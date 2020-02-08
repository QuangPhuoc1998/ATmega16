/*
 * ADC_AS7.c
 *
 * Created: 23/04/2019 11:48:55
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
int main(void)
{
  float x;
  char data[5];
  // port
  DDRC = 0xFF;
  cbi(DDRA, PA0);
  // chuong trinh con
  ADC_Init();
  Lcd4_Init();
  // beign
  Lcd4_Write_String("x = ");
  Lcd4_Set_Cursor(2,0);
  Lcd4_Write_String("y = ");
  while(1)
  {
    x = (float)Read_ADC(0)*0.488f+0.5f;
	dtostrf(x,4,2,data);
	Lcd4_Set_Cursor(1,4);
	Lcd4_Write_String(data);
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
    ADMUX &= 0xE0;
	ADMUX |= channel;
	_delay_ms(2);
	ADCSRA |= (1<<ADSC); // cho phep bat dau chuyen doi
	while(ADIF==0);
	ADCSRA |= (1<<ADIF);
	return ADCW;
}

