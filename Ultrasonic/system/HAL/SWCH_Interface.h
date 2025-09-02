/*
 * SWCH_Interface.h
 *
 *  Created on: Aug 26, 2025
 *      Author: alhof
 */

#ifndef SWCH_INTERFACE_H_
#define SWCH_INTERFACE_H_

#define SWCH_INPUT_PULLUP 0
#define SWCH_INPUT_FLOATING 1

void SWCH_int(u8 ARG_u8InputState);
u8 SWCH_GETVal();
#endif /* SWCH_INTERFACE_H_ */
