/*
 * DKDC_AS7.c
 *
 * Created: 23/04/2019 12:03:01
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

/*---khai bao bien PID---*/
double E, E1, E2, T;
double a1, a2, a3;
double out, pre_out, chot;
/*---typer---*/
typedef struct 
{
	float NL;
	float NM;
	float NS;
	float ZE;
	float PS;
	float PM;
	float PL;
} input;
typedef struct
{
	float NL;
	float NM;
	float NS;
	float ZE;
	float PS;
	float PM;
	float PL;
} output;
typedef struct midro_
{
	float NL;
	float NM;
	float NS;
	float ZE;
	float PS;
	float PM;
	float PL;
} midro;
midro Kp_micro;
/*---function---*/
void PWM_Init();
void PWM_Duty(uint16_t duty);
void Capture_Init();
double PID_Init(unsigned int tocdo, unsigned int tocdodat,double Kp, double Ki, double Kd);
double Fuzzy(unsigned int tocdo, unsigned int tocdodat,input *Error, midro *Kp_micro, output *duty);
/*---MAIN---*/
int main(void)
{
	/*---variable---*/
	input Error;
		Error.PL = -7.5;
		Error.PM = -5;
		Error.PS = -2.5;
		Error.ZE = 0;
		Error.NS = 2.5;
		Error.NM = 5;
		Error.NL = 7.5;
	output duty;
		duty.PL = 40;
		duty.PM = 50;
		duty.PS = 60;
		duty.ZE = 70;
		duty.NS = 80;
		duty.NM = 90;
		duty.NL = 100;
	/*---variable PID---*/
	T = 0.01;
	E = E1 = E2 = 0;
	a1 = a2 = a3 = 0;
	out = pre_out = 0;	
  /*---variable speed---*/
  uint32_t c, t, m;
  /*---port---*/
  sbi(DDRB, PB3);
  DDRC = 0xFF;
  /*---chuong trinh con---*/
  Lcd4_Init();
  PWM_Init();
  Capture_Init();
  sei();
  /*---begin---*/
  Lcd4_Write_String("Toc do dat: ");
  Lcd4_Set_Cursor(2, 0);
  Lcd4_Write_String("Toc do: ");
  m = 80;
  while(1)
  {
	//
	c = ICR1;
	t = 60000000/(c*256*0.0625f*24);
	
	PWM_Duty(Fuzzy(t,m,&Error, &Kp_micro, &duty));
	Lcd4_Set_Cursor(2, 8);
	Lcd4_Write_Char(t/10000+48);
	Lcd4_Write_Char((t%10000)/1000+48);
	Lcd4_Write_Char((t%1000)/100+48);
	Lcd4_Write_Char((t%100)/10+48);
	Lcd4_Write_Char(t%10+48);
	
	Lcd4_Set_Cursor(1, 12);
	Lcd4_Write_Char(m/100+48);
	Lcd4_Write_Char((m%100)/10+48);
	Lcd4_Write_Char(m%10+48);
	
	_delay_ms(10);
  }
}
void PWM_Init()
{
  // thanh ghi TCCR0
  TCCR0 = 0;
  // thanh ghi TCCR0
  TCCR0 |= (1<<WGM01)|(1<<WGM00)|(1<<COM01)|(1<<CS02)|(1<<CS00);
}
void PWM_Duty(uint16_t duty)
{
  OCR0 = duty*255/100;
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
double PID_Init(unsigned int tocdo, unsigned int tocdodat,double Kp, double Ki, double Kd)
{
	E = tocdodat-tocdo;
	a1 = Kp + (Ki*T)/2 + Kd/2;
	a2 = -Kp + (Ki*T)/2 - 2*Kd/T;
	a3 = Kd/T;
	out = pre_out + E*a1 + E1*a2 + E2*a3;
	pre_out = out;
	E2 = E1;
	E1 = E;
	if(out >= 100) out = 100;
	//if(out <= 50) out = 50;
	return out;
}
double Fuzzy(unsigned int tocdo, unsigned int tocdodat,input *Error, midro *Kp_micro, output *duty)
{
	E = tocdodat-tocdo;
	/*-NL-*/
	(E <= Error->NL) ? Kp_micro->NL = 1 :
	(E > Error->NL && E < Error->NM)? Kp_micro->NL = (Error->NM-E)/(Error->NM-Error->NL):
	(E >= Error->NM)? Kp_micro->NL = 0:0;
	/*-NM-*/
	(E <= Error->NL)? Kp_micro->NM = 0:
	(E > Error->NL && E <= Error->NM)? Kp_micro->NM = (E-Error->NL)/(Error->NM-Error->NL):
	(E > Error->NM && E < Error->NS)? Kp_micro->NM = (Error->NS-E)/(Error->NS-Error->NM):
	(E >= Error->NS)? Kp_micro->NM = 0:0;
	/*-NS-*/
	(E <= Error->NM)? Kp_micro->NS = 0:
	(E > Error->NM && E <= Error->NS)? Kp_micro->NS = (E-Error->NM)/(Error->NS-Error->NM):
	(E > Error->NS && E < Error->ZE)? Kp_micro->NS = (Error->ZE-E)/(Error->ZE-Error->NS):
	(E >= Error->ZE)? Kp_micro->NS = 0:0;
	/*-ZE-*/
	(E <= Error->NS)? Kp_micro->ZE = 0:
	(E > Error->NS && E <= Error->ZE)? Kp_micro->ZE = (E-Error->NS)/(Error->ZE-Error->NS):
	(E > Error->ZE && E < Error->PS)? Kp_micro->ZE = (Error->PS-E)/(Error->PS-Error->ZE):
	(E >= Error->PS)? Kp_micro->ZE = 0:0;
	/*-PS-*/
	(E <= Error->ZE)? Kp_micro->PS = 0:
	(E > Error->ZE && E <= Error->PS)? Kp_micro->PS = (E-Error->ZE)/(Error->PS-Error->ZE):
	(E > Error->PS && E < Error->PM)? Kp_micro->PS = (Error->PM-E)/(Error->PM-Error->PS):
	(E >= Error->PM)? Kp_micro->PS = 0:0;
	/*-PM-*/
	(E <= Error->PS)? Kp_micro->PM = 0:
	(E > Error->PS && E <= Error->PM)? Kp_micro->PM = (E-Error->PS)/(Error->PM-Error->PS):
	(E > Error->PM && E < Error->PL)? Kp_micro->PM = (Error->PL-E)/(Error->PL-Error->PM):
	(E >= Error->PL)? Kp_micro->PM = 0:0;
	/*-PL-*/
	(E <= Error->PM)? Kp_micro->PL = 0:
	(E > Error->PM && E < Error->PL)? Kp_micro->PL = (E-Error->PM)/(Error->PL-Error->PM):
	(E >= Error->PL)? Kp_micro->PL = 1:0;
	/*---*/
	return  (Kp_micro->NL*duty->NL + Kp_micro->NM*duty->NM + Kp_micro->NS*duty->NS + Kp_micro->ZE*duty->ZE + Kp_micro->PS*duty->PS + Kp_micro->PM*duty->PM + Kp_micro->PL*duty->PL) ;
}