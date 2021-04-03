/*
 * Test_HIQ.c
 *
 * Created: 3/3/2021 12:24:19 PM
 * Author : phuoc
 */ 

#include "main.h"

volatile uint16_t sec = 0;

void Interrupt_Init();
void Timer1_Init();
int main(void)
{
	DDRA = 0xFF;
	/*---*/
	Interrupt_Init();
	Timer1_Init();
	sei();
	while (1)
	{
		
	}
}
void Interrupt_Init()
{
	// thanh ghi MCUCR
	MCUCR |= (1<<ISC01)|~(1<<ISC00); // canh xuong
	// thanh ghi GICF
	GICR |= (1<<INT0); // cho phep ngat 3 ngat ngoai
}
ISR(INT0_vect)
{
	tbi(PORTA, 1);
	if(bit_is_clear(PIND, 2))
	{
		MCUCR |= (1<<ISC01)|(1<<ISC00); // canh xuong
		sbi(PORTA, 0);
		TCCR1B |= (1<<CS10);
	} else
	{
		MCUCR |= (1<<ISC01); // canh xuong
		MCUCR &= (0<<ISC00);
		cbi(PORTA, 0);
		TCCR1B &= (0<<CS10);
		
		if(sec <= 2000)
		{
			tbi(PORTA, 5);
		}
		else if(sec > 2000 && sec < 5000)
		{
			tbi(PORTA, 6);
		} else if(sec > 5000)
		{
			tbi(PORTA, 7);
		}
		sec = 0;
	}
}
ISR(TIMER1_OVF_vect)
{
	TCNT1 = 49536;
	tbi(PORTA, 2);
	sec++;
}
void Timer1_Init()
{
	TCNT1 = 49536;
	TCCR1A = 0x00;
	TIMSK |= (1<<TOIE1);
}
/*
if(bit_is_clear(PINA, 0))
{
	while(bit_is_clear(PINA, 0))
	{
		Lcd4_Set_Cursor(1,7);
		Lcd4_Write_Char(count/10000+48);
		Lcd4_Write_Char(count%10000/1000+48);
		Lcd4_Write_Char(count%1000/100+48);
		Lcd4_Write_Char(count%100/10+48);
		Lcd4_Write_Char(count%10+48);
		_delay_ms(1);
		count++;
	}
	if(count > 10 && count < 100)
	{
		tbi(PORTB, 0);
	} else if(count > 500 && count < 1000)
	{
		tbi(PORTB, 1);
	} else if(count > 1000)
	{
		tbi(PORTB, 2);
	} else tbi(PORTB, 7);
	count = 0;
}
*/

/*
if(bit_is_clear(PINA, 0))
{
	if(pressed == 0)
	{
		tbi(PORTB, 0);
		tbi(PORTB, 1);
		pressed = 1;
	}
}
else
{
	pressed = 0;
}
*/

/*
int pressed = 0;
int pressed_confidence_level = 0;
int reseased_confidence_level = 0;
while (1)
{
	if(bit_is_clear(PINA, 0))
	{	
		pressed_confidence_level++;
		if(pressed_confidence_level > 200)
		{
			if(pressed == 0)
			{
				tbi(PORTB, 0);
				tbi(PORTB, 1);
				pressed = 1;
			}
			pressed_confidence_level = 0;
		}
	}
	else
	{
		reseased_confidence_level++;
		if(reseased_confidence_level > 200)
		{
			pressed = 0;
			reseased_confidence_level = 0;
		}
	}
}
*/

