#ifndef _My_LCD_
#define _My_LCD_

#define PORT_RS PORTB
#define PORT_EN PORTB
#define PORT_Data PORTB

#define DDR_RS DDRB
#define DDR_EN DDRB
#define DDR_Data DDRB

#define RS PB0
#define EN PB1
#define D7 PB5
#define D6 PB4
#define D5 PB3
#define D4 PB2

void Lcd_Port(char a);
void Lcd_cmd(char a);
void Lcd_Init();
void Lcd_Write_Char(char a);
void Lcd_Write_String(char *a);
void Lcd_Set_Cursor(char a, char b);
void Lcd4_Shift_Right();
void Lcd4_Shift_Left();
#endif