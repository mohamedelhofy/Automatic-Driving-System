/*
 * Timer1_Interface.h
 *
 *  Created on: Sep 10, 2025
 *      Author: Marina Boutros
 */

#ifndef MCAL_TIMER1_TIMER1_INTERFACE_H_
#define MCAL_TIMER1_TIMER1_INTERFACE_H_

void Timer1_voidInit_Normal(void);
void Timer1_voidInit_CTC_A(u16 compareValue);
void Timer1_voidInit_CTC_B(u16 compareValue);
void Timer1_voidInit_FastPWM_A(void);
void Timer1_voidInit_FastPWM_B(void);

/* Set Compare Match Values */
void Timer1_voidSetCompareMatchA(u16 value);
void Timer1_voidSetCompareMatchB(u16 value);

/* Set ICR1 (for PWM TOP) */
void Timer1_voidSetICR(u16 value);

/* Set Timer Counter */
void Timer1_voidSetTCNT(u16 value);
void Timer1_voidInitPWM(u16 top, u8 prescaler);
void Timer1_voidSetDuty(u8 channel, u16 duty);

#endif /* MCAL_TIMER1_TIMER1_INTERFACE_H_ */
