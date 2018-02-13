/*
 * uart_test.c
 *
 * Created: 2/13/2018 1:51:44 PM
 *  Author: mohamed
 */ 


#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include "uart/usart0.h"

int main(void)
{
	
	//init uart
	initUsart0(9600);
	
	putsUsart0("uart test starts...\n");
    while(1)
    {
        //TODO:: Please write your application code 
		putsUsart0("uart test ..\n");
		_delay_ms(1000);
    }
}