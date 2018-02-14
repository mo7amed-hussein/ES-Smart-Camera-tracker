#define F_CPU 16000000UL
#include <avr/io.h>
#include "util/delay.h"
#include "servo/servo.h"
/* VCC -> E2 , GND-> E4, Control - E0 ->  */
int main(void)
{
	
	//system leds
	DDRB |= (1<<PB0);
	PORTB &= ~(1<<PB0);
	
	//init serve
	initServo();
	
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
	int delay = 650;
	int cycles = 0;
	int i;
	for (i = 0;i<cycles;i++)
	{
		PORTD |= (1<<PD7);
		_delay_us(delay);
		PORTD &= ~(1<<PD7);
		_delay_us(20000-delay);
	}
	
	
	
	//cycles = 23;
	delay = 1500;
	for (i = 0;i<cycles;i++)
	{
		PORTD |= (1<<PD7);
		_delay_us(delay);
		PORTD &= ~(1<<PD7);
		_delay_us(20000-delay);
	}
	
	
	
	
	
	delay = 2400;
	for (i = 0;i<cycles;i++)
	{
		PORTD |= (1<<PD7);
		_delay_us(delay);
		PORTD &= ~(1<<PD7);
		_delay_us(20000-delay);
	}
	//moveToAngle(180);
	//moveToAngle(45);
	uint8_t angle =0;
	while(1)
	{
		
		PORTB &= ~(1<<PB0);
		_delay_ms(1000);
		PORTB |= (1<<PB0);
		_delay_ms(1000);
		moveToAngle(angle);
		angle += 25;
		if (angle >180)
		{
			angle=0;
		}
	}
}
