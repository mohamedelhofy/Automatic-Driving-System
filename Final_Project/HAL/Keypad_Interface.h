/*
 * Keypad_Interface.h
 *
 *  Created on: Aug 25, 2025
 *      Author: alhof
 */

#ifndef KEYPAD_INTERFACE_H_
#define KEYPAD_INTERFACE_H_
//#define Keypad_Port DIO_u8_PORTB

u8 GET_Pressed_Key(void);
u32 GET_Pressed_Time(void);

#define NOT_Pressed 0XFF


#endif /* KEYPAD_INTERFACE_H_ */
