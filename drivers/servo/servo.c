/*
 * servo.c
 *
 * Created: 2/14/2018 1:07:38 PM
 *  Author: mohamed
 */ 

#include "servo.h"


void initServo()
{
	//config port as output
	SERVO_DDR |= (1<<SERVO_PIN);
	//force output zero
	SERVO_PORT ~= (1<<SERVO_PIN);
	
}

