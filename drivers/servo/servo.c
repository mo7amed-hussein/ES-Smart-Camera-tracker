/*
 * servo.c
 *
 * Created: 2/14/2018 1:07:38 PM
 *  Author: mohamed
 */ 
#define F_CPU 16000000UL
#include "servo.h"


void initServo()
{
	//config port as output
	SERVO_DDR |= (1<<SERVO_PIN);
	//force output zero
	SERVO_PORT &= ~(1<<SERVO_PIN);
	
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

void moveToAngle(uint8_t angle)
{
	uint16_t requiredDelay = claculateDelay(angle);//in usec
	uint8_t i=0;
	for(i=0; i<SERVO_STABILITY_VALUE;i++)
	{
		SERVO_PORT |= (1<<SERVO_PIN);
		_delay_us(requiredDelay);
		SERVO_PORT &= ~(1<<SERVO_PIN);
		_delay_us(20000-requiredDelay);
	}
}