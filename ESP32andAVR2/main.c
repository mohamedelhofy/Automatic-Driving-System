/*
 * main.c
 *
 *  Created on: Sep 10, 2025
 *      Author: Marina Boutros
 */



#include "Library/STD_TYPES.h"
#include "Library/BIT_MATH.h"
//
#include "MCAL/DIO_Interface.h"
#include "MCAL/DIO_Register.h"
#include "MCAL/TIMER1/Timer1_Interface.h"
#include "MCAL/TIMER0/Timer0_Interface.h"
#include "MCAL/EXT_IN/EXT_IN_Interface.h"
#include "HAL/ULTRASONIC/Ultrasonic_Interface.h"
#include "HAL/Servo/Servo_Interface.h"
#include "HAL/L298/L298_Interface.h"
//
#include "MCAL/UART/UART_Interface.h"
#include "MCAL/UART/UART_Register.h"
#include <avr/interrupt.h>
#include <avr/io.h>
#include <util/delay.h>

volatile u8 mode = 1; // 1 = Auto mode, 0 = Manual mode

ISR(INT1_vect)
{
    mode ^= 1;   // Toggle between Auto and Manual
}


//
//// ================== UART FUNCTIONS ==================
//
//// Initialize UART (9600 baud @ 8MHz)
//void UART_Init(void)
//{
//    // Baud rate = 9600 -> UBRR = (F_CPU / (16 * Baud)) - 1 = 51
//    UBRRH = 0;
//    UBRRL = 51;
//
//    // Enable receiver and transmitter
//    UCSRB = (1 << RXEN) | (1 << TXEN);
//
//    // Frame format: 8 data bits, 1 stop bit, no parity
//    UCSRC = (1 << URSEL) | (1 << UCSZ1) | (1 << UCSZ0);
//}
//
//// Receive one byte
//unsigned char UART_Receive_Byte(void)
//{
//    while (!(UCSRA & (1 << RXC)));   // Wait for data
//    return UDR;                      // Return received byte
//}
//
//// Send one byte
//void UART_Send_Byte(unsigned char data)
//{
//    while (!(UCSRA & (1 << UDRE)));  // Wait until buffer is empty
//    UDR = data;                      // Send data
//}
//
//// ================== MAIN ==================
//
int main(void)
{
    UART_Init();

    // Configure PA0 & PA1 as outputs
    DDRA |= (1 << PA0) | (1 << PA1);

    u16 distance, leftDist, rightDist;

    // Initialization
    L298_voidInit();
    SERVO_voidInit();
    Ultrasonic_Init();
    EXT1_IN_Enable();  // Enable interrupt on PD3


    while (1)
    {
        unsigned char read = UART_Receive_Byte();

        if (read == 'F')   // Forward
        {
            PORTA |=  (1 << PA1);   // PA1 HIGH
            PORTA &= ~(1 << PA0);   // PA0 LOW
            PORTA &= ~(1 << PA2);   // PA2 LOW
            PORTA &= ~(1 << PA3);   // PA3 LOW
            PORTA &= ~(1 << PA4);   // PA4 LOW
            L298_voidMove(MOVE_FORWARD, 70);
            UART_Send_Byte('F');    // Send ACK

        }
        else if (read == 'B')  // Backward
        {
            PORTA |=  (1 << PA2);   // PA2 HIGH
            PORTA &= ~(1 << PA0);   // PA0 LOW
            PORTA &= ~(1 << PA1);   // PA1 LOW
            PORTA &= ~(1 << PA3);   // PA3 LOW
            PORTA &= ~(1 << PA4);   // PA4 LOW
            L298_voidMove(MOVE_BACKWARD, 70);
            UART_Send_Byte('B');    // Send ACK

        }
        else if (read == 'R')  // Right
                {
            PORTA |=  (1 << PA3);   // PA3 HIGH
            PORTA &= ~(1 << PA0);   // PA0 LOW
            PORTA &= ~(1 << PA1);   // PA1 LOW
            PORTA &= ~(1 << PA2);   // PA2 LOW
            PORTA &= ~(1 << PA4);   // PA4 LOW
            L298_voidMove(MOVE_RIGHT, 70);
			UART_Send_Byte('R');    // Send ACK

        }
        else if (read == 'L')  // Left
                {
            PORTA |=  (1 << PA4);   // PA4 HIGH
            PORTA &= ~(1 << PA0);   // PA0 LOW
            PORTA &= ~(1 << PA1);   // PA1 LOW
            PORTA &= ~(1 << PA2);   // PA2 LOW
            PORTA &= ~(1 << PA3);   // PA3 LOW
            L298_voidMove(MOVE_LEFT, 70);
			UART_Send_Byte('L');    // Send ACK

          }
        else   // Stop
        {
            PORTA |=  (1 << PA0);   // PA0 HIGH
            PORTA &= ~(1 << PA1);   // PA1 LOW
            PORTA &= ~(1 << PA2);   // PA2 LOW
            PORTA &= ~(1 << PA3);   // PA3 LOW
            PORTA &= ~(1 << PA4);   // PA4 LOW
            L298_voidMove(MOVE_STOP, 0);
            UART_Send_Byte('S');    // Send Stop ACK

        }
    }
}

