#include <util/delay.h>
#include "../Library/STD_TYPES.h"
#include "../Library/BIT_MATH.h"

#include "../MCAL/DIO_Interface.h"
#include "../MCAL/DIO_Register.h"

#include "LCD_Config.h"
#include "LCD_Interfac.h"


void LCD_vidInit_8bits(void) {
	DIO_voidSetPortDirection(DIO_u8_PORTB, 0xFF);
	DIO_voidSetPinDirection(DIO_u8_PORTC, 0, DIO_u8_OUTPUT);
	// RS
	DIO_voidSetPinDirection(DIO_u8_PORTC, 1, DIO_u8_OUTPUT);
	// RW
	DIO_voidSetPinDirection(DIO_u8_PORTC, 2, DIO_u8_OUTPUT);
	// EN
	// 2. Power-on delay (critical!)
	_delay_ms(40); // Extended delay for safet
	// 3. Triple initialization sequence
	LCD_vidSendCommand(0x30);
	_delay_ms(10);
	// Extended delay
	LCD_vidSendCommand(0x30);
	_delay_ms(1);
	LCD_vidSendCommand(0x30);
	_delay_us(150);
	// 4. Final configuration
	LCD_vidSendCommand(0x38);
	// 8-bit, 2-line, 5x8 font
	_delay_us(50);
	LCD_vidSendCommand(0x08);
	// Display off
	_delay_us(50);
	LCD_vidSendCommand(0x01);
	// Clear display
	_delay_ms(3); // Longer clear delay
	LCD_vidSendCommand(0x06); // Entry mode set
	_delay_us(50);
	LCD_vidSendCommand(0x0C); // Display on
	_delay_us(50); }


void LCD_vidSendCommand_(u8 u8Cmd) {
	LCD_vidSendCommand(u8Cmd >> 4);
	LCD_vidSendCommand(u8Cmd & 0x0F);


}

void LCD_vidGotoxy(u8 X, u8 Y)
{
	// Validate coordinates
	if (X < 16 && Y < 2)
	{
		// Calculate DDRAM address
		u8 address = (Y == 0) ? 0x80 + X : 0xC0 + X;
		LCD_vidSendCommand(address);
	}
}




void LCD_vidSendCommand(u8 u8CmdCpy){
	///8 Bits (D0->D7)////
	///RS -> 0 for command////
    DIO_voidSetPinDirection(LCD_CONTROL_PORT,LCD_RS_PIN, DIO_u8_OUTPUT);
	DIO_voidSetPinValue(LCD_CONTROL_PORT,LCD_RS_PIN, DIO_u8_LOW);

	DIO_voidSetPinValue(LCD_CONTROL_PORT,LCD_RW_PIN,DIO_u8_LOW);
	//pass command //D0->D7//
	DIO_voidSetPortDirection(LCD_DATA_PORT,0xff);
	DIO_voidSetPortValue(LCD_DATA_PORT,u8CmdCpy);

	//Enable
	DIO_voidSetPortDirection(LCD_CONTROL_PORT,0xff);
	DIO_voidSetPinValue(LCD_CONTROL_PORT,LCD_E_PIN, DIO_u8_HIGH);
	_delay_ms(2);
	DIO_voidSetPinValue(LCD_CONTROL_PORT,LCD_E_PIN, DIO_u8_LOW);

}
void LCD_vidSendCommand_4_Bits(uint8_t u8CmdCpy) {


	DIO_voidSetPinValue(LCD_CONTROL_PORT, LCD_RS_PIN, DIO_u8_LOW);
	DIO_voidSetPinValue(LCD_CONTROL_PORT, LCD_RW_PIN, DIO_u8_LOW);

	LCD_Port = (LCD_Port & 0x0F) | (u8CmdCpy & 0xF0); /* sending upper nibble */

	DIO_voidSetPinValue(LCD_CONTROL_PORT, LCD_E_PIN, DIO_u8_HIGH);
	_delay_us(1);
	DIO_voidSetPinValue(LCD_CONTROL_PORT, LCD_E_PIN, DIO_u8_LOW);
	_delay_us(100);



	LCD_Port = (LCD_Port & 0x0F) | (u8CmdCpy << 4);
	DIO_voidSetPinValue(LCD_CONTROL_PORT, LCD_E_PIN, DIO_u8_HIGH);
	_delay_us(1);
	DIO_voidSetPinValue(LCD_CONTROL_PORT, LCD_E_PIN, DIO_u8_LOW);
	_delay_us(100);

}
void LCD_vidWriteCharctr(u8 u8DataCpy){
	///8 Bits (D0->D7)////

	///RS -> 1 for Data////
	DIO_voidSetPinValue(LCD_CONTROL_PORT,LCD_RS_PIN, DIO_u8_HIGH);
	//RW PIN writing active LOW
	DIO_voidSetPinValue(LCD_CONTROL_PORT,LCD_RW_PIN,DIO_u8_LOW);
	//pass command //D0->D7//
	DIO_voidSetPortValue(LCD_DATA_PORT,u8DataCpy);
	//EnaLCD_vidWriteCharctrble
	DIO_voidSetPinValue(LCD_CONTROL_PORT,LCD_E_PIN, DIO_u8_HIGH);
	_delay_us(1);
	DIO_voidSetPinValue(LCD_CONTROL_PORT,LCD_E_PIN, DIO_u8_LOW);
	_delay_us(50);
}


void LCD_vidWriteCharctr_4bits(uint8_t u8DataCpy) {


	///RS -> 1 for Data////
	DIO_voidSetPinValue(LCD_CONTROL_PORT,LCD_RS_PIN, DIO_u8_HIGH);
	//RW PIN writing active LOW
	DIO_voidSetPinValue(LCD_CONTROL_PORT,LCD_RW_PIN,DIO_u8_LOW);

	DIO_voidSetPortValue(LCD_DATA_PORT, ((u8DataCpy >> 4) & 0x0F) << 4);
	_delay_us(1);
	DIO_voidSetPinValue(LCD_CONTROL_PORT, LCD_E_PIN, DIO_u8_HIGH);
	_delay_us(1);
	DIO_voidSetPinValue(LCD_CONTROL_PORT, LCD_E_PIN, DIO_u8_LOW);
	_delay_us(100);

	DIO_voidSetPortValue(LCD_DATA_PORT, ((u8DataCpy & 0x0F) << 4));
	//	_delay_us(1);

	DIO_voidSetPinValue(LCD_CONTROL_PORT, LCD_E_PIN, DIO_u8_HIGH);
	_delay_us(1);
	DIO_voidSetPinValue(LCD_CONTROL_PORT, LCD_E_PIN, DIO_u8_LOW);
	_delay_ms(2);
}




void LCD_vidInit_4bits(void)
{
	DIO_voidSetPortDirection(DIO_u8_PORTD,0XFF);
	DIO_voidSetPinDirection(DIO_u8_PORTC,0,DIO_u8_OUTPUT);
	DIO_voidSetPinDirection(DIO_u8_PORTC,1,DIO_u8_OUTPUT);
	DIO_voidSetPinDirection(DIO_u8_PORTC,2,DIO_u8_OUTPUT);
	_delay_ms(40);
	LCD_Command(0x02);		/* send for 4 bit initialization of LCD  */
	LCD_Command(0x28);              /* 2 line, 5*7 matrix in 4-bit mode */
	LCD_Command(0x0c);              /* Display on cursor off*/
	LCD_Command(0x06);              /* Increment cursor (shift cursor to right)*/
	LCD_Command(0x01);              /* Clear display screen*/
	_delay_ms(2);


}
void LCD_vidWriteNumber_8bits(u16 Copy_u16Number)
{
    char buffer[10];
    u8 i = 0;

    if (Copy_u16Number == 0)
    {
    	LCD_vidWriteCharctr('0');
        return;
    }

    while (Copy_u16Number > 0)
    {
        buffer[i] = (Copy_u16Number % 10) + '0';
        Copy_u16Number /= 10;
        i++;
    }

    while (i > 0)
    {
        i--;
        LCD_vidWriteCharctr(buffer[i]);
    }
}

void LCD_vidWriteNumber_4bits(u16 Copy_u16Number)
{
    char buffer[10];
    u8 i = 0;

    if (Copy_u16Number == 0)
    {
        LCD_Char('0');
        return;
    }

    while (Copy_u16Number > 0)
    {
        buffer[i] = (Copy_u16Number % 10) + '0';
        Copy_u16Number /= 10;
        i++;
    }

    while (i > 0)
    {
        i--;
        LCD_Char(buffer[i]);
    }
}

void LCD_Command( unsigned char cmnd )
{

	PORTC &= ~ (1<<RS);		/* RS=0, command reg. */
	PORTC &= ~ (1<<1);     /*RW -> 0 Writing */
	LCD_Port = (LCD_Port & 0x0F) | (cmnd & 0xF0); /* sending upper nibble */

	PORTC |= (1<<EN);		/* Enable pulse */
	_delay_us(1);
	PORTC &= ~ (1<<EN);

	_delay_us(200);

	LCD_Port = (LCD_Port & 0x0F) | (cmnd << 4);  /* sending lower nibble */
	PORTC |= (1<<EN);
	_delay_us(1);
	PORTC &= ~ (1<<EN);
	_delay_ms(2);
}

void LCD_Char( unsigned char data )
{

	PORTC |= (1<<RS);		/* RS=1, data reg. */
	PORTC &=~ (1<<1);
	///0X1111
	///make to store only first 4 bits
	LCD_Port = (LCD_Port & 0x0F) | (data & 0xF0); /* sending upper nibble */

	PORTC|= (1<<EN);

	_delay_us(1
	);
	PORTC &= ~ (1<<EN);

	_delay_us(200);

	LCD_Port = (LCD_Port & 0x0F) | (data << 4); /* sending lower nibble */
	PORTC |= (1<<EN);
	_delay_us(1);
	PORTC &= ~ (1<<EN);
	_delay_ms(2);
}

void LCD_Init (void)			/* LCD Initialize function */
{

	DIO_voidSetPinDirection(DIO_u8_PORTC, 0, DIO_u8_OUTPUT); // RS
	DIO_voidSetPinDirection(DIO_u8_PORTC, 1, DIO_u8_OUTPUT); // RW
	DIO_voidSetPinDirection(DIO_u8_PORTC, 2, DIO_u8_OUTPUT); // E

	DIO_voidSetPinDirection(DIO_u8_PORTB, 4, DIO_u8_OUTPUT); // D4
	DIO_voidSetPinDirection(DIO_u8_PORTB, 5, DIO_u8_OUTPUT); // D5
	DIO_voidSetPinDirection(DIO_u8_PORTB, 6, DIO_u8_OUTPUT); // D6
	DIO_voidSetPinDirection(DIO_u8_PORTB, 7, DIO_u8_OUTPUT); // D7

	_delay_ms(50);

	LCD_Command(0x33);
	LCD_Command(0x32);
	LCD_Command(0x28);
	LCD_Command(0x0C);
	LCD_Command(0x06);
	LCD_Command(0x01);
	_delay_ms(2);

}

void LCD_String (char *str)		/* Send string to LCD function */
{
	int i;
	for(i=0;str[i]!=0;i++)		/* Send each char of string till the NULL */
	{
		LCD_Char (str[i]);
	}
}

void LCD_String_xy (char row, char pos, char *str)	/* Send string to LCD with xy position */
{
	if (row == 0 && pos<16)
		LCD_Command((pos & 0x0F)|0x80);	/* Command of first row and required position<16 */
	else if (row == 1 && pos<16)
		LCD_Command((pos & 0x0F)|0xC0);	/* Command of first row and required position<16 */
	LCD_String(str);		/* Call LCD string function */
}

void LCD_Clear()
{
	LCD_Command (0x01);		/* Clear display */
	_delay_ms(2);
	LCD_Command (0x80);		/* Cursor at home position */
}
