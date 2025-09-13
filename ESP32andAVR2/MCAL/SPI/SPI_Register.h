/*
 * SPI_Register.h
 *
 *  Created on: Sep 9, 2025
 *      Author: Marina Boutros
 */

#ifndef MCAL_SPI_SPI_REGISTER_H_
#define MCAL_SPI_SPI_REGISTER_H_

/* SPI */
#define SPCR    (*(volatile u8 *)(0x2D))
#define SPSR    (*(volatile u8 *)(0x2E))
#define SPDR    (*(volatile u8 *)(0x2F))

/* SPSR */
#define SPIF    7
#define WCOL    6
/* bits 5-1 reserved */
#define SPI2X   0

/* SPCR */
#define SPIE    7
#define SPE     6
#define DORD    5
#define MSTR    4
#define CPOL    3
#define CPHA    2
#define SPR1    1
#define SPR0    0





#endif /* MCAL_SPI_SPI_REGISTER_H_ */
