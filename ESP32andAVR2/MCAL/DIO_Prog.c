/*
 * DIO_Prog.c
 *
 *  Created on: Aug 25, 2025
 *      Author: Marina Boutros
 */


#include "../LIBRARY/STD_TYPES.h"
#include "../LIBRARY/BIT_MATH.h"
#include "DIO_Interface.h"
#include "DIO_Register.h"


//void DIO_voidSetPortDirection(u8 u8PortId, u8 Direction)
//{
//  if(Direction ==DIO_u8_OUTPUT )
//  {
//    switch(u8PortId)
//    {
//      case DIO_u8_PORTA:DDRA= 0xFF; break;
//      case DIO_u8_PORTB:DDRB= 0xFF; break;
//      case DIO_u8_PORTC:DDRC= 0xFF; break;
//      case DIO_u8_PORTD:DDRD= 0xFF; break;
//    }
//  }
//  else
//  {
//    switch(u8PortId)
//    {
//      case DIO_u8_PORTA:DDRA= 0x00; break;
//      case DIO_u8_PORTB:DDRB= 0x00; break;
//      case DIO_u8_PORTC:DDRC= 0x00; break;
//      case DIO_u8_PORTD:DDRD= 0x00; break;
//    }
//  }
//}

void DIO_voidSetPortDirection(u8 u8PortId, u8 Direction)
{
	switch(u8PortId)
	    {
	      case DIO_u8_PORTA:DDRA= Direction; break;
	      case DIO_u8_PORTB:DDRB= Direction; break;
	      case DIO_u8_PORTC:DDRC= Direction; break;
	      case DIO_u8_PORTD:DDRD= Direction; break;
	    }
}
void DIO_voidSetPortValue(u8 u8PortId, u8 u8PortVal)
{
    switch(u8PortId)
    {
      case DIO_u8_PORTA:PORTA=u8PortVal; break;
      case DIO_u8_PORTB:PORTB=u8PortVal; break;
      case DIO_u8_PORTC:PORTC=u8PortVal; break;
      case DIO_u8_PORTD:PORTD=u8PortVal; break;
    }
}

void DIO_voidSetPinDirection(u8 u8PortIdCopy, u8 u8PinIdCopy, u8 u8PinDirCopy)
{
  if(u8PinDirCopy == DIO_u8_OUTPUT )
  {
    switch(u8PortIdCopy)
        {
          case DIO_u8_PORTA:SET_BIT(DDRA,u8PinIdCopy); break;
          case DIO_u8_PORTB:SET_BIT(DDRB,u8PinIdCopy); break;
          case DIO_u8_PORTC:SET_BIT(DDRC,u8PinIdCopy); break;
          case DIO_u8_PORTD:SET_BIT(DDRD,u8PinIdCopy); break;
        }
  }
  else
    {
      switch(u8PortIdCopy)
      {
        case DIO_u8_PORTA:CLR_BIT(DDRA,u8PinIdCopy); break;
        case DIO_u8_PORTB:CLR_BIT(DDRB,u8PinIdCopy); break;
        case DIO_u8_PORTC:CLR_BIT(DDRC,u8PinIdCopy); break;
        case DIO_u8_PORTD:CLR_BIT(DDRD,u8PinIdCopy); break;
      }
    }

}
void DIO_voidSetPinValue(u8 u8PortIdCopy , u8 u8PinIdCopy, u8 u8PinValCopy)
{
  if(u8PinValCopy == DIO_u8_HIGH)
    {
      switch(u8PortIdCopy)
          {
            case DIO_u8_PORTA:SET_BIT(PORTA,u8PinIdCopy); break;
            case DIO_u8_PORTB:SET_BIT(PORTB,u8PinIdCopy); break;
            case DIO_u8_PORTC:SET_BIT(PORTC,u8PinIdCopy); break;
            case DIO_u8_PORTD:SET_BIT(PORTD,u8PinIdCopy); break;
          }
    }
    else
      {
        switch(u8PortIdCopy)
        {
          case DIO_u8_PORTA:CLR_BIT(PORTA,u8PinIdCopy); break;
          case DIO_u8_PORTB:CLR_BIT(PORTB,u8PinIdCopy); break;
          case DIO_u8_PORTC:CLR_BIT(PORTC,u8PinIdCopy); break;
          case DIO_u8_PORTD:CLR_BIT(PORTD,u8PinIdCopy); break;
        }
      }
}
u8   DIO_u8GetPinValue(u8 u8PortIdCopy, u8 u8PinIdCopy)
{
	u8 Pin_Value =0;
	switch (u8PortIdCopy)
	{
	case DIO_u8_PORTA : Pin_Value = GET_BIT(PINA,u8PortIdCopy);
	break;
	case DIO_u8_PORTB : Pin_Value = GET_BIT(PINB,u8PortIdCopy);
	break;
	case DIO_u8_PORTC : Pin_Value = GET_BIT(PINC,u8PortIdCopy);
	break;
	case DIO_u8_PORTD : Pin_Value = GET_BIT(PIND,u8PortIdCopy);
	break;


	}

	return Pin_Value;
}

