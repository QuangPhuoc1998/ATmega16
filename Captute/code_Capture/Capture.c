/*
 * Capture.c
 *
 * Created: 18/04/2019 20:31:49
 * Author: ADMIN
 */

#include <mega16.h>
#include <delay.h>
#include <lcd.h>

unsigned long int over_step, period;
void Capture_Init();
void main(void)
{
// bien

//--------

// cau hinh port
#asm
.equ __lcd_port = 0x15;
#endasm
// chuong trinh con
Capture_Init();
lcd_init(16);
#asm ("sei");
// begin
lcd_puts("Gia tri: ");
while (1)
    {   
      lcd_gotoxy(9, 0);
      lcd_putchar(period/100000+48); 
    }
}
void Capture_Init()
{
  DDRD.6 = 0;
  PORTD.6 = 0;
  TCNT1 = 0;
  TCCR1A = 0x00;
  TCCR1B |= (1<<ICES1)|(1<<CS10); // canh xuong, chia 1
  TIMSK |= (1<<TICIE1)|(1<<TOIE1);            
}
interrupt [TIM1_OVF] void tim1_ovf_isr(void)
{
  over_step += 0xFFFF;
}
interrupt [TIM1_CAPT] void tim1_capt_isr(void)
{
  period = over_step + ((long int)ICR1H*256+ICR1L);
  TCNT1 = 0;
}
