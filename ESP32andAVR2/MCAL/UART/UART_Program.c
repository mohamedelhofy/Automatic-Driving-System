/*
 * UART_Program.c
 *
 *  Created on: Sep 7, 2025
 *      Author: Marina Boutros
 */

#include "../../LIBRARY/STD_TYPES.h"
#include "../../LIBRARY/BIT_MATH.h"

#include "UART_Interface.h"
#include "UART_Register.h"

#include "../DIO_Interface.h"
#include "../DIO_Register.h"

u8 UART_Receive_Flag=0;

u8 UART_Frame[50]={0};



void UART_Init(void)
{
//	CLR_BIT(UBRRH,URSEL);

	UBRRH =0;
	UBRRL=51;

	DIO_voidSetPinDirection(DIO_u8_PORTD,DIO_u8_PIN0,DIO_u8_INPUT);  //RX INPUT
	DIO_voidSetPinDirection(DIO_u8_PORTD,DIO_u8_PIN1,DIO_u8_OUTPUT); //TX INPUT

	UCSRC = (1<<URSEL) | (1<<UCSZ1) | (1<<UCSZ0);

//	SET_BIT(UCSRC,URSEL);
//	CLR_BIT(UCSRC,UMSEL);
//	CLR_BIT(UCSRC,UPM0);
//	CLR_BIT(UCSRC,UPM1);
//	CLR_BIT(UCSRC,USBS);
//	SET_BIT(UCSRC,UCSZ0);
//	SET_BIT(UCSRC,UCSZ1);

	UCSRB = (1<<RXEN) | (1<<TXEN);


}


unsigned char UART_Receive_Byte(void)
{
	while (!(UCSRA & (1<<RXC)));

	return UDR;
}

void UART_Init_Interrupt(void)
{
	UART_Init();

	UCSRB |= (1<<RXCIE)|(1<<TXCIE);

	__asm__ __volatile__ ("sei" ::);
}


void UART_Send_Byte(u8 data)
{
	while (GET_BIT(UCSRA,UDRE)==0);
	UCSRA |= (1<<UDRE);

	UDR=data;
	while (GET_BIT(UCSRA,TXC)==0)
	{
		UCSRA |= (1<<TXC);
	}
}





