/*
 * Servo_Prog.c
 * Author: shaima
 */

#include "../Library/STD_TYPES.h"
#include "../Library/BIT_MATH.h"
#include <avr/io.h>
#include "Servo_Config.h"
#include "Servo_Interface.h"

void SERVO_voidInit(void)
{
    // OC1A = PD5 كـ output
    SERVO_DDR |= (1 << SERVO_PIN);

    // Timer1 Fast PWM Mode 14 (ICR1 = TOP), Prescaler = 8
    TCCR1A = (1 << COM1A1) | (1 << WGM11);
    TCCR1B = (1 << WGM13) | (1 << WGM12) | (1 << CS11);

    // Set TOP value = 20ms
    ICR1 = SERVO_TOP;
}

void SERVO_voidSetAngle(u16 Copy_u16Angle)
{
    // تحويل الزاوية (0–180) ل pulse width (1000–2000 µs)
    u16 pulse = SERVO_MIN_PULSE + ((u32)Copy_u16Angle * (SERVO_MAX_PULSE - SERVO_MIN_PULSE)) / 180;

    if (pulse < SERVO_MIN_PULSE) pulse = SERVO_MIN_PULSE;
    if (pulse > SERVO_MAX_PULSE) pulse = SERVO_MAX_PULSE;

    OCR1A = pulse;  // خرج على OC1A
}
