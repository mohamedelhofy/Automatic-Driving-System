/*
 * UART_Register.h
 *
 *  Created on: Sep 7, 2025
 *      Author: Marina Boutros
 */

#ifndef MCAL_UART_UART_REGISTER_H_
#define MCAL_UART_UART_REGISTER_H_




#define UDR		*((volatile u8 *)(0x2C))
#define UCSRA	*((volatile u8 *)(0x2B))
#define UCSRB	*((volatile u8 *)(0x2A))


#define UCSRC	*((volatile u8 *)(0x40))		//nafs l address
#define UBRRH	*((volatile u8 *)(0x40))		//nafs l address

#define UBRRL	*((volatile u8 *)(0x29))





#endif /* MCAL_UART_UART_REGISTER_H_ */
