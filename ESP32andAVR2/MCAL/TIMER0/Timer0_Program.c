/*
 * Timer0_Program.c
 *
 *  Created on: Sep 10, 2025
 *      Author: Marina Boutros
 */

#include "../../Library/STD_TYPES.h"
#include "../../Library/BIT_MATH.h"
#include "../DIO_Interface.h"
#include "../Global_Interrupt_Enable/GIE_Interface.h"
#include "Timer0_Interface.h"
#include "Timer0_Register.h"

void Timer0_void_init(void){
	Global_Interrupt_Enable();
	//Waveform Generation Mode Mode normal
	CLR_BIT(TCCR0,6);
	CLR_BIT(TCCR0,3);
	//  Clock Select  8
	CLR_BIT(TCCR0,0);
	SET_BIT(TCCR0,1);
	CLR_BIT(TCCR0,2);
	// Timer 0 counter
	SET_BIT(TIMSK,0);
}
void Timer0_void_CTC(){
	Global_Interrupt_Enable();
	//Waveform Generation Mode ctc
	CLR_BIT(TCCR0,6);
	SET_BIT(TCCR0,3);
	//  Clock Select  8
	CLR_BIT(TCCR0,0);
	SET_BIT(TCCR0,1);
	CLR_BIT(TCCR0,2);
	OCR0=255;
	// Timer 0 counter
	SET_BIT(TIMSK,1);
}
void Timer0_voidSet_CompareMatch_Value(u8 u8_local_OCR_Value){
	OCR0 = u8_local_OCR_Value;
}
void Timer0_Init_PWM(void){
	//Waveform Generation Mode fast pwm without ctc
	SET_BIT(TCCR0,6);
	SET_BIT(TCCR0,3);
	//  Clock Select  8
	CLR_BIT(TCCR0,0);
	SET_BIT(TCCR0,1);
	CLR_BIT(TCCR0,2);
	// set and clear at top
	SET_BIT(TCCR0,4);
	SET_BIT(TCCR0,5);
	// set B3 out =1
	DIO_voidSetPinDirection(DIO_u8_PORTB,DIO_u8_PIN3,DIO_u8_OUTPUT);
}
void Timer0_Init_Phase_PWM(void){
	//Waveform Generation Mode fast pwm without ctc
	SET_BIT(TCCR0,6);
	SET_BIT(TCCR0,3);
	//  Clock Select  8
	CLR_BIT(TCCR0,0);
	SET_BIT(TCCR0,1);
	CLR_BIT(TCCR0,2);
	// set and clear at top
	CLR_BIT(TCCR0,4);
	SET_BIT(TCCR0,5);
	// set B3 out =1
	DIO_voidSetPinDirection(DIO_u8_PORTB,DIO_u8_PIN3,DIO_u8_OUTPUT);
}

void Timer0_voidInit_FastPWM(void)
{
    // Fast PWM Mode
    SET_BIT(TCCR0, 6);
    SET_BIT(TCCR0, 3);

    // Non-Inverting Mode (Clear on compare match, set on TOP)
    CLR_BIT(TCCR0, 4);
    SET_BIT(TCCR0, 5);

    // Prescaler = 8
    CLR_BIT(TCCR0, 0);
    SET_BIT(TCCR0, 1);
    CLR_BIT(TCCR0, 2);

    // Set OC0 (PB3) as output
    DIO_voidSetPinDirection(DIO_u8_PORTB, DIO_u8_PIN3, DIO_u8_OUTPUT);
}

void Timer0_voidSetDuty(u8 duty)
{
    OCR0 = duty;   // 0 → 0% speed, 255 → 100% speed
}
