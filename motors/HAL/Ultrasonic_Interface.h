/*
 * Ultrasonic_Interface.h
 *
 *  Created on: Sep 3, 2025
 *      Author: alhof
 */

#ifndef ULTRASONIC_INTERFACE_H_
#define ULTRASONIC_INTERFACE_H_


/* Initialize Ultrasonic sensor */
void Ultrasonic_Init(void);

/* Get distance in cm */
f32 Ultrasonic_GetDistance(void);

#endif /* ULTRASONIC_INTERFACE_H_ */
