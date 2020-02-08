/*
 * Timer0.c
 *
 * Created: 12/04/2019 22:08:22
 * Author: ADMIN
 */

#include <mega16.h>

void Timer0_Init();
void main(void)
{
// cau hinh port
DDRC.0 = 1;
DDRB = 0xFF;
PORTB = 0x55;
// chuong trinh con
Timer0_Init();
#asm ("sei")
while (1)
    {
    // Please write your application code here

    }
}
void Timer0_Init()
{
  // thanh ghi TCNT0
  TCCR0 = (1<<CS01); // chia 8   
  // nap gia tri
  TCNT0 = 56; // 100us
  // thanh ghi TIMSK
  TIMSK = (1<<TOIE0); // cho phep ngat timer 0 
  
}
interrupt [TIM0_OVF] void tim0_ovf_isr(void)
{
  TCNT0 = 56;
  PORTC.0 = ~PORTC.0;
}
