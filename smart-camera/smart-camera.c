/*
 * bluetooth_test.c
 *
 * Created: 2/15/2018 11:28:51 AM
 *  Author: mohamed
 */ 

#define F_CPU 16000000ul
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include "servo/servo.h"
//#include "servo/pantilt.h"
#include "bluetooth/bluetooth.h"

extern uint8_t currentPanAngle ;
extern uint8_t currentTiltAngle ;
int main(void)
{
	//system leds
	DDRB =0xff;
	PORTB = 0x00;
	initBluetooth();
	initPanTilt();
	sei();
    while(1)
    {
        //TODO:: Please write your application code
		PORTB &= ~(1<<PB0);
		_delay_ms(500);
		PORTB |= (1<<PB0);
		_delay_ms(500);
    }
}

ISR(USART_RX_vect)
{
	char ch = UDR0;
	switch(ch)
	{
		case 'F' :
		PORTB |= (1<<PB1);
		_delay_ms(100);
		PORTB &= ~(1<<PB1);
		moveUp();
		break;
		case 'B':
		PORTB |= (1<<PB2);
		_delay_ms(100);
		PORTB &= ~(1<<PB2);
		moveDown();
		break;
		case 'L':
		PORTB |= (1<<PB3);
		_delay_ms(100);
		PORTB &= ~(1<<PB3);
		moveLeft();
		break;
		case 'R':
		PORTB |= (1<<PB4);
		_delay_ms(100);
		PORTB &= ~(1<<PB4);
		moveRight();
		break;
	}
}