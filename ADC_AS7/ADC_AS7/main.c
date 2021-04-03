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

float in[] = { 100.00, 100.39, 100.78, 101.17, 101.56, 101.95, 102.34, 102.73, 103.12, 103.51,
	103.90, 104.29, 104.68, 105.07, 105.46, 105.85, 106.24, 106.63, 107.02, 107.40,
	107.79, 108.18, 108.57, 108.96, 109.35, 109.73, 110.12, 110.51, 110.90, 111.29,
	111.67, 112.06, 112.45, 112.83, 113.22, 113.61, 114.00, 114.38, 114.77, 115.15,
	115.54, 115.93, 116.31, 116.70, 117.08, 117.47, 117.86, 118.24, 118.63, 119.01,
	119.40, 119.78, 120.17, 120.55, 120.94, 121.32, 121.71, 122.09, 122.47, 122.86,
	123.24, 123.63, 124.01, 124.39, 124.78, 125.16, 125.54, 125.93, 126.31, 126.69,
127.08, 127.46, 127.84, 128.22, 128.61, 128.99, 129.37, 129.75, 130.13, 130.52 };
int R1 = 217;

void ADC_Init();
unsigned int Read_ADC(unsigned char channel);
float MultiMap(float val, float* _in, uint8_t size);

int main(void)
{
  int x;
  char data[5];
  float Vout, R2,c;
  // port
  DDRC = 0xFF;
  cbi(DDRA, PA0);
  // chuong trinh con
  ADC_Init();
  Lcd4_Init();
  // beign
  Lcd4_Write_String("x = ");
  while(1)
  {
	x = Read_ADC(0);

	Vout = x * (5.0 / 1023.0);
	R2 = R1 * 1/(5.0/Vout - 1);
	c =  MultiMap(R2,in,80);
/*
	float Vout = pt100 * (5.0 / 1023.0);
	float R2 = R1 * 1/(5.0/Vout - 1);

	float 
    */
	dtostrf(c,4,4,data);
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
float MultiMap(float val, float* _in, uint8_t size)
{
	// calculate if value is out of range
	if (val < _in[0] ) return -99.99;
	if (val > _in[size-1] ) return 99.99;

	//  search for 'value' in _in array to get the position No.
	uint8_t pos = 0;
	while(val > _in[pos]) pos++;

	// handles the 'rare' equality case
	if (val == _in[pos]) return pos;

	float r1 = _in[pos-1];
	float r2 = _in[pos];
	int c1 = pos-1;
	int c2 = pos;

	return c1 + (val - r1) / (r2-r1) * (c2-c1);
}
