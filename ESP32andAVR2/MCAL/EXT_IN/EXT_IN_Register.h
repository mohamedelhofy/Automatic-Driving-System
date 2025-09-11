/*
 * EXT_IN_Register.h
 *
 *  Created on: Aug 28, 2025
 *      Author: Marina Boutros
 */

#ifndef EXT_IN_REGISTER_H_
#define EXT_IN_REGISTER_H_

#define 	MCUCR *((volatile u8*)(0x55))
#define 	MCUCSR *((volatile u8*)(0x54))
#define 	GICR *((volatile u8*)(0x5B))
#define 	GIFR *((volatile u8*)(0x5A))

#endif /* EXT_IN_REGISTER_H_ */
