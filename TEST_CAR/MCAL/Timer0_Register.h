
/*
 * Timer_Register.h
 *
 *  Created on: Sep 2, 2025
 *      Author: alhof
 */

#ifndef SYSTEM_MCAL_TIMER0_REGISTER_H_
#define SYSTEM_MCAL_TIMER0_REGISTER_H_

#define TCCR0 (*(volatile u8 *)(0x53))
#define TCNT0 (*(volatile u8 *)(0x52))
#define OCR0  (*(volatile u8 *)(0x5C))
#define TIMSK (*(volatile u8 *)(0x59))
#define TIFR  (*(volatile u8 *)(0x58))

#endif /* SYSTEM_MCAL_TIMER0_REGISTER_H_ */
