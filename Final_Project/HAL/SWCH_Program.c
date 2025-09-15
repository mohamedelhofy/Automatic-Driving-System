/*
 * SWCH_Program.c
 *
 *  Created on: Aug 26, 2025
 *      Author: alhof
 */
#include "../Library/STD_TYPES.h"
#include "../Library/BIT_MATH.h"
#include "../MCAL/DIO_Interface.h"
#include "../MCAL/DIO_Register.h"
#include "SWCH_Config.h"
#include "SWCH_Interface.h"
void SWCH_init(u8 ARG_u8InputState)
{
    switch(ARG_u8InputState)
    {
        case SWCH_INPUT_PULLUP:
            DIO_voidSetPinDirection(SWCH_PORT, SWCH_PIN, DIO_u8_INPUT);
            DIO_voidSetPinValue(SWCH_PORT, SWCH_PIN, 1);
            break;

        case SWCH_INPUT_FLOATING:
            DIO_voidSetPinDirection(SWCH_PORT, SWCH_PIN, DIO_u8_INPUT);
            break;

        default:
            break;
    }
}

u8 SWCH_GetVal()
{
    return (DIO_u8GetPinValue(SWCH_PORT, SWCH_PIN));
}
