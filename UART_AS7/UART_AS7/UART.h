#ifndef _UART_H_
#define _UART_H_


void UART_init(long USART_BAUDRATE);
unsigned char UART_RxChar();
void UART_Read_Text(char *Output, unsigned int length);
void UART_TxChar(char ch);
void UART_SendString(char *str);

#endif