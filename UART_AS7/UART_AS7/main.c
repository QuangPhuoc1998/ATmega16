/*
 * UART_AS7.c
 *
 * Created: 30/04/2019 10:34:15
 * Author : ADMIN
 */ 

#include "main.h"
#include "UART.h"

void ADC_Init();
unsigned int Read_ADC(unsigned char channel);
int main(void)
{
  // bien
  unsigned int a, b;
  // port
  cbi(DDRA, PA0);
  // chuong trinh con
  ADC_Init();
  UART_init(9600);
  while(1)
  {
    a = Read_ADC(0);
	b = Read_ADC(1);
	UART_TxChar(':');
	_delay_us(10);
	UART_TxChar(a/1000);
	UART_TxChar(a%1000/100);
	UART_TxChar(a%100/10);
	UART_TxChar(a%10);
	_delay_ms(10);

	UART_TxChar(b/1000);
	UART_TxChar(b%1000/100);
	UART_TxChar(b%100/10);
	UART_TxChar(b%10);
	_delay_ms(10);
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

