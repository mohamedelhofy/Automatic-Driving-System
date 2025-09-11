/*
 * Ultrasonic_Interface.h
 *
 *  Created on: Sep 10, 2025
 *      Author: Marina Boutros
 */

#ifndef HAL_ULTRASONIC_ULTRASONIC_INTERFACE_H_
#define HAL_ULTRASONIC_ULTRASONIC_INTERFACE_H_

/* Initialize Ultrasonic sensor */
void Ultrasonic_Init(void);

/* Get distance in cm */
f32 Ultrasonic_GetDistance(void);

#endif /* HAL_ULTRASONIC_ULTRASONIC_INTERFACE_H_ */
