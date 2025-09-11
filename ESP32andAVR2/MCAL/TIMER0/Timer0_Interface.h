/*
 * Timer0_Interface.h
 *
 *  Created on: Sep 10, 2025
 *      Author: Marina Boutros
 */

#ifndef MCAL_TIMER0_TIMER0_INTERFACE_H_
#define MCAL_TIMER0_TIMER0_INTERFACE_H_

void Timer0_void_init(void);
void Timer0_voidSet_CompareMatch_Value(u8 u8_local_OCR_Value);
void Timer0_void_CTC(void);
void Timer0_Init_PWM(void);
void Timer0_voidInit_FastPWM(void);
void Timer0_voidSetDuty(u8 duty);

#endif /* MCAL_TIMER0_TIMER0_INTERFACE_H_ */
