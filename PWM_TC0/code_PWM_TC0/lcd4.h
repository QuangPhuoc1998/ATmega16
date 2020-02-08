
#include "main.h"

#define RS PORTC.0
#define EN PORTC.1
#define D4 PORTC.2
#define D5 PORTC.3
#define D6 PORTC.4
#define D7 PORTC.5

void Lcd_Port(char a);
void Lcd_Cmd(char a);
void Lcd_Clear();
void Lcd_Set_Cursor(char a, char b);
void Lcd_Init();
void Lcd_Write_Char(char a);
void Lcd_Write_String(char *a);
void Lcd_Shift_Right();
void Lcd_Shift_Left();