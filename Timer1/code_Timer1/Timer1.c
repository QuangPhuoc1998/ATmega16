/*
 * Timer1.c
 *
 * Created: 17/04/2019 20:58:12
 * Author: ADMIN
 */

#include <main.h>
#include <lcd.h>
#include <delay.h>

void Timer1_Init();
void main(void)
{
// khai bao bien

// cau hinh port
DDRC = 0xFF;
DDRB.0 = 1;
// chuong trinh con
lcd_init(16);
Timer1_Init();
#asm
.equ __lcd_port = 0x15;
#endasm
#asm ("sei")
// begin
lcd_puts("hello");
while (1)
    {
      
    }
}
void Timer1_Init()
{
  TCNT1 = 33536;
  TCCR1A = 0x00;
  TCCR1B |= (1<<CS10);
  TIMSK |= (1<<TOIE1);   
}
interrupt [TIM1_OVF] void tim1_ovf_isr(void)
{
  TCNT1 = 33536;
  PORTB.0 = !PORTB.0;
}
