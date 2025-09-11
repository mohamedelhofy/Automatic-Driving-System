/*
 * EXT_IN_Prog.c
 *
 *  Created on: Aug 28, 2025
 *      Author: Marina Boutros
 */


#include "../../Library/STD_TYPES.h"
#include "../../Library/BIT_MATH.h"
#include"../DIO_Interface.h"
#include"../DIO_Register.h"
#include "../Global_Interrupt_Enable/GIE_Interface.h"
#include "EXT_IN_Interface.h"
#include "EXT_IN_Register.h"

void EXT1_IN_Enable(void){
    // Enable global interrupts
	Global_Interrupt_Enable();

    /*** INT0 Falling Edge ***/
    MCUCR |= (1 << 1);
    MCUCR &= ~(1 << 0);
    SET_BIT(MCUCR, 3);   // ISC01 = 1
    CLR_BIT(MCUCR, 2);   // ISC00 = 0
    GICR |=1<<6;
    GICR |=1<<7;
    DIO_voidSetPinDirection(DIO_u8_PORTD,3,0);
    DIO_voidSetPinValue(DIO_u8_PORTD,3,1);
}
void EXT2_IN_Enable(void){}
