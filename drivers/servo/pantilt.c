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

void movePanToAngle(uint8_t angle)
{
	uint16_t requiredDelay = claculateDelay(angle);//in usec
	uint8_t i=0;
	for(i=0; i<SERVO_STABILITY_VALUE;i++)
	{
		SERVO_PORT |= (1<<PAN_PIN);
		_delay_us(requiredDelay);
		SERVO_PORT &= ~(1<<PAN_PIN);
		_delay_us(20000-requiredDelay);
	}
}
void moveTiltToAngle(uint8_t angle)
{
	uint16_t requiredDelay = claculateDelay(angle);//in usec
	uint8_t i=0;
	for(i=0; i<SERVO_STABILITY_VALUE;i++)
	{
		SERVO_PORT |= (1<<TILT_PIN);
		_delay_us(requiredDelay);
		SERVO_PORT &= ~(1<<TILT_PIN);
		_delay_us(20000-requiredDelay);
	}	
}