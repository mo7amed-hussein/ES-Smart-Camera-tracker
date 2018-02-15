/*
 * soft_uart_test.c
 *
 * Created: 2/15/2018 10:53:03 AM
 *  Author: mohamed
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include "uart/softuart.h"
int main(void)
{
	//system leds
	DDRB |= (1<<PB0);
	PORTB &= ~(1<<PB0);
	
	//init softuart
	softuart_init();
	sei();
	
	softuart_puts("software uart test start...\n");
	char ch = 'A';
    while(1)
    {
        //TODO:: Please write your application code 
		PORTB &= ~(1<<PB0);
		_delay_ms(1000);
		PORTB |= (1<<PB0);
		_delay_ms(1000);
		softuart_putchar(ch);
		ch++;
    }
}