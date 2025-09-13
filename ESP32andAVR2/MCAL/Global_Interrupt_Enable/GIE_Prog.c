/*
 * GIE_Prog.c
 *
 *  Created on: Aug 27, 2025
 *      Author: shaima
 */

#include "../../LIBRARY/STD_TYPES.h"
#include "../../LIBRARY/BIT_MATH.h"
#include "../../MCAL/DIO_Interface.h"
#include "../../MCAL/DIO_Register.h"
#include "GIE_Interface.h"
#include "GIE_Register.h"


void Global_Interrupt_Enable(void)
{
    SET_BIT(SREG, 7);

}
void Global_Interrupt_Disable(void)
{
	CLR_BIT(SREG, 7);
}

