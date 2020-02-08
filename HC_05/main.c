/*
 * HC_05.c
 *
 * Created: 6/22/2019 8:10:00 PM
 * Author : Admin
 */ 

#include "main.h"
#include "UART.h"
#include "avr/interrupt.h"


int main(void)
{
    // chuong trinh con
	sbi(DDRB, 0);
	UART_init(9600);
	sei();
    while (1) 
    {
    }
}
ISR (USART_RXC_vect)
{
	static unsigned char u;
	u = UART_RxChar();
	if(u == '1')
	{
		sbi(PORTB, 0);
	}
	if(u == '0')
	{
		cbi(PORTB, 0);
	}
}

