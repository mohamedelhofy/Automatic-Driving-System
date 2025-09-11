/*
 * Stepper_config.h
 *
 *  Created on: Sep 1, 2025
 *      Author: Marina Boutros
 */

#ifndef HAL_STEPPER_CONFIG_H_
#define HAL_STEPPER_CONFIG_H_

#define STEPPER_u8_CIOL_Blue	DIO_u8_PIN0
#define STEPPER_u8_CIOL_Pink	DIO_u8_PIN1
#define STEPPER_u8_CIOL_Yellow	DIO_u8_PIN2
#define STEPPER_u8_CIOL_Orange	DIO_u8_PIN3


#define STEPPER_u8_COIL_PORT	DIO_u8_PORTD
#define CW 1
#define ACW 0
#define STEPS_PER_REV	2048

#endif /* HAL_STEPPER_CONFIG_H_ */
