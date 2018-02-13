#ifndef _USART
#define _USART
#include <avr/io.h>

#define       FCLK_SYSTEM     16000000UL

/*
	initialize usart0 
	@param baudrate uart baudrate
*/
void initUsart0(unsigned short baudrate);

/*
	transmit character over usart0
	@param ch character to be send
*/
void putcUsart0(unsigned char data);

/*
	read character from usart0 [sync]
	@return  recieved character
*/
unsigned char getcUsart0(void);

/*
	transmit string over usart0
	@param str string to be send
*/
void putsUsart0(char *str);

#endif