/*
 * SERVO_Prog.c
 *
 *  Created on: Sep 4, 2025
 *      Author: shaima
 */


#include "../Library/STD_TYPES.h"
#include "../Library/BIT_MATH.h"
#include "../MCAL/DIO_Interface.h"
#include "../MCAL/Timer1_Interface.h"
#include "../MCAL/Timer1_Register.h"
#include "Servo_Interface.h"
#include "Servo_Config.h"

void SERVO_voidInit(void)
{
	DIO_voidSetPinDirection(DIO_u8_PORTD, DIO_u8_PIN4, DIO_u8_OUTPUT);

	Timer1_voidInitPWM(SERVO_TOP, TIMER1_PRESCALER_8);


}

void SERVO_voidSetAngle(u8 Copy_u8Angle)
{
    // Pulse بين 1000µs ل 2000µs → من 0° لـ 180°
    u16 duty = (1000 + ((u32)Copy_u8Angle * 1000) / 180);
    Timer1_voidSetDuty(SERVO_CHANNEL, duty);
}


