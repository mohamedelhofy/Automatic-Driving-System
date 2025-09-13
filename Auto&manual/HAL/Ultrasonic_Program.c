/*
 * Ultrasonic_Program.c
 *
 *  Created on: Sep 3, 2025
 *      Author: alhof
 */


#include "../Library/STD_TYPES.h"
#include "../Library/BIT_MATH.h"
#include "../MCAL/DIO_Interface.h"
#include "../MCAL/Timer1_Interface.h"
#include "../MCAL/GIE_Interface.h"
#include "Ultrasonic_Config.h"
#include "Ultrasonic_Interface.h"
#include <util/delay.h>
#include <avr/interrupt.h>

static volatile u16 TimerOverflow = 0;

ISR(TIMER1_OVF_vect)
{
    TimerOverflow++;
}

void Ultrasonic_Init(void)
{
    /* Trigger pin output */
    DIO_voidSetPinDirection(ULTRASONIC_TRIGGER_PORT, ULTRASONIC_TRIGGER_PIN, DIO_u8_OUTPUT);

    /* Echo pin input (ICP1 = PD6) */
    DIO_voidSetPinDirection(ULTRASONIC_ECHO_PORT, ULTRASONIC_ECHO_PIN, DIO_u8_INPUT);

    /* Enable global interrupts */
    Global_Interrupt_Enable();

    /* Timer1 Normal mode + overflow interrupt */
    Timer1_voidInit_Normal();
}

f32 Ultrasonic_GetDistance(void)
{
    u32 count;
    f32 distance;

    // Send 10us pulse
    DIO_voidSetPinValue(ULTRASONIC_TRIGGER_PORT, ULTRASONIC_TRIGGER_PIN, DIO_u8_HIGH);
    _delay_us(10);
    DIO_voidSetPinValue(ULTRASONIC_TRIGGER_PORT, ULTRASONIC_TRIGGER_PIN, DIO_u8_LOW);

    // Rising edge, prescaler=8
    TCCR1B = (1 << ICES1) | (1 << CS11);
    TIFR = (1 << ICF1) | (1 << TOV1);
    while ((TIFR & (1 << ICF1)) == 0);

    Timer1_voidSetTCNT(0);
    TCCR1B = (0 << ICES1) | (1 << CS11); // falling edge, prescaler=8
    TIFR = (1 << ICF1) | (1 << TOV1);
    TimerOverflow = 0;

    while ((TIFR & (1 << ICF1)) == 0);

    count = ICR1 + (65535UL * TimerOverflow);

    /*
     * Distance calc:
     * Tick = 0.5us (for prescaler=8 at 16MHz)
     * Echo round-trip: distance(cm) = (time_us / 58)
     * => distance = (count * 0.5) / 58 = count / 116
     */
    distance = (f32)count / 116.0f;

    return distance;
}
