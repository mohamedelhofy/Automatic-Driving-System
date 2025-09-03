/*
 * Timer1_Program.c
 *
 *  Created on: Sep 3, 2025
 *      Author: alhof
 */



#include "../Library/STD_TYPES.h"
#include "../Library/BIT_MATH.h"
#include "Timer1_Interface.h"
#include "Timer1_Register.h"
#include "DIO_Interface.h"
#include "GIE_Interface.h"

void Timer1_voidInit_Normal(void)
{
    Global_Interrupt_Enable();

    /* Normal mode */
    CLR_BIT(TCCR1A,0);
    CLR_BIT(TCCR1A,1);
    CLR_BIT(TCCR1B,3);
    CLR_BIT(TCCR1B,4);

    /* Prescaler */
    TCCR1B |= TIMER1_PRESCALER;

    /* Enable overflow interrupt */
    SET_BIT(TIMSK,2);
}

void Timer1_voidInit_CTC_A(u16 compareValue)
{
    Global_Interrupt_Enable();

    /* CTC mode with OCR1A */
    CLR_BIT(TCCR1A,0);
    SET_BIT(TCCR1A,1);
    CLR_BIT(TCCR1B,3);
    CLR_BIT(TCCR1B,4);

    OCR1A = compareValue;

    /* Prescaler */
    TCCR1B |= TIMER1_PRESCALER;

    /* Enable OCR1A interrupt */
    SET_BIT(TIMSK,4);
}

void Timer1_voidInit_CTC_B(u16 compareValue)
{
    Global_Interrupt_Enable();

    /* CTC mode with OCR1B */
    CLR_BIT(TCCR1A,0);
    SET_BIT(TCCR1A,1);
    CLR_BIT(TCCR1B,3);
    CLR_BIT(TCCR1B,4);

    OCR1B = compareValue;

    /* Prescaler */
    TCCR1B |= TIMER1_PRESCALER;

    /* Enable OCR1B interrupt */
    SET_BIT(TIMSK,3);
}

void Timer1_voidInit_FastPWM_A(void)
{
    /* Fast PWM with ICR1 as TOP */
    SET_BIT(TCCR1A,1);
    CLR_BIT(TCCR1A,0);
    SET_BIT(TCCR1B,3);
    SET_BIT(TCCR1B,4);

    /* Clear OC1A on compare match, set at TOP */
    SET_BIT(TCCR1A,7);
    CLR_BIT(TCCR1A,6);

    /* Prescaler */
    TCCR1B |= TIMER1_PRESCALER;

    /* OC1A pin as output */
    DIO_voidSetPinDirection(DIO_u8_PORTD,DIO_u8_PIN5,DIO_u8_OUTPUT); // OC1A
}

void Timer1_voidInit_FastPWM_B(void)
{
    /* Fast PWM with ICR1 as TOP */
    SET_BIT(TCCR1A,1);
    CLR_BIT(TCCR1A,0);
    SET_BIT(TCCR1B,3);
    SET_BIT(TCCR1B,4);

    /* Clear OC1B on compare match, set at TOP */
    SET_BIT(TCCR1A,5);
    CLR_BIT(TCCR1A,4);

    /* Prescaler */
    TCCR1B |= TIMER1_PRESCALER;

    /* OC1B pin as output */
    DIO_voidSetPinDirection(DIO_u8_PORTD,DIO_u8_PIN4,DIO_u8_OUTPUT); // OC1B
}

void Timer1_voidSetCompareMatchA(u16 value)
{
    OCR1A = value;
}

void Timer1_voidSetCompareMatchB(u16 value)
{
    OCR1B = value;
}

void Timer1_voidSetICR(u16 value)
{
    ICR1 = value;
}

void Timer1_voidSetTCNT(u16 value)
{
    TCNT1 = value;
}

