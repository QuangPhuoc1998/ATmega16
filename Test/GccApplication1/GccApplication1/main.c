/*
 * GccApplication1.c
 *
 * Created: 5/18/2019 9:01:04 PM
 * Author : Admin
 */ 

#include "main.h"


int main(void)
{
	DDRA = 0xFF;
	DDRB = 0xFF;
	DDRC = 0xFF;
	DDRD = 0xFF;
    while (1) 
    {
		PORTA = PORTB = PORTC = PORTD = 0x55;
		_delay_ms(500);
		PORTA = PORTB = PORTC = PORTD = 0xAA;
		_delay_ms(500);
    }
}

