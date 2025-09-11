/*
 * ADC_Program.c
 *
 *  Created on: Sep 1, 2025
 *      Author: Marina Boutros
 */

#include "../../LIBRARY/BIT_MATH.h"
#include "../../LIBRARY/STD_TYPES.h"
#include "../../MCAL/DIO_Interface.h"
#include "../../MCAL/DIO_Register.h"

#include "ADC-Interface.h"
#include "ADC_Register.h"

#include <util/delay.h>




void ADC_voidInit 		(void)
{

	CLR_BIT(ADMUX , ADMUX_REFS1);	//AVCC & AREF external to 5v Mode
	SET_BIT(ADMUX , ADMUX_REFS0);	//AVCC & AREF external to 5v Mode

	CLR_BIT(ADMUX , ADMUX_ADLAR); //16-BIT MODE

	SET_BIT(ADCSRA , ADCSRA_ADPS0);  //h2sm 3la 128
	SET_BIT(ADCSRA , ADCSRA_ADPS1);  //h2sm 3la 128
	SET_BIT(ADCSRA , ADCSRA_ADPS2);  //h2sm 3la 128


	SET_BIT(ADCSRA , ADCSRA_ADEN);



}



u16 ADC_u16GetDigitalValue (u8 Copy_u8ChanelNb)
{
	ADMUX &= (ADMUX_CHANNEL_NUM_MASK);
	ADMUX |= Copy_u8ChanelNb ;

	SET_BIT(ADCSRA,ADCSRA_ADSC);

	while(GET_BIT(ADCSRA,ADCSRA_ADIF)==0);

	SET_BIT(ADCSRA,ADCSRA_ADIF);		//H5LEHA B 0 AKNY 3MLT CLEAR bs howa 3ashan interrupt f lma b3ml set akny b3ml clear

	return ADC;

}



