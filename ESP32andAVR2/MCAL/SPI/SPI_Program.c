/*
 * SPI_Program.c
 *
 *  Created on: Sep 9, 2025
 *      Author: Marina Boutros
 */

#include "../../LIBRARY/STD_TYPES.h"
#include "../../LIBRARY/BIT_MATH.h"

#include "../DIO_Interface.h"
#include "../DIO_Register.h"


#include "SPI_Interface.h"
#include "SPI_Register.h"


void SPI_Master_Init_(void)
{

	DIO_voidSetPinDirection(DIO_u8_PORTB,DIO_u8_PIN5,DIO_u8_OUTPUT);		//MOSI
	DIO_voidSetPinDirection(DIO_u8_PORTB,DIO_u8_PIN7,DIO_u8_OUTPUT);		//CLCK
	DIO_voidSetPinDirection(DIO_u8_PORTB,DIO_u8_PIN4,DIO_u8_OUTPUT);		//SS
	DIO_voidSetPinDirection(DIO_u8_PORTB,DIO_u8_PIN6,DIO_u8_INPUT);			//MISO

	SPCR = (1 << SPE) | (1 << MSTR) | (1 << SPR0); //SPR0=> FLAG /

}




void SPI_Master_Init_Interrupt(void)
{



}




void SPI_Slave_Init_(void)
{

}



void SPI_Slave_Init_Interrupt(void)
{

}





u8 SPI_Send_Receive_Data(u8 data)
{
	SPDR = data ;

	while (GET_BIT(SPSR,SPIF)==0);
	SET_BIT(SPSR,SPIF);
	return SPDR;

}
