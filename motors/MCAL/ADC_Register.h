/*
 * ADC_Register.h
 *
 *  Created on: Sep 1, 2025
 *      Author: alhof
 */

#ifndef SYSTEM_MCAL_ADC_REGISTER_H_
#define SYSTEM_MCAL_ADC_REGISTER_H_

#define ADMUX  *((volatile u8 *)0x27)
#define ADCSRA  *((volatile u8 *)0x26)
#define ADCH    *((volatile u8 *)0x25)
#define ADCL    *((volatile u8 *)0x24)

#define ADC  *((volatile u16*)0x24)

/* ADMUX BITS */
#define ADMUX_REFS1   7
#define ADMUX_REFS0   6
#define ADMUX_ADLAR   5

#define ADMUX_CHANNEL_NUM_MASK 0b1110000

/* ADSCRA BITS */
#define ADSCRA_ADEN    7
#define ADSCRA_ADSC    6
#define ADSCRA_ADATE   5
#define ADSCRA_ADIF    4
#define ADSCRA_ADIE    3
#define ADSCRA_ADPS2   2
#define ADSCRA_ADPS1   1
#define ADSCRA_ADPS0   0


#endif /* SYSTEM_MCAL_ADC_REGISTER_H_ */
