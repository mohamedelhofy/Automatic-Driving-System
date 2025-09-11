/*
 * DIO_Interface.h
 *
 *  Created on: Aug 25, 2025
 *      Author: Marina Boutros
 */
#ifndef DIO_INTERFACE_H
#define DIO_INTERFACE_H


#define DIO_u8_PORTA 0
#define DIO_u8_PORTB 1
#define DIO_u8_PORTC 2
#define DIO_u8_PORTD 3

#define DIO_u8_PIN0 0
#define DIO_u8_PIN1 1
#define DIO_u8_PIN2 2
#define DIO_u8_PIN3 3

#define DIO_u8_PIN4 4
#define DIO_u8_PIN5 5
#define DIO_u8_PIN6 6
#define DIO_u8_PIN7 7


#define DIO_u8_OUTPUT 1
#define DIO_u8_INPUT  0
#define DIO_u8_HIGH   1
#define DIO_u8_LOW    0

// 5 FUN
//DIO_SET PORT DIRECTION
//DIO_SET PIN DIRECTION
//DIO_SET PORT VALUE
//DIO_SET PIN VALUE
//GET_PIN_VALUE
void DIO_voidSetPinDirection(u8 u8PortIdCopy, u8 u8PinIdCopy, u8 u8PinDirCopy);

void DIO_voidSetPortDirection(u8 u8PortId, u8 Direction);
void DIO_voidSetPortValue(u8 u8PortId, u8 u8PortVal);
void DIO_voidSetPinValue(u8 u8PortIdCopy , u8 u8PinIdCopy, u8 u8PinValCopy);

u8   DIO_u8GetPinValue(u8 u8PortIdCopy, u8 u8PinIdCopy);

#endif /* DIO_INTERFACE_H_ */
