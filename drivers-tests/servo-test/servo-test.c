#define F_CPU 16000000UL
#include <avr/io.h>
#include "util/delay.h"
/* VCC -> E2 , GND-> E4, Control - E0 ->  */
int main(void)
{
	unsigned char i = 0;
	unsigned short delay = 0;
	unsigned short cycles = 0;

	
	//DDRE  |= ((1<<PE0)|(1<<PE2)|(1<<PE4));
	//PORTE |= (1<<PE2);
	
	//PORTE &= ~((1<<PE0)|(1<<PE4));
	DDRD = (1<<PORTD7);
	PORTD &= ~(1<<PORTD7); 
	
	//system leds
	DDRB |= (1<<PB0);
	PORTB &= ~(1<<PB0);
	
	delay = 650;
	cycles = 20;
	for (i = 0;i<cycles;i++)
	{
		PORTD |=(1<<PORTD7);
		_delay_us(delay);
		PORTD &= ~(1<<PORTD7);
		_delay_us(20000-delay);
	}
	
	
	
	cycles = 20;
	delay = 1500;
	for (i = 0;i<cycles;i++)
	{
		PORTD |=(1<<PORTD7);
		_delay_us(delay);
		PORTD &= ~(1<<PORTD7);
		_delay_us(20000-delay);
	}
	
	
	
	
	cycles=20;
	delay = 2400;
	for (i = 0;i<cycles;i++)
	{
		PORTD |=(1<<PORTD7);
		_delay_us(delay);
		PORTD &= ~(1<<PORTD7);
		_delay_us(20000-delay);
	}
	while(1)
	{
		
		PORTB &= ~(1<<PB0);
		_delay_ms(1000);
		PORTB |= (1<<PB0);
		_delay_ms(1000);
	}
}
