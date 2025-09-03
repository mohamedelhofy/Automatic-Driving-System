#include "../Library/BIT_MATH.h"
#include "../Library/STD_TYPES.h"
#include "../MCAL/DIO_Interface.h"
#include "../MCAL/GIE_Interface.h"
#include "../MCAL/Timer1_Interface.h"
#include <avr/interrupt.h>
#include "util/delay.h"
#include <avr/iom32.h>

ISR(TIMER1_OVF_vect)
{
	 static u16 Counter=0;
	 if (Counter >= 15)
	 {

		 DIO_voidSetPinValue(DIO_u8_PORTB,DIO_u8_PIN1,DIO_u8_HIGH);
		 Counter=0;

	 }
	 Counter++;

}


int main()
{
	Timer1_voidInit_Normal();
	DIO_voidSetPinDirection(DIO_u8_PORTB,DIO_u8_PIN1,DIO_u8_OUTPUT);

	while(1)
	{

	}
	return 0;
}
