/*
 * Ultrasonic_Config.h
 *
 *  Created on: Sep 3, 2025
 *      Author: alhof
 */

#ifndef ULTRASONIC_CONFIG_H_
#define ULTRASONIC_CONFIG_H_

/* Trigger pin */
#define ULTRASONIC_TRIGGER_PORT   DIO_u8_PORTD
#define ULTRASONIC_TRIGGER_PIN    DIO_u8_PIN5

/* Echo pin is fixed to ICP1 = PD6 */
#define ULTRASONIC_ECHO_PORT      DIO_u8_PORTD
#define ULTRASONIC_ECHO_PIN       DIO_u8_PIN6

#endif /* ULTRASONIC_CONFIG_H_ */
