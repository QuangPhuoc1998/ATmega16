/*
 * interrupt.c
 *
 * Created: 12/04/2019 21:42:02
 * Author: ADMIN
 */

#include <mega16.h>
#include <delay.h>


void Interrupt_Init();
void main(void)
{
// cau hinh port
DDRC.0 = 1;
DDRC.1 = 1;
DDRC.2 = 1;
DDRD.2 = 0;
DDRD.3 = 0;
DDRB.2 = 0;
// chuong trinh con
Interrupt_Init();
#asm ("sei");
// chuong trinh chinh
while (1)
    {
    }
}
void Interrupt_Init()
{
  // thanh ghi MCUCR
  MCUCR |= (1<<ISC01)|~(1<<ISC00)|(1<<ISC11)|~(1<<ISC10); // canh xuong
  MCUCSR |= (1<<ISC2); // canh xuong cho INT2
  // thanh ghi GICF
  GICR |= (1<<INT0)|(1<<INT1)|(1<<INT2); // cho phep ngat 3 ngat ngoai
}
interrupt [EXT_INT0] void ext_int0_isr(void)
{
  PORTC.0 = !PORTC.0;  
}
interrupt [EXT_INT1] void ext_int1_isr(void)
{
  PORTC.1 = !PORTC.1;  
}
interrupt [EXT_INT2] void ext_int2_isr(void)
{
  PORTC.2 = !PORTC.2;  
}
