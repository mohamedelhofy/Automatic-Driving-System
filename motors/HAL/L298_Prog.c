/*
 * L298_Prog.c
 *
 *  Created on: Sep 3, 2025
 *      Author: shaima
 */
#include "../Library/BIT_MATH.h"
#include "../Library/STD_TYPES.h"
#include "../MCAL/DIO_Register.h"
#include "../MCAL/DIO_Interface.h"
#include "../MCAL/Timer1_Interface.h"
#include "../MCAL/Timer1_Register.h"
#include "../MCAL/Timer0_Interface.h"
#include "../MCAL/Timer0_Register.h"
#include "L298_Interface.h"
#include "L298_Config.h"


void L298_voidInit(void)
{
    // Outputs
    DIO_voidSetPinDirection(DIO_u8_PORTB, IN1, DIO_u8_OUTPUT);
    DIO_voidSetPinDirection(DIO_u8_PORTB, IN2, DIO_u8_OUTPUT);
    DIO_voidSetPinDirection(DIO_u8_PORTB, IN3, DIO_u8_OUTPUT);
    DIO_voidSetPinDirection(DIO_u8_PORTB, IN4, DIO_u8_OUTPUT);

    DIO_voidSetPinDirection(DIO_u8_PORTB, ENA, DIO_u8_OUTPUT);
    DIO_voidSetPinDirection(DIO_u8_PORTB, ENB, DIO_u8_OUTPUT);
    Timer0_voidInit_FastPWM();                          // ENA → Motor A
	Timer1_voidInitPWM(19999, TIMER1_PRESCALER_8);      // ENB → Motor B

}

void L298_voidMove(u8 Copy_u8Direction, u8 Copy_u8SpeedPercent)
{
	u16 duty_motorA = (Copy_u8SpeedPercent * 255) / 100;      // Timer0
	u16 duty_motorB = (Copy_u8SpeedPercent * 19999) / 100;    // Timer1
    switch(Copy_u8Direction)
    {
        case MOVE_FORWARD:
            DIO_voidSetPinValue(DIO_u8_PORTB, IN1, DIO_u8_HIGH);
            DIO_voidSetPinValue(DIO_u8_PORTB, IN2, DIO_u8_LOW);
            DIO_voidSetPinValue(DIO_u8_PORTB, IN3, DIO_u8_HIGH);
            DIO_voidSetPinValue(DIO_u8_PORTB, IN4, DIO_u8_LOW);

            break;

        case MOVE_BACKWARD:
            DIO_voidSetPinValue(DIO_u8_PORTB, IN1, DIO_u8_LOW);
            DIO_voidSetPinValue(DIO_u8_PORTB, IN2, DIO_u8_HIGH);
            DIO_voidSetPinValue(DIO_u8_PORTB, IN3, DIO_u8_LOW);
            DIO_voidSetPinValue(DIO_u8_PORTB, IN4, DIO_u8_HIGH);
             break;

        case MOVE_RIGHT:
            DIO_voidSetPinValue(DIO_u8_PORTB, IN1, DIO_u8_HIGH);
            DIO_voidSetPinValue(DIO_u8_PORTB, IN2, DIO_u8_LOW);
            DIO_voidSetPinValue(DIO_u8_PORTB, IN3, DIO_u8_LOW);
            DIO_voidSetPinValue(DIO_u8_PORTB, IN4, DIO_u8_LOW);
               break;

        case MOVE_LEFT:
            DIO_voidSetPinValue(DIO_u8_PORTB, IN1, DIO_u8_LOW);
            DIO_voidSetPinValue(DIO_u8_PORTB, IN2, DIO_u8_LOW);
            DIO_voidSetPinValue(DIO_u8_PORTB, IN3, DIO_u8_HIGH);
            DIO_voidSetPinValue(DIO_u8_PORTB, IN4, DIO_u8_LOW);
              break;

        case MOVE_STOP:
            DIO_voidSetPinValue(DIO_u8_PORTB, IN1, DIO_u8_LOW);
            DIO_voidSetPinValue(DIO_u8_PORTB, IN2, DIO_u8_LOW);
            DIO_voidSetPinValue(DIO_u8_PORTB, IN3, DIO_u8_LOW);
            DIO_voidSetPinValue(DIO_u8_PORTB, IN4, DIO_u8_LOW);
              break;
    }
    // Apply PWM speed
        Timer0_voidSetDuty(duty_motorA);    // Motor A
        Timer1_voidSetDuty(TIMER1_CHANNEL_A, duty_motorB); // Motor B

}



