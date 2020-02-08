/*
 * LCD.c
 *
 * Created: 11/04/2019 22:37:32
 * Author: ADMIN
 */

#include <main.h>
#include "lcd4.h"

void PWM_Init();
void main(void)
{
DDRB = 0xFF;
DDRD.4 = 1;
PORTD.4 = 1;
DDRD.5 = 1;
PORTD.5 = 1;
// chuong trinh con
Lcd_Init();
PWM_Init();
#asm ("sei");
//begin
Lcd_Write_String("hello");
while (1)
    {
    // Please write your application code here

    }
}
void PWM_Init()
{
   MCUCR|=(1<<ISC11)|(1<<ISC01); //ngat canh xuong
   GICR |=((1<<INT1)|(1<<INT0)); //cho phép 2 ngat hoat dong 

   TCCR1A=(1<<COM1A1)|(1<<COM1B1)|(1<<WGM11);
   TCCR1B=(1<<WGM13)|(1<<WGM12)|(1<<CS10);
   
   OCR1A=1000;              //Duty cycle servo1=1000us=1ms (0 degree)
   OCR1B=1500;              //Duty cycle servo2=1500us=1.5ms (90 degree)
   ICR1H=0x4E;                  //Time period = 20000us=20ms 
   ICR1L=0x20;
}