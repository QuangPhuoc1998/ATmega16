/*
 * ADC.c
 *
 * Created: 12/04/2019 20:44:02
 * Author: ADMIN
 */

#include "main.h"
#include "lcd4.h"

void ADC_Init();
unsigned int Read_ADC(unsigned char channel);
void main(void)
{
// khai bao bien
unsigned int a, t;
// cau hinh port
DDRB.0 = 1;
DDRB.1 = 1;
DDRB.2 = 1;
DDRB.3 = 1;
DDRB.4 = 1;
DDRB.5 = 1;
// chuong trinh con
Lcd_Init();
ADC_Init();
// chuong trinh chinh
Lcd_Write_String("Gia tri: ");
Lcd_Set_Cursor(2,1);
Lcd_Write_String("Nhiet do: ");
while (1)
    {
      a = Read_ADC(0); 
      t = a*0.488f;      
      // gia tri
      Lcd_Set_Cursor(1,10);
      Lcd_Write_Char(a/1000+48);   
      Lcd_Write_Char((a%1000)/100+48);
      Lcd_Write_Char((a%100)/10+48);
      Lcd_Write_Char(a%10+48);
      // nhiet do  
      Lcd_Set_Cursor(2,11);
      Lcd_Write_Char((t%100)/10+48);
      Lcd_Write_Char(t%10+48);
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
  delay_us(10);
  ADCSRA |= (1<<ADSC); // cho phep bat dau chuyen doi
  while(ADIF==0);
  ADCSRA |= (1<<ADIF);
  return ADCW;
}

