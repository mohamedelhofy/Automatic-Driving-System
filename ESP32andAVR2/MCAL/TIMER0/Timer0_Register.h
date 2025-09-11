/*
 * Timer0_Register.h
 *
 *  Created on: Sep 10, 2025
 *      Author: Marina Boutros
 */

#ifndef MCAL_TIMER0_TIMER0_REGISTER_H_
#define MCAL_TIMER0_TIMER0_REGISTER_H_

#define TCCR0 (*(volatile u8 *)(0x53))
#define TCNT0 (*(volatile u8 *)(0x52))
#define OCR0  (*(volatile u8 *)(0x5C))
#define TIMSK (*(volatile u8 *)(0x59))
#define TIFR  (*(volatile u8 *)(0x58))


#endif /* MCAL_TIMER0_TIMER0_REGISTER_H_ */
