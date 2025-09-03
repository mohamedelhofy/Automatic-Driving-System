/*
 * Timer_Interface.h
 *
 *  Created on: Sep 2, 2025
 *      Author: alhof
 */

#ifndef SYSTEM_MCAL_TIMER0_INTERFACE_H_
#define SYSTEM_MCAL_TIMER0_INTERFACE_H_

void Timer0_void_init(void);
void Timer0_voidSet_CompareMatch_Value(u8 u8_local_OCR_Value);
void Timer0_void_CTC(void);
void Timer0_Init_PWM(void);

#endif /* SYSTEM_MCAL_TIMER0_INTERFACE_H_ */
