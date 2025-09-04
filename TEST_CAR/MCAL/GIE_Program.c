/*
 * GIE_Program.c
 *
 *  Created on: Aug 27, 2025
 *      Author: alhof
 */
#include "../Library/BIT_MATH.h"
#include "../Library/STD_TYPES.h"
#include "GIE_Register.h"
#include "GIE_Interface.h"
void Global_Interrupt_Disable(void){
	CLR_BIT(SREG,7);
}
void Global_Interrupt_Enable(void){
	SET_BIT(SREG,7);
}
