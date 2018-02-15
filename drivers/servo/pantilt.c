/*
 * pantilt.c
 *
 * Created: 2/14/2018 9:43:21 PM
 *  Author: mohamed
 */ 
#define F_CPU 16000000UL
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

void resetPan()
{
	currentPanAngle=0;
	movePanToAngle(0);
}

void resetTilt()
{
	currentTiltAngle=0;
	moveTiltToAngle(0);
}

void moveUp()
{
	currentTiltAngle--;
	if(currentTiltAngle<0)
	{
		currentTiltAngle=0;
	}
	moveTiltToAngle(currentTiltAngle);
}

void moveDown()
{
	currentTiltAngle++;
	if(currentTiltAngle>180)
	{
		currentTiltAngle=180;
	}
	moveTiltToAngle(currentTiltAngle);
}

void moveRight()
{
	currentPanAngle--;
	if(currentPanAngle <0)
	{
		currentPanAngle=0;
	}
	movePanToAngle(currentPanAngle);
}

void moveLeft()
{
	currentPanAngle++;
	if(currentPanAngle >180)
	{
		currentPanAngle=180;
	}
	movePanToAngle(currentPanAngle);
	
}