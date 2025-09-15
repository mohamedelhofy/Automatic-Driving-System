/*
 * Ultrasonic_Program.c (INT0 + Timer0)
 *
 * Author: shaima
 */

#include "../Library/STD_TYPES.h"
#include "../Library/BIT_MATH.h"
#include "../MCAL/DIO_Interface.h"
#include "../MCAL/GIE_Interface.h"
#include "Ultrasonic_Config.h"
#include "Ultrasonic_Interface.h"

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

static volatile u32 Timer0Overflow = 0;
static volatile u16 start_time = 0;
static volatile u16 end_time = 0;
static volatile u8 capture_done = 0;

/* ---------------- ISR ---------------- */
ISR(TIMER0_OVF_vect)
{
    Timer0Overflow++;
}

/* INT0 ISR for Echo pin */
ISR(INT0_vect)
{
    if (DIO_u8GetPinValue(ULTRASONIC_ECHO_PORT, ULTRASONIC_ECHO_PIN))
    {
        // Rising edge → start timing
        TCNT0 = 0;
        Timer0Overflow = 0;
        start_time = 0;
    }
    else
    {
        // Falling edge → stop timing
        end_time = (u16)TCNT0 + (Timer0Overflow * 256UL);
        capture_done = 1;
    }
}

/* ---------------- Init ---------------- */
void Ultrasonic_Init(void)
{
    /* Trigger pin output */
    DIO_voidSetPinDirection(ULTRASONIC_TRIGGER_PORT, ULTRASONIC_TRIGGER_PIN, DIO_u8_OUTPUT);

    /* Echo pin as input */
    DIO_voidSetPinDirection(ULTRASONIC_ECHO_PORT, ULTRASONIC_ECHO_PIN, DIO_u8_INPUT);

    /* Timer0 Normal mode, prescaler = 64 (tick = 4us) */
    TCCR0 = (1 << CS01) | (1 << CS00); // clk/64
    TIMSK |= (1 << TOIE0);             // enable overflow interrupt

    /* Enable INT0 on any logical change */
    MCUCR |= (1 << ISC00);
    MCUCR &= ~(1 << ISC01);

    GICR |= (1 << INT0);

    /* Enable global interrupts */
    Global_Interrupt_Enable();
}

/* ---------------- Get Distance ---------------- */
f32 Ultrasonic_GetDistance(void)
{
    f32 distance = 0;

    // Send 10us pulse
    DIO_voidSetPinValue(ULTRASONIC_TRIGGER_PORT, ULTRASONIC_TRIGGER_PIN, DIO_u8_HIGH);
    _delay_us(10);
    DIO_voidSetPinValue(ULTRASONIC_TRIGGER_PORT, ULTRASONIC_TRIGGER_PIN, DIO_u8_LOW);

    capture_done = 0;

    // انتظر لحد ما يحصل قياس
    while (!capture_done);

    // كل tick = 4us → time_us = end_time * 4
    // distance_cm = time_us / 58
    distance = ((f32)end_time * 4.0f) / 58.0f;

    return distance;
}
