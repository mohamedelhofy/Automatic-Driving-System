/*

 * Stepper_program.c
 *
 *  Created on: Sep 1, 2025
 *      Author: mosst
 */

#include "../Library/BIT_Math.h"
#include "../Library/STD_TYPES.h"
#include "../MCAL/DIO_Interface.h"
#include "Stepper_interface.h"
#include "Stepper_config.h"
#include "util/delay.h"

void STEPPER_voidInit(void){
	DIO_voidSetPinDirection(STEPPER_u8_COIL_PORT, STEPPER_u8_COIL_BLUE,DIO_u8_OUTPUT);
	DIO_voidSetPinDirection(STEPPER_u8_COIL_PORT,STEPPER_u8_COIL_Pink,DIO_u8_OUTPUT);
	DIO_voidSetPinDirection(STEPPER_u8_COIL_PORT,STEPPER_u8_COIL_Yellow,DIO_u8_OUTPUT);
	DIO_voidSetPinDirection(STEPPER_u8_COIL_PORT,STEPPER_u8_COIL_Orange,DIO_u8_OUTPUT);
}
void STEPPER_voidRotateCW(void){
	DIO_voidSetPinValue(STEPPER_u8_COIL_PORT, STEPPER_u8_COIL_BLUE,DIO_u8_HIGH);
	DIO_voidSetPinValue(STEPPER_u8_COIL_PORT,STEPPER_u8_COIL_Pink,DIO_u8_LOW);
	DIO_voidSetPinValue(STEPPER_u8_COIL_PORT,STEPPER_u8_COIL_Yellow,DIO_u8_LOW);
	DIO_voidSetPinValue(STEPPER_u8_COIL_PORT,STEPPER_u8_COIL_Orange,DIO_u8_LOW);
	_delay_ms(5);
	DIO_voidSetPinValue(STEPPER_u8_COIL_PORT, STEPPER_u8_COIL_BLUE,DIO_u8_LOW);
	DIO_voidSetPinValue(STEPPER_u8_COIL_PORT,STEPPER_u8_COIL_Pink,DIO_u8_HIGH);
	DIO_voidSetPinValue(STEPPER_u8_COIL_PORT,STEPPER_u8_COIL_Yellow,DIO_u8_LOW);
	DIO_voidSetPinValue(STEPPER_u8_COIL_PORT,STEPPER_u8_COIL_Orange,DIO_u8_LOW);
	_delay_ms(5);
	DIO_voidSetPinValue(STEPPER_u8_COIL_PORT, STEPPER_u8_COIL_BLUE,DIO_u8_LOW);
	DIO_voidSetPinValue(STEPPER_u8_COIL_PORT,STEPPER_u8_COIL_Pink,DIO_u8_LOW);
	DIO_voidSetPinValue(STEPPER_u8_COIL_PORT,STEPPER_u8_COIL_Yellow,DIO_u8_HIGH);
	DIO_voidSetPinValue(STEPPER_u8_COIL_PORT,STEPPER_u8_COIL_Orange,DIO_u8_LOW);
	_delay_ms(5);
	DIO_voidSetPinValue(STEPPER_u8_COIL_PORT, STEPPER_u8_COIL_BLUE,DIO_u8_LOW);
	DIO_voidSetPinValue(STEPPER_u8_COIL_PORT,STEPPER_u8_COIL_Pink,DIO_u8_LOW);
	DIO_voidSetPinValue(STEPPER_u8_COIL_PORT,STEPPER_u8_COIL_Yellow,DIO_u8_LOW);
	DIO_voidSetPinValue(STEPPER_u8_COIL_PORT,STEPPER_u8_COIL_Orange,DIO_u8_HIGH);
	_delay_ms(5);
}
void STEPPER_voidRotateACW(void){
	DIO_voidSetPinValue(STEPPER_u8_COIL_PORT,STEPPER_u8_COIL_Orange,DIO_u8_HIGH);
	DIO_voidSetPinValue(STEPPER_u8_COIL_PORT,STEPPER_u8_COIL_Yellow,DIO_u8_LOW);
	DIO_voidSetPinValue(STEPPER_u8_COIL_PORT,STEPPER_u8_COIL_Pink,DIO_u8_LOW);
	DIO_voidSetPinValue(STEPPER_u8_COIL_PORT, STEPPER_u8_COIL_BLUE,DIO_u8_LOW);
	_delay_ms(5);
	DIO_voidSetPinValue(STEPPER_u8_COIL_PORT,STEPPER_u8_COIL_Orange,DIO_u8_LOW);
	DIO_voidSetPinValue(STEPPER_u8_COIL_PORT,STEPPER_u8_COIL_Yellow,DIO_u8_HIGH);
	DIO_voidSetPinValue(STEPPER_u8_COIL_PORT,STEPPER_u8_COIL_Pink,DIO_u8_LOW);
	DIO_voidSetPinValue(STEPPER_u8_COIL_PORT, STEPPER_u8_COIL_BLUE,DIO_u8_LOW);
	_delay_ms(5);
	DIO_voidSetPinValue(STEPPER_u8_COIL_PORT,STEPPER_u8_COIL_Orange,DIO_u8_LOW);
	DIO_voidSetPinValue(STEPPER_u8_COIL_PORT,STEPPER_u8_COIL_Yellow,DIO_u8_LOW);
	DIO_voidSetPinValue(STEPPER_u8_COIL_PORT,STEPPER_u8_COIL_Pink,DIO_u8_HIGH);
	DIO_voidSetPinValue(STEPPER_u8_COIL_PORT, STEPPER_u8_COIL_BLUE,DIO_u8_LOW);
	_delay_ms(5);
	DIO_voidSetPinValue(STEPPER_u8_COIL_PORT,STEPPER_u8_COIL_Orange,DIO_u8_LOW);
	DIO_voidSetPinValue(STEPPER_u8_COIL_PORT,STEPPER_u8_COIL_Yellow,DIO_u8_LOW);
	DIO_voidSetPinValue(STEPPER_u8_COIL_PORT,STEPPER_u8_COIL_Pink,DIO_u8_LOW);
	DIO_voidSetPinValue(STEPPER_u8_COIL_PORT, STEPPER_u8_COIL_BLUE,DIO_u8_HIGH);
	_delay_ms(5);
}
