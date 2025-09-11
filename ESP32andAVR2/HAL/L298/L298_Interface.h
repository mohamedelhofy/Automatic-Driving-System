/*
 * L298_Interface.h
 *
 *  Created on: Sep 10, 2025
 *      Author: Marina Boutros
 */

#ifndef HAL_L298_L298_INTERFACE_H_
#define HAL_L298_L298_INTERFACE_H_

#define MOVE_FORWARD   0
#define MOVE_BACKWARD  1
#define MOVE_LEFT      2
#define MOVE_RIGHT     3
#define MOVE_STOP      4

void L298_voidInit(void);
void L298_voidMove(u8 Copy_u8Direction, u8 Copy_u8Speed);
void L298_voidMoveForward(void);
void L298_voidStop(void);

#endif /* HAL_L298_L298_INTERFACE_H_ */
