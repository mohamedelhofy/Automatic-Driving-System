/*
 * SPI_Interface.h
 *
 *  Created on: Sep 9, 2025
 *      Author: Marina Boutros
 */

#ifndef MCAL_SPI_SPI_INTERFACE_H_
#define MCAL_SPI_SPI_INTERFACE_H_
#include "../../LIBRARY/BIT_MATH.h"
#include "../../LIBRARY/STD_TYPES.h"
#include "../DIO_Interface.h"
#include "../DIO_Register.h"


void SPI_Master_Init_(void);
void SPI_Master_Init_Interrupt(void);
void SPI_Slave_Init_(void);
void SPI_Slave_Init_Interrupt(void);

u8 SPI_Send_Receive_Data(u8 data);

#endif /* MCAL_SPI_SPI_INTERFACE_H_ */
