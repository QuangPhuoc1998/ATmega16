#include "main.h"
#include "SPI.h"

void Spi_Init_Master()
{
	DDRB |= (1<<PB4)|(1<<PB5)|(1<<PB7);    // SCK, MOSI and SS as outputs
	DDRB &= ~(1<<PB6);                 // MISO as input
	
	SPCR |= (1<<MSTR);               // Set as Master
	SPCR |= (1<<SPR0)|(1<<SPR1);     // divided clock by 128
	SPCR |= (1<<SPE);                // Enable SPI
}
void Spi_Init_Slave()
{
	DDRB &= ~((1<<PB4)|(1<<PB5)|(1<<PB7));   // SCK, MOSI and SS as inputs
	DDRB |= (1<<PB6);                    // MISO as output

	SPCR &= ~(1<<MSTR);                // Set as slave
	SPCR |= (1<<SPR0)|(1<<SPR1);       // divide clock by 128
	SPCR |= (1<<SPE);
}
unsigned char Spi_Read()
{
	while(!(SPSR & (1<<SPIF)));    // wait until all data is received
	return SPDR;
}
void Spi_Read_Text(char *Output, unsigned int length)
{
	int i;
	for(i=0;i<length;i++)
	Output[i] = Spi_Read();
}
void Spi_Write(char data)
{
	SPDR = data;
	while(!(SPSR & (1<<SPIF)));
}
void SPI_Write_Text(char *text)
{
	int i;
	for(i=0;text[i]!='\0';i++)
	Spi_Write(text[i]);
}