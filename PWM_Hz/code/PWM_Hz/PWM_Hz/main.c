#define RS eS_PORTC0
#define EN eS_PORTC1
#define D4 eS_PORTC2
#define D5 eS_PORTC3
#define D6 eS_PORTC4
#define D7 eS_PORTC5

#include "main.h"
#include "lcd.h"


void PWM_Init();
void PWM_Duty(uint16_t duty);
void Capture_Init();
int main(void)
{
  sbi(DDRA, 0);
  sbi(DDRB, 3);
  PWM_Init();
  PWM_Duty(210);
  sei();
  while(1)
  {
	  
  }
}
void PWM_Init()
{
	// thanh ghi TCCR0
	TCCR0 = 0;
	// thanh ghi TCCR0
	TCNT0 = 200;
	TCCR0 |= (1<<WGM01)|(1<<WGM00)|(1<<COM01)|(1<<CS00);
}
void PWM_Duty(uint16_t duty)
{
	OCR0 = duty;
}
void Capture_Init()
{
	cbi(DDRD, PD6);
	cbi(PORTD, PD6);
	TCNT1 = 0;
	TCCR1A = 0x00;
	TCCR1B |= (1<<ICES1)|(1<<CS12); // canh len. chia 256
	TIMSK |= (1<<TICIE1);
}
ISR (TIMER1_CAPT_vect)
{
	TCNT1 = 0;
}
ISR(TIMER0_COMP_vect)
{
	TCNT1 = 200;
	OCR0 = 210;
	tbi(PORTA,0);
}
