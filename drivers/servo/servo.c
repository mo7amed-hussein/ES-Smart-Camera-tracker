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

uint16_t claculateDelay(uint8_t angle)
{
	//validate angle to be between 0 and 180
	if(angle <0 )
	{
		angle = 0;
	}
	else if(angle >180)
	{
		
		angle =180;
	}
	return (SERVO_BASE_DELAY+(SERVO_STEP*angle));
}