/*
 * code_KeyPad4x4.c
 *
 * Created: 03/05/2019 21:19:53
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
#include "KeyPad4x4.h"



int main(void)
{
  // bien 
  unsigned char key = 0;
  // port
  DDRC = 0xFF;
  // chuon trinh con
  Lcd4_Init();
  KeyPad4x4_Init();
  // begin
  Lcd4_Write_String("Gia tri: ");
  while(1)
  {
    if(Key_press() != 0) key = Key_press();
    Lcd4_Set_Cursor(1,9);
	Lcd4_Write_Char(key/10+48);
	Lcd4_Write_Char(key%10+48);

  }
}

