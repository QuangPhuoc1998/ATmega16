/*
 * Capture_AS7.c
 *
 * Created: 23/04/2019 11:03:56
 * Author : ADMIN
 */
#define RS eS_PORTC0
#define EN eS_PORTC1 
#define D4 eS_PORTC2
#define D5 eS_PORTC3
#define D6 eS_PORTC4
#define D7 eS_PORTC5
 
#include "main.h"
#include "lcd.h"


void Capture_Init();
int main(void)
{
  // bien
  uint32_t c = 0;
  uint32_t t = 0;
  // port
  DDRC = 0xFF;
  // chuong trinh con
  Capture_Init();
  Lcd4_Init();
  sei();
  // beign
  Lcd4_Write_String("Gia tri: ");
  Lcd4_Set_Cursor(2, 0);
  Lcd4_Write_String("Chu ky: ");
  while(1)
  {
    c = ICR1;  
	t = 60000000/(c*256*0.0625f*24);
	c = c*256*0.0625f;
	Lcd4_Set_Cursor(1, 10);
	Lcd4_Write_Char(c/10000+48);
	Lcd4_Write_Char((c%10000)/1000+48);
	Lcd4_Write_Char((c%1000)/100+48);
	Lcd4_Write_Char((c%100)/10+48);
	Lcd4_Write_Char(c%10+48);

	Lcd4_Set_Cursor(2, 9);
	Lcd4_Write_Char(t/10000+48);
	Lcd4_Write_Char((t%10000)/1000+48);
	Lcd4_Write_Char((t%1000)/100+48);
	Lcd4_Write_Char((t%100)/10+48);
	Lcd4_Write_Char(t%10+48);

	_delay_ms(10);
  }
}
void Capture_Init()
{
  cbi(DDRD, PD6);
  cbi(PORTD, PD6);
  TCNT1 = 0;
  TCCR1A = 0x00;
  TCCR1B |= (1<<ICES1)|(1<<CS12); // canh len. chia 256
  TIMSK |= (1<<TICIE1);
}
ISR (TIMER1_CAPT_vect) 
{
  TCNT1 = 0;
}


