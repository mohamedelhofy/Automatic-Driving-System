/*
 * Keypad_Program.c
 *
 *  Created on: Aug 25, 2025
 *      Author: alhof
 */
#include "../Library/STD_TYPES.h"
#include "../Library/BIT_MATH.h"
#include "../MCAL/DIO_Interface.h"
#include "../MCAL/DIO_Register.h"
#include "Keypad_Interface.h"
#include "Keypad_Config.h"
#include "util/delay.h"

u8 KPD_au8SwitchVal[4][4] = KPD_Array;
u8 ROWS[4]={KPD_ROW0_PIN,KPD_ROW1_PIN,KPD_ROW2_PIN,KPD_ROW3_PIN};
u8 COLS[4]={KPD_COL0_PIN,KPD_COL1_PIN,KPD_COL2_PIN,KPD_COL3_PIN};
u8 pressed_key = NOT_Pressed;
static u8 last_pressed_key = NOT_Pressed;
void KPD_setup(void){
	pressed_key = NOT_Pressed;
	for(u8 i = 0; i < 4 ; i++){
		DIO_voidSetPinDirection(Keypad_PORT,ROWS[i],DIO_u8_INPUT);
		DIO_voidSetPinValue(Keypad_PORT,ROWS[i],DIO_u8_HIGH);
		DIO_voidSetPinDirection(Keypad_PORT,COLS[i],DIO_u8_OUTPUT);
		DIO_voidSetPinValue(Keypad_PORT,COLS[i],DIO_u8_HIGH);
	}
}

u8 GET_Key_Number(void){
	for(u8 i = 0;i <4 ; i++){
		DIO_voidSetPinValue(Keypad_PORT,COLS[i],DIO_u8_LOW);
		for(u8 j = 0 ; j < 4 ; j++){
			u8 state = DIO_u8GetPinValue(Keypad_PORT,ROWS[j]);
			if(DIO_u8_LOW == state){
				pressed_key = KPD_au8SwitchVal[j][i];
				return j;
			}
		}
		DIO_voidSetPinValue(Keypad_PORT,COLS[i],DIO_u8_HIGH);
	}
	return NOT_Pressed;
}
//---------------------------------------------------------------
u8 GET_Pressed_Key(void){
	KPD_setup();
    GET_Key_Number();
	if(last_pressed_key == pressed_key){
		return NOT_Pressed;
	}else{
		if(last_pressed_key == NOT_Pressed){
			last_pressed_key = pressed_key;
			return pressed_key;
		}else {
			last_pressed_key = pressed_key;
			return NOT_Pressed;
		}
	}

}
u32 GET_Pressed_Time(void){
	KPD_setup();
	u8 col = GET_Key_Number();
	u32 press_time = 0;
	while(DIO_u8_LOW == DIO_u8GetPinValue(Keypad_PORT,ROWS[col])) {
		_delay_ms(1000);
		press_time+=1000;
	}
    return press_time;
}
