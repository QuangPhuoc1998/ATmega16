/*
 * phone.c
 *
 * Created: 6/22/2019 8:27:09 PM
 * Author : Admin
 */ 

#include "main.h"
#include "UART.h"

int main(void)
{
	UART_init(9600);
    cbi(DDRB, 0);
	cbi(DDRB, 1);
    while (1) 
    {
		if(bit_is_clear(PINB, 0))
		{
			while(bit_is_clear(PINB, 0));
			UART_TxChar('1');
		}
		if(bit_is_clear(PINB, 1))
		{
			while(bit_is_clear(PINB, 1));
			UART_TxChar('0');
		}
    }
}

