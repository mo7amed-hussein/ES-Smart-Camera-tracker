/*
 * pantilt.c
 *
 * Created: 2/14/2018 9:43:21 PM
 *  Author: mohamed
 */ 

#include "pantilt.h"

void initPanTilt()
{
	//config pins as outputs
	SERVO_DDR |= (1<<PAN_PIN) |(1<<TILT_PIN);
	//init pins to output zero
	SERVO_PORT &= ~(1<<PAN_PIN);
	SERVO_PORT &= ~(1<<TILT_PIN);
	//reset pan and tilt
	resetPan();
	resetTilt();
}