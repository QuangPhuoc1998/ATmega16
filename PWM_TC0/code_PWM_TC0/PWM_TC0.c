/*
 * PWM_TC0.c
 *
 * Created: 17/04/2019 10:30:55
 * Author: ADMIN
 */

#include "main.h"
#include "lcd4.h"

void PWM_Init(unsigned int duty);
void main(void)
{
DDRB.3 = 1;
DDRC.0 = 1;
DDRC.1 = 1;
DDRC.2 = 1;
DDRC.3 = 1;
DDRC.4 = 1;
DDRC.5 = 1;
// chuong trinh con
Lcd_Init();
PWM_Init(0);
// begin
Lcd_Write_String("Gia tri: ");
while (1)
    {
      
    }
}
void PWM_Init(unsigned int duty)
{
  duty = duty*255/100;
  // thanh ghi TCCR0
  TCCR0 = 0;
  // thanh ghi TCCR0
  TCCR0 |= (1<<WGM01)|(1<<WGM00)|(1<<COM01)|(1<<CS02);
  OCR0 = duty;
}
