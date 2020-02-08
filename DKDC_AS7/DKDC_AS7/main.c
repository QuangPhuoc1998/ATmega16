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

void ADC_Init();
unsigned int Read_ADC(unsigned char channel);
void PWM_Init();
void PWM_Duty(uint16_t duty);
void Capture_Init();
int main(void)
{
  //bien
  uint32_t a, duty, c, t;
  // port
  sbi(DDRB, PB3);
  DDRC = 0xFF;
  cbi(DDRA, PA0);
  // chuong trinh con
  ADC_Init();
  Lcd4_Init();
  PWM_Init();
  Capture_Init();
  sei();
  // begin
  Lcd4_Write_String("Duty: ");
  Lcd4_Set_Cursor(2, 0);
  Lcd4_Write_String("Toc do: ");
  while(1)
  {
    a = Read_ADC(0);
	duty = a*100/1024;
	//
	c = ICR1;
	t = 60000000/(c*256*0.0625f*24);
	if(t<10) t = 0;
	//
	PWM_Duty(duty);
	Lcd4_Set_Cursor(1, 6);
	Lcd4_Write_Char(duty/100+48);
	Lcd4_Write_Char((duty%100)/10+48);
	Lcd4_Write_Char(duty%10+48);

	Lcd4_Set_Cursor(2, 9);
	Lcd4_Write_Char(t/10000+48);
	Lcd4_Write_Char((t%10000)/1000+48);
	Lcd4_Write_Char((t%1000)/100+48);
	Lcd4_Write_Char((t%100)/10+48);
	Lcd4_Write_Char(t%10+48);
  }
}
void ADC_Init()
{
	// thanh ghi ADMUX
	ADMUX |= (1<<REFS0); // dien ap: AVCC, ADCL chua 8 bit thap
	// thanh ghi ADCSRA
	ADCSRA |= (1<<ADEN)|(1<<ADPS2)|(1<<ADPS1)|(ADPS0); // cho phep ADC, chia 128
}
unsigned int Read_ADC(unsigned char channel)
{
	ADMUX |= channel;
	_delay_us(10);
	ADCSRA |= (1<<ADSC); // cho phep bat dau chuyen doi
	while(ADIF==0);
	ADCSRA |= (1<<ADIF);
	return ADCW;
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
  OCR0 = duty*256/100;
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
