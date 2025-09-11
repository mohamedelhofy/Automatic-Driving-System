/*
 * Stepper_Motor.c
 *
 *  Created on: Sep 1, 2025
 *      Author: Marina Boutros
 */



#include "../../LIBRARY/BIT_MATH.h"
#include "../../LIBRARY/STD_TYPES.h"
#include "../../MCAL/DIO_Interface.h"
#include "../../MCAL/DIO_Register.h"
#include <util/delay.h>

#include "Stepper_interface.h"
#include "Stepper_config.h"


void STEPPER_voidInit(void)
{

	DIO_voidSetPinDirection( STEPPER_u8_COIL_PORT,  STEPPER_u8_CIOL_Blue,    DIO_u8_OUTPUT);
	DIO_voidSetPinDirection( STEPPER_u8_COIL_PORT,  STEPPER_u8_CIOL_Pink,    DIO_u8_OUTPUT);
	DIO_voidSetPinDirection( STEPPER_u8_COIL_PORT,  STEPPER_u8_CIOL_Yellow,	 DIO_u8_OUTPUT);
	DIO_voidSetPinDirection( STEPPER_u8_COIL_PORT,  STEPPER_u8_CIOL_Orange,  DIO_u8_OUTPUT);

}



void STEPPER_voidRotateACW(void)
{

	DIO_voidSetPinValue( STEPPER_u8_COIL_PORT, STEPPER_u8_CIOL_Blue,    DIO_u8_HIGH);
	DIO_voidSetPinValue( STEPPER_u8_COIL_PORT, STEPPER_u8_CIOL_Pink,    DIO_u8_LOW);
	DIO_voidSetPinValue( STEPPER_u8_COIL_PORT, STEPPER_u8_CIOL_Yellow,  DIO_u8_LOW);
	DIO_voidSetPinValue( STEPPER_u8_COIL_PORT, STEPPER_u8_CIOL_Orange,  DIO_u8_LOW);
	_delay_ms(5);

	DIO_voidSetPinValue( STEPPER_u8_COIL_PORT, STEPPER_u8_CIOL_Blue,    DIO_u8_LOW);
	DIO_voidSetPinValue( STEPPER_u8_COIL_PORT, STEPPER_u8_CIOL_Pink,    DIO_u8_HIGH);
	DIO_voidSetPinValue( STEPPER_u8_COIL_PORT, STEPPER_u8_CIOL_Yellow,  DIO_u8_LOW);
	DIO_voidSetPinValue( STEPPER_u8_COIL_PORT, STEPPER_u8_CIOL_Orange,  DIO_u8_LOW);
	_delay_ms(5);

	DIO_voidSetPinValue( STEPPER_u8_COIL_PORT, STEPPER_u8_CIOL_Blue,    DIO_u8_LOW);
	DIO_voidSetPinValue( STEPPER_u8_COIL_PORT, STEPPER_u8_CIOL_Pink,    DIO_u8_LOW);
	DIO_voidSetPinValue( STEPPER_u8_COIL_PORT, STEPPER_u8_CIOL_Yellow,  DIO_u8_HIGH);
	DIO_voidSetPinValue( STEPPER_u8_COIL_PORT, STEPPER_u8_CIOL_Orange,  DIO_u8_LOW);
	_delay_ms(5);


	DIO_voidSetPinValue( STEPPER_u8_COIL_PORT, STEPPER_u8_CIOL_Blue,    DIO_u8_LOW);
	DIO_voidSetPinValue( STEPPER_u8_COIL_PORT, STEPPER_u8_CIOL_Pink,    DIO_u8_LOW);
	DIO_voidSetPinValue( STEPPER_u8_COIL_PORT, STEPPER_u8_CIOL_Yellow,  DIO_u8_LOW);
	DIO_voidSetPinValue( STEPPER_u8_COIL_PORT, STEPPER_u8_CIOL_Orange,  DIO_u8_HIGH);
	_delay_ms(5);

}



void STEPPER_voidRotateCW(void)
{

	DIO_voidSetPinValue( STEPPER_u8_COIL_PORT, STEPPER_u8_CIOL_Orange,    DIO_u8_HIGH);
	DIO_voidSetPinValue( STEPPER_u8_COIL_PORT, STEPPER_u8_CIOL_Yellow,    DIO_u8_LOW);
	DIO_voidSetPinValue( STEPPER_u8_COIL_PORT, STEPPER_u8_CIOL_Pink,      DIO_u8_LOW);
	DIO_voidSetPinValue( STEPPER_u8_COIL_PORT, STEPPER_u8_CIOL_Blue,      DIO_u8_LOW);
	_delay_ms(5);

	DIO_voidSetPinValue( STEPPER_u8_COIL_PORT, STEPPER_u8_CIOL_Orange,    DIO_u8_LOW);
	DIO_voidSetPinValue( STEPPER_u8_COIL_PORT, STEPPER_u8_CIOL_Yellow,    DIO_u8_HIGH);
	DIO_voidSetPinValue( STEPPER_u8_COIL_PORT, STEPPER_u8_CIOL_Pink,      DIO_u8_LOW);
	DIO_voidSetPinValue( STEPPER_u8_COIL_PORT, STEPPER_u8_CIOL_Blue,      DIO_u8_LOW);
	_delay_ms(5);

	DIO_voidSetPinValue( STEPPER_u8_COIL_PORT, STEPPER_u8_CIOL_Orange,    DIO_u8_LOW);
	DIO_voidSetPinValue( STEPPER_u8_COIL_PORT, STEPPER_u8_CIOL_Yellow,    DIO_u8_LOW);
	DIO_voidSetPinValue( STEPPER_u8_COIL_PORT, STEPPER_u8_CIOL_Pink,      DIO_u8_HIGH);
	DIO_voidSetPinValue( STEPPER_u8_COIL_PORT, STEPPER_u8_CIOL_Blue,      DIO_u8_LOW);
	_delay_ms(5);

	DIO_voidSetPinValue( STEPPER_u8_COIL_PORT, STEPPER_u8_CIOL_Orange,    DIO_u8_LOW);
	DIO_voidSetPinValue( STEPPER_u8_COIL_PORT, STEPPER_u8_CIOL_Yellow,    DIO_u8_LOW);
	DIO_voidSetPinValue( STEPPER_u8_COIL_PORT, STEPPER_u8_CIOL_Pink,      DIO_u8_LOW);
	DIO_voidSetPinValue( STEPPER_u8_COIL_PORT, STEPPER_u8_CIOL_Blue,      DIO_u8_HIGH);
	_delay_ms(5);



}
