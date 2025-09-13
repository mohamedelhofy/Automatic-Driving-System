/*
 * main.c
 * Author: shaima
 */

#include "Library/STD_TYPES.h"
#include "Library/BIT_MATH.h"
#include "MCAL/DIO_Interface.h"
#include "MCAL/Timer1_Interface.h"
#include "MCAL/Timer0_Interface.h"
#include "MCAL/UART/UART_Interface.h"
#include "HAL/Ultrasonic_Interface.h"
#include "HAL/SERVO_Interface.h"
#include "HAL/L298_Interface.h"

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

// --------- GLOBAL VARIABLES ---------
volatile u8 mode = 1; // 1 = Auto (default), 0 = Manual

// --------- FUNCTIONS ---------
void Auto_Mode(void)
{
    u16 distance, leftDist, rightDist;

    distance = Ultrasonic_GetDistance();

    if (distance > 20 && distance < 200)
    {
        L298_voidMove(MOVE_FORWARD);
    }
    else
    {
        L298_voidMove(MOVE_STOP);

        // يمين
        SERVO_voidSetAngle(0);
        _delay_ms(800);
        rightDist = Ultrasonic_GetDistance();

        // شمال
        SERVO_voidSetAngle(180);
        _delay_ms(800);
        leftDist = Ultrasonic_GetDistance();

        // رجع للمنتصف
        SERVO_voidSetAngle(90);

        if (rightDist > leftDist && rightDist > 30)
        {
            L298_voidMove(MOVE_RIGHT);
            _delay_ms(400);
        }
        else if (leftDist >= rightDist && leftDist > 30)
        {
            L298_voidMove(MOVE_LEFT);
            _delay_ms(400);
        }
        else
        {
            L298_voidMove(MOVE_BACKWARD);
            _delay_ms(500);
        }

        L298_voidMove(MOVE_STOP);
    }
}

// --------- ISR for UART RX ---------
//ISR(USART_RXC_vect)
//{
//	PORTA ^= (1 << PA7);
//    unsigned char read = UDR;
//
//    switch (read)
//    {
//        case 'A': mode = 1; break;  // Auto Mode
//        case 'M': mode = 0; break;  // Manual Mode
//
//        // Manual control commands
//        case 'F': if (mode == 0) L298_voidMove(MOVE_FORWARD);  break;
//        case 'B': if (mode == 0) L298_voidMove(MOVE_BACKWARD); break;
//        case 'R': if (mode == 0) L298_voidMove(MOVE_RIGHT);    break;
//        case 'L': if (mode == 0) L298_voidMove(MOVE_LEFT);     break;
//        case 'S': if (mode == 0) L298_voidMove(MOVE_STOP);     break;
//    }
//}

// --------- MAIN ---------
int main(void)
{
    // Init
    L298_voidInit();
    SERVO_voidInit();
    Ultrasonic_Init();
   // UART_Init();

    // Enable global interrupt
  //  sei();

    while (1)
    {
        if (mode == 1) // Auto Mode
        {
            Auto_Mode();
        }
        // Manual Mode مفيش Loop هنا، الأوامر بتتنفذ من الـ ISR مباشرة
    }
}
