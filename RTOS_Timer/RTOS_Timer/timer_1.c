#include "timer_1.h"

void timer1_init(void)
{
	TCNT1 = 49536;
	TCCR1A = 0x00;
	TCCR1B |= (1<<CS10);
	TIMSK |= (1<<TOIE1);
}