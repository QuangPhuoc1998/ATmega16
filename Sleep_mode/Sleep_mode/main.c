/*
 * Sleep_mode.c
 *
 * Created: 10/20/2019 10:36:08 AM
 * Author : Admin
 */ 

#include "main.h"
#include <avr/interrupt.h>
#include <avr/sleep.h>

void Interrupt_Init();
int main(void)
{
	sbi(DDRA,0);
	sbi(DDRA,1);
	sbi(DDRA,2);
	DDRC = 0xFF;
	//
	Interrupt_Init();
	//
	set_sleep_mode(SLEEP_MODE_IDLE);
	cli();
	sei();
	sleep_mode();
	while(1)
	{
		PORTC = 0xAA;
		_delay_ms(500);
		PORTC = 0x55;
		_delay_ms(500);
		sleep_mode();
	}
}
void Interrupt_Init()
{
	// thanh ghi MCUCR
	MCUCR |= (1<<ISC01)|~(1<<ISC00)|(1<<ISC11)|~(1<<ISC10); // canh xuong
	MCUCSR |= (1<<ISC2); // canh xuong cho INT2
	// thanh ghi GICF
	GICR |= (1<<INT0)|(1<<INT1)|(1<<INT2); // cho phep ngat 3 ngat ngoai
}
ISR(INT0_vect)
{
	tbi(PORTA,0);
}
ISR(INT1_vect)
{
	tbi(PORTA,1);
}
ISR(INT2_vect)
{
	tbi(PORTA,2);
	sleep_disable();
}

