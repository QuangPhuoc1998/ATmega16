/*
 * RTOS.c
 *
 * Created: 6/16/2019 8:22:50 PM
 * Author : Admin
 */ 

#include "main.h"
#include <avr/interrupt.h>

void Timer0_init();
void task1_100ms();
void task2_200ms();
void task3_300ms();
void task4_400ms();
int main(void)
{
	//
	DDRD = 0xFF;
	//
	Timer0_init();
    sei();
    while (1) 
    {
		
    }
}
void Timer0_init()
{
	TCCR0 |= (1<<CS02)|(1<<CS00); // chia 1024
	TCNT0 = 100; // delay 10ms
	TIMSK |= (1<<TOIE0); // cho phep ngat
}
void task1_100ms()
{
	tbi(PORTD,0);
}
void task2_200ms()
{
	tbi(PORTD,1);
}
void task3_300ms()
{
	tbi(PORTD,2);
}
void task4_400ms()
{
	tbi(PORTD,3);
}
ISR (TIMER0_OVF_vect)
{
	static uint8_t t1, t2, t3, t4;
	// task 1
	if(t1<10)
	{
		t1++;
	}
	else
	{
		task1_100ms();
		t1 = 0;
	}
	// task 2
	if(t2<20)
	{
		t2++;
	}
	else
	{
		task2_200ms();
		t2 = 0;
	}
	// task 3
	if(t3<30)
	{
		t3++;
	}
	else
	{
		task3_300ms();
		t3 = 0;
	}
	// task 4
	if(t4<40)
	{
		t4++;
	}
	else
	{
		task4_400ms();
		t4 = 0;
	}
	TCNT0 = 100;
}

