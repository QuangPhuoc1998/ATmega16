/*
 * SPI_P1.c
 *
 * Created: 30/04/2019 23:24:26
 * Author : ADMIN
 */ 

#include "main.h"
#include "SPI.h"

void ADC_Init();
unsigned int Read_ADC(unsigned char channel);
int main(void)
{
  unsigned int a, b;
  // port
  cbi(DDRA, PA0);
  cbi(DDRA, PA1);
  // chuong trinh conn
  Spi_Init_Master();
  ADC_Init();
  _delay_ms(500);
  while(1)
  {
    a =  Read_ADC(0);
	b =  Read_ADC(1);
    Spi_Write(':');
	_delay_us(10);
	Spi_Write(a/1000);
	Spi_Write(a%1000/100);
	Spi_Write(a%100/10);
	Spi_Write(a%10);
	Spi_Write(b/1000);
	Spi_Write(b%1000/100);
	Spi_Write(b%100/10);
	Spi_Write(b%10);
	_delay_ms(50);
  }
}void ADC_Init()
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


