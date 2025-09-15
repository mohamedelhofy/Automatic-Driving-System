/*
 * Keypad_Config.h
 *
 *  Created on: Aug 25, 2025
 *      Author: alhof
 */

#ifndef KEYPAD_CONFIG_H_
#define KEYPAD_CONFIG_H_

#define Keypad_PORT   DIO_u8_PORTB

#define KPD_ROW0_PIN				DIO_u8_PIN4
#define KPD_ROW1_PIN				DIO_u8_PIN5
#define KPD_ROW2_PIN                DIO_u8_PIN6
#define KPD_ROW3_PIN                DIO_u8_PIN7

#define KPD_COL0_PIN				DIO_u8_PIN3
#define KPD_COL1_PIN				DIO_u8_PIN2
#define KPD_COL2_PIN                DIO_u8_PIN1
#define KPD_COL3_PIN                DIO_u8_PIN0

#define KPD_Array {{0,1,2,3},{4,5,6,7},{8,9,10,11},{12,13,14,15}}
#define KPD_Change_Val {{15,14.13,12},{11,10,9,8},{7,6,5,4},{3,2,1,0}}

#endif /* KEYPAD_CONFIG_H_ */
