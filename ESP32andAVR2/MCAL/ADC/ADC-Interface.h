/*
 * ADC-Interface.h
 *
 *  Created on: Sep 1, 2025
 *      Author: Marina Boutros
 */

#ifndef MCAL_ADC_ADC_INTERFACE_H_
#define MCAL_ADC_ADC_INTERFACE_H_


#define ADC_u8_ADC_CHANNEL_0		0
#define ADC_u8_ADC_CHANNEL_1		1
#define ADC_u8_ADC_CHANNEL_2		2
#define ADC_u8_ADC_CHANNEL_3		3
#define ADC_u8_ADC_CHANNEL_4		4
#define ADC_u8_ADC_CHANNEL_5		5
#define ADC_u8_ADC_CHANNEL_6		6
#define ADC_u8_ADC_CHANNEL_7		7

void ADC_voidInit 		(void);
u16 ADC_u16GetDigitalValue (u8 Copy_u8ChanelNb);



#endif /* MCAL_ADC_ADC_INTERFACE_H_ */
