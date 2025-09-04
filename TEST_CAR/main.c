/*
 * main.c
 *
 *  Created on: Sep 3, 2025
 *      Author: shaima
 */

#include "Library/STD_TYPES.h"
#include "Library/BIT_MATH.h"
#include "MCAL/DIO_Interface.h"
#include "HAL/ULTRASONIC_Interface.h"
#include "HAL/SERVO_Interface.h"
#include "HAL/L298_Interface.h"
#include "MCAL/Timer1_Interface.h"
#include <util/delay.h>
#include <avr/interrupt.h>

int main(void)
{
    u16 distance, leftDist, rightDist;

    L298_voidInit();
    SERVO_voidInit();
    Ultrasonic_Init();

    while(1)
    {
        distance = Ultrasonic_GetDistance();

        if(distance > 100)
        {
            L298_voidMove(MOVE_FORWARD, 70);
        }
        else
        {
            // وقف
            L298_voidMove(MOVE_STOP, 0);

            // بص يمين
            SERVO_voidSetAngle(0);
            _delay_ms(500);
            rightDist = Ultrasonic_GetDistance();

            // بص شمال
            SERVO_voidSetAngle(180);
            _delay_ms(500);
            leftDist = Ultrasonic_GetDistance();

            // رجّع للمنتصف
            SERVO_voidSetAngle(90);

            if(rightDist > leftDist && rightDist > 100)
            {
                L298_voidMove(MOVE_RIGHT, 70);
            }
            else if(leftDist >= rightDist && leftDist > 100)
            {
                L298_voidMove(MOVE_LEFT, 70);
            }
            else
            {
                L298_voidMove(MOVE_BACKWARD, 60);
                _delay_ms(500);
                L298_voidMove(MOVE_STOP, 0);
            }
        }
    }
}
