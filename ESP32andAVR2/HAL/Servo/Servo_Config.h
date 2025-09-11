/*
 * Servo_Config.h
 *
 *  Created on: Sep 10, 2025
 *      Author: Marina Boutros
 */

#ifndef HAL_SERVO_SERVO_CONFIG_H_
#define HAL_SERVO_SERVO_CONFIG_H_

// البن اللي السيرفو متوصل عليه (OC1A = PD5 or OC1B = PD4)
// هنا هنختار OC1A = PD5
#define SERVO_DDR   DDRD
#define SERVO_PORT  PORTD
#define SERVO_PIN   PD5

// Timer1 Settings
#define SERVO_TOP        20000   // 20ms period (50Hz)
#define SERVO_MIN_PULSE  500    // ~0°
#define SERVO_MAX_PULSE  2500    // ~180°

#endif /* HAL_SERVO_SERVO_CONFIG_H_ */
