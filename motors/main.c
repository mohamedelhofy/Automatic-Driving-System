/*
 * main.c
 * Author: shaima
 */

#include "Library/STD_TYPES.h"
#include "Library/BIT_MATH.h"
#include "MCAL/DIO_Interface.h"
#include "MCAL/Timer1_Interface.h"
#include "MCAL/Timer0_Interface.h"
#include "MCAL/EXT_IN_Interface.h"
#include "HAL/ULTRASONIC_Interface.h"
#include "HAL/Servo_Interface.h"
#include "HAL/L298_Interface.h"

#include <util/delay.h>
#include <avr/interrupt.h>
volatile u8 mode = 1; // 1 = Auto mode, 0 = Manual mode

ISR(INT1_vect)
{
    mode ^= 1;   // Toggle between Auto and Manual
}
int main(void)
{
    u16 distance, leftDist, rightDist;

    // Initialization
    L298_voidInit();
    SERVO_voidInit();
    Ultrasonic_Init();
    EXT1_IN_Enable();  // Enable interrupt on PD3


    while(1)
    {


        if(mode == 1) // ---- AUTO MODE ----
        {
            distance = Ultrasonic_GetDistance();

            if(distance > 100)
            {
                // Path is clear → move forward
                L298_voidMove(MOVE_FORWARD, 70);
            }
            else
            {
                // Stop before decision
                L298_voidMove(MOVE_STOP, 0);

                // Look right
                SERVO_voidSetAngle(90);
                _delay_ms(600);
                rightDist = Ultrasonic_GetDistance();

                // Look left
                SERVO_voidSetAngle(270);
                _delay_ms(600);
                leftDist = Ultrasonic_GetDistance();

                // Return servo to center
                SERVO_voidSetAngle(0);

                if(rightDist > leftDist && rightDist > 100)
                {
                    // Rotate robot slightly right
                    L298_voidMove(MOVE_RIGHT, 70);
                    _delay_ms(400);
                    L298_voidMove(MOVE_STOP, 0);

                    // Then move forward
                    L298_voidMove(MOVE_FORWARD, 70);
                }
                else if(leftDist >= rightDist && leftDist > 100)
                {
                    // Rotate robot slightly left
                    L298_voidMove(MOVE_LEFT, 70);
                    _delay_ms(400);
                    L298_voidMove(MOVE_STOP, 0);

                    // Then move forward
                    L298_voidMove(MOVE_FORWARD, 70);
                }
                else
                {
                    // No way out → move backward a little
                    L298_voidMove(MOVE_BACKWARD, 60);
                    _delay_ms(500);
                    L298_voidMove(MOVE_STOP, 0);
                }
            }
        }
        else // ---- MANUAL MODE ----
        {

        }
    }
}
