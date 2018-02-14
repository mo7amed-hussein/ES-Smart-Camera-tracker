/*
 * servo.h
 *
 * Created: 2/14/2018 12:52:12 PM
 *  Author: mohamed
 */ 


#ifndef SERVO_H_
#define SERVO_H_
#include "util/delay.h"
#include <avr/io.h>

#define SERVO_STEP 8.62
#define SERVO_BASE_DELAY 750
#define SERVO_STABILITY_VALUE  50
#define SERVO_DDR DDRD
#define SERVO_PORT PORTD
#define SERVO_PIN PD7

void initServo();

void moveToAngle(uint8_t angle);

uint16_t claculateDelay(uint8_t angle);



#endif /* SERVO_H_ */