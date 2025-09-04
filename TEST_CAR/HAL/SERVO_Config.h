/*
 * SERVO_Config.h
 *
 *  Created on: Sep 4, 2025
 *      Author: shaima
 */

#ifndef HAL_SERVO_CONFIG_H_
#define HAL_SERVO_CONFIG_H_

#define SERVO_CHANNEL   TIMER1_CHANNEL_B   // نقدر نخليها A أو B
#define SERVO_TOP       19999              // يدي 20ms مع prescaler = 8
// Servo متوصل على OC1B → PD4
#define SERVO_PORT   DIO_u8_PORTD
#define SERVO_PIN    DIO_u8_PIN4

// Min/Max pulse width للـ Servo
#define SERVO_MIN_PULSE  1000   // 1ms → 0 degree
#define SERVO_MAX_PULSE  2000   // 2ms → 180 degree


#endif /* HAL_SERVO_CONFIG_H_ */
