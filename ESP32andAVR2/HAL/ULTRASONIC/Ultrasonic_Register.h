/*
 * Ultrasonic_Register.h
 *
 *  Created on: Sep 10, 2025
 *      Author: Marina Boutros
 */

#ifndef HAL_ULTRASONIC_ULTRASONIC_REGISTER_H_
#define HAL_ULTRASONIC_ULTRASONIC_REGISTER_H_

/* Trigger pin */
#define ULTRASONIC_TRIGGER_PORT   DIO_u8_PORTD
#define ULTRASONIC_TRIGGER_PIN    DIO_u8_PIN0

/* Echo pin is fixed to ICP1 = PD6 */
#define ULTRASONIC_ECHO_PORT      DIO_u8_PORTD
#define ULTRASONIC_ECHO_PIN       DIO_u8_PIN6

#endif /* HAL_ULTRASONIC_ULTRASONIC_REGISTER_H_ */
