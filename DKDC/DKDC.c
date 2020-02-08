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
void PWM_Init();
void PWM_Duty(unsigned char duty);
void Capture_Init();
void main(void)
{
// khai bao bien
unsigned int c, cL, cH;
unsigned int vL, vH;
unsigned long int v, V;
//_______
unsigned long int a;
//_______
// cau hinh port
DDRA.0 = 0; // channel ADC
DDRB.3 = 1; // channel PWM
DDRC.0 = 1;
DDRC.1 = 1;
DDRC.2 = 1;
DDRC.3 = 1;
DDRC.4 = 1;
DDRC.5 = 1;
// chuong trinh con
Lcd_Init();
ADC_Init();
PWM_Init();
Capture_Init();
#asm ("sei");
// chuong trinh chinh
Lcd_Write_String("Gia tri: ");
Lcd_Set_Cursor(2,1);
Lcd_Write_String("Toc do: ");
while (1)
    {
      a = Read_ADC(0); 
      a = a*100/1023;
      PWM_Duty(a);
      // capture   
      cH = ICR1H;
      cL = ICR1L; 
      c = (cH<<8)+cL; 
      vL = cL*256*0.0625f;
      vH = cH*256*0.0625f;
      V = (vH<<8)+vL;
      v = 60000000/(V*24);
      //--------------         
      // gia tri
      Lcd_Set_Cursor(1,10);
      Lcd_Write_Char(a/1000+48);   
      Lcd_Write_Char((a%1000)/100+48);
      Lcd_Write_Char((a%100)/10+48);
      Lcd_Write_Char(a%10+48);
      // toc do
      Lcd_Set_Cursor(2, 9);
      Lcd_Write_Char(v/10000+48);
      Lcd_Write_Char((v%10000)/1000+48);
      Lcd_Write_Char((v%1000)/100+48);
      Lcd_Write_Char((v%100)/10+48);
      Lcd_Write_Char(v%10+48);  
      delay_ms(1);
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
void PWM_Init()
{
  // thanh ghi TCCR0
  TCCR0 = 0;
  // thanh ghi TCCR0
  TCCR0 |= (1<<WGM01)|(1<<WGM00)|(1<<COM01)|(1<<CS02)|(1<<CS00); // 1024
  OCR0 = 0;
}
void PWM_Duty(unsigned char duty)
{
  duty = duty*255/100;
  OCR0 = duty;  
}
void Capture_Init()
{
  DDRD.6 = 0;
  PORTD.6 = 0;
  TCNT1 = 0;
  TCCR1A = 0x00;
  TCCR1B |= (1<<ICNC1)|(1<<ICES1)|(1<<CS12);
  TIMSK |= (1<<TICIE1);            
}
interrupt [TIM1_CAPT] void tim1_capt_isr(void)
{
  TCNT1 = 0; 
}

