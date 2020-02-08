#ifndef _LCD_I2C_H_
#define _LCD_I2C_H_

#define Address_PCF8574 0x40
void Lcd_Write_Char(unsigned char data);
void lcd_send_cmd (unsigned char data);
void Lcd_Clear();
void Lcd_Init();
void Lcd_Write_String(char *str);
void Lcd_Set_Cursor(unsigned char row, unsigned char col);

#endif