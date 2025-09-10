/*
 * ADC_Program.c
 *
 *  Created on: Sep 1, 2025
 *      Author: alhof
 */

#include "../Library/STD_TYPES.h"
#include "../Library/BIT_MATH.h"
#include "ADC_Interface.h"
#include "ADC_Register.h"
void ADC_voidInit(void){
	// select voltage refernce
	CLR_BIT(ADMUX,ADMUX_REFS1);
	SET_BIT(ADMUX,ADMUX_REFS0);
	// select the right adjustment
	CLR_BIT(ADMUX,ADMUX_ADLAR);
	// Prescaler Select
	SET_BIT(ADCSRA,ADSCRA_ADPS0);
	SET_BIT(ADCSRA,ADSCRA_ADPS1);
	SET_BIT(ADCSRA,ADSCRA_ADPS2);
	//  enables the ADC
	SET_BIT(ADCSRA,ADSCRA_ADEN);
}
u16 ADC_u16GetDigitalValue(u8 Copy_u8ChannelNb){
	ADMUX &= ADMUX_CHANNEL_NUM_MASK ;
	// select channel number
	ADMUX |= Copy_u8ChannelNb ;
	// Start Conversion
	SET_BIT(ADCSRA,ADSCRA_ADSC);
	// polling on flag
	while(GET_BIT(ADCSRA,ADSCRA_ADIF) == 0);
	SET_BIT(ADCSRA,ADSCRA_ADIF);

	return ADC;

}
