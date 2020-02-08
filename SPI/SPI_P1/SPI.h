#ifndef _SPI_H_
#define _SPI_H_

void Spi_Init_Master();
void Spi_Init_Slave();
unsigned char Spi_Read();
void Spi_Read_Text(char *Output, unsigned int length);
void Spi_Write(char data);
void SPI_Write_Text(char *text);

#endif