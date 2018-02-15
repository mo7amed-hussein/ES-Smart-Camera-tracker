#define F_CPU 16000000UL
#include <avr/io.h>
#include "util/delay.h"
#include "servo/servo.h"
extern uint8_t currentPanAngle ;
extern uint8_t currentTiltAngle ;
/* VCC -> E2 , GND-> E4, Control - E0 ->  */
int main(void)
{
	
	//system leds
	DDRB |= (1<<PB0);
	PORTB &= ~(1<<PB0);
	
	//init serve
	//initServo();
	initPanTilt();
	//DDRD |= (1<<PD7);
	//PORTD &= ~(1<<PD7);
	//moveToAngle(0);
	//_delay_ms(3000);
	//moveToAngle(90);
	//_delay_ms(3000);
	//moveToAngle(135);
	//moveToAngle(650);
	//moveToAngle(1500);
	//moveToAngle(2400);
	//moveToAngle(180);
	//moveToAngle(45);
	uint8_t angle =0;
	currentPanAngle =180;
	currentTiltAngle=180;
	movePanToAngle(180);
	moveTiltToAngle(180);
	while(1)
	{
		
		PORTB &= ~(1<<PB0);
		_delay_ms(1000);
		PORTB |= (1<<PB0);
		_delay_ms(1000);
		//moveToAngle(angle);
		//angle += 25;
		//if (angle >180)
		//{
			//angle=0;
		//}
		//moveLeft();
		//moveDown();
		moveRight();
		moveUp();
	}
}
