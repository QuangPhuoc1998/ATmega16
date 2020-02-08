/*
 * DKDC_AS7.c
 *
 * Created: 23/04/2019 12:03:01
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

// khai bao bien PID
double E, E1, E2, T;
double a1, a2, a3, Kp, Ki, Kd;
double out, pre_out, chot;

void PWM_Init();
void PWM_Duty(uint16_t duty);
void Capture_Init();
uint16_t PID_Init(unsigned int tocdo, unsigned int tocdodat);
int main(void)
{
	// gan gia tri bien PID
	T = 0.01;
	Kp = 14.28005;
	Ki = 0.0055;
	Kd = 0.0001;
	E = E1 = E2 = 0;
	a1 = a2 = a3 = 0;
	out = pre_out = 0;	
  //bien
  uint32_t c, t, m;
  // port
  sbi(DDRB, PB3);
  DDRC = 0xFF;
  // chuong trinh con
  Lcd4_Init();
  PWM_Init();
  Capture_Init();
  sei();
  // begin
  Lcd4_Write_String("Toc do dat: ");
  Lcd4_Set_Cursor(2, 0);
  Lcd4_Write_String("Toc do: ");
  m = 100;
  while(1)
  {
	//
	c = ICR1;
	t = 60000000/(c*256*0.0625f*24);
	
	PWM_Duty(PID_Init(t, m));
	Lcd4_Set_Cursor(2, 8);
	Lcd4_Write_Char(t/10000+48);
	Lcd4_Write_Char((t%10000)/1000+48);
	Lcd4_Write_Char((t%1000)/100+48);
	Lcd4_Write_Char((t%100)/10+48);
	Lcd4_Write_Char(t%10+48);
	
	Lcd4_Set_Cursor(1, 12);
	Lcd4_Write_Char(m/100+48);
	Lcd4_Write_Char((m%100)/10+48);
	Lcd4_Write_Char(m%10+48);
	
	_delay_ms(10);
  }
}
void PWM_Init()
{
  // thanh ghi TCCR0
  TCCR0 = 0;
  // thanh ghi TCCR0
  TCCR0 |= (1<<WGM01)|(1<<WGM00)|(1<<COM01)|(1<<CS02)|(1<<CS00);
}
void PWM_Duty(uint16_t duty)
{
  OCR0 = duty*255/100;
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
uint16_t PID_Init(unsigned int tocdo, unsigned int tocdodat)
{
	E = tocdodat-tocdo;
	a1 = Kp + (Ki*T)/2 + Kd/2;
	a2 = -Kp + (Ki*T)/2 - 2*Kd/T;
	a3 = Kd/T;
	out = pre_out + E*a1 + E1*a2 + E2*a3;
	pre_out = out;
	E2 = E1;
	E1 = E;
	if(out >= 100) out = 100;
	if(out <= 50) out = 50;
	return out;
}