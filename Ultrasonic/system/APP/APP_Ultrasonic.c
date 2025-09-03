#include "../Library/STD_TYPES.h"
#include "../Library/BIT_MATH.h"
#include "../HAL/Ultrasonic_Interface.h"
#include "../HAL/LCD_Interfac.h"
#include "../MCAL/DIO_Interface.h"
#include <util/delay.h>
#include <stdlib.h>

int main(void)
{
    f32 distance;

    /* Init */
    Ultrasonic_Init();

    /* LEDs on PORTC */
    DIO_voidSetPortDirection(DIO_u8_PORTA, 0xFF);


    while(1)
    {
        distance = Ultrasonic_GetDistance();


        /* Handle LED output */
        if (distance < 10)
            DIO_voidSetPortValue(DIO_u8_PORTA, 0b00000001); // LED0 ON
        else if (distance < 20)
            DIO_voidSetPortValue(DIO_u8_PORTA, 0b00000010); // LED1 ON
        else if (distance < 30)
            DIO_voidSetPortValue(DIO_u8_PORTA, 0b00000100); // LED2 ON
        else if (distance < 40)
            DIO_voidSetPortValue(DIO_u8_PORTA, 0b00001000); // LED3 ON
        else if (distance < 70)
            DIO_voidSetPortValue(DIO_u8_PORTA, 0b00010000); // LED3 ON
        else if (distance < 100)
            DIO_voidSetPortValue(DIO_u8_PORTA, 0b00100000); // LED3 ON
        else if (distance < 120)
            DIO_voidSetPortValue(DIO_u8_PORTB, 0b01000000); // LED3 ON
        else
            DIO_voidSetPortValue(DIO_u8_PORTA, 0b10000000); // Last LED ON

        _delay_ms(200);
    }
}
