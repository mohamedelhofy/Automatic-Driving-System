/*
 * Timer1_Register.h
 *
 *  Created on: Sep 3, 2025
 *      Author: alhof
 */

#ifndef SYSTEM_MCAL_TIMER1_REGISTER_H_
#define SYSTEM_MCAL_TIMER1_REGISTER_H_

/* Prescaler options */
#define TIMER1_NO_CLOCK        0
#define TIMER1_PRESCALER_1     1
#define TIMER1_PRESCALER_8     2
#define TIMER1_PRESCALER_64    3
#define TIMER1_PRESCALER_256   4
#define TIMER1_PRESCALER_1024  5

/* Default Prescaler */
#define TIMER1_PRESCALER   TIMER1_PRESCALER_8


/* Timer1 Registers */
#define TCCR1A   (*(volatile u8*)0x4F)
#define TCCR1B   (*(volatile u8*)0x4E)
#define TCNT1    (*(volatile u16*)0x4C)
#define OCR1A    (*(volatile u16*)0x4A)
#define OCR1B    (*(volatile u16*)0x48)
#define ICR1     (*(volatile u16*)0x46)
#define TIMSK    (*(volatile u8*)0x59)
#define TIFR     (*(volatile u8*)0x58)


#endif /* SYSTEM_MCAL_TIMER1_REGISTER_H_ */
