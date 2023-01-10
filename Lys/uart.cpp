/************************************************
* "uart.c":                                     *
* Implementation file for Mega2560 UART driver. *
* Using UART 0.                                 *
* Henning Hargaard, 5/4 2019                    *
*************************************************/
#include <avr/io.h>
#include <stdlib.h>
#include <math.h>
#include "Headers/uart.h"

// Target CPU frequency
#define XTAL 16000000

/*************************************************************************
UART 0 initialization:
    Asynchronous mode.
    Baud rate = 9600.
    Data bits = 8.
    RX and TX enabled.
    No interrupts enabled.
    Number of Stop Bits = 1.
    No Parity.
    Baud rate = 9600.
    Data bits = 8.
*************************************************************************/
void InitUART(unsigned long BaudRate, unsigned char DataBit)
{
	if (BaudRate < 300)
	{
		BaudRate = 300;
	} 
	else if (BaudRate > 115200)
	{
		BaudRate = 115200;
	}
	double UBR = ((double)XTAL/(16*BaudRate))-1;
	UBRR0 = (int)round(UBR);
	if (DataBit == 5)
	{
		UCSR0B = 0b00011000;
		UCSR0C = 0b00000000;
	} 
	else if (DataBit == 6)
	{
		UCSR0B = 0b00011000;
		UCSR0C = 0b00000010;
	}
	else if (DataBit == 7)
	{
		UCSR0B = 0b00011000;
		UCSR0C = 0b00000100;
	}
	else if (DataBit == 9)
	{
		UCSR0B = 0b00011100;
		UCSR0C = 0b00000110;
	}
	else
	{
		UCSR0B = 0b00011000;
		UCSR0C = 0b00000110;
	}
}

/*************************************************************************
  Returns 0 (FALSE), if the UART has NOT received a new character.
  Returns value <> 0 (TRUE), if the UART HAS received a new character.
*************************************************************************/
unsigned char CharReady()
{
	if ((UCSR0A & 0b10000000) != 0)
	{
		return 1;
	} 
	else
	{
		return 0;
	}
}

/*************************************************************************
Awaits new character received.
Then this character is returned.
*************************************************************************/
char ReadChar()
{
	while (CharReady() == 0)
	{
	}
	//UCSR0A &= 0b01111111;
	return UDR0;
}

/*************************************************************************
Awaits transmitter register ready.
Then send the character.
Parameter :
	Tegn : Character for sending. 
*************************************************************************/
void SendChar(char Tegn)
{
	while ((UCSR0A & 0b00100000) == 0)
	{
	}
	//UCSR0A &= 0b11011111;
	UDR0 = Tegn;
}

/*************************************************************************
Sends 0 terminated string.
Parameter:
   Streng: Pointer to the string. 
*************************************************************************/
void SendString(char* Streng)
{
	unsigned int i = 0;
	while (Streng[i] != '\0')
	{
		SendChar(Streng[i]);
		i++;
	}
}

/*************************************************************************
Converts the integer "Tal" to an ASCII string - and then sends this string
using the USART.
Makes use of the C standard library <stdlib.h>.
Parameter:
    Tal: The integer to be converted and sent. 
*************************************************************************/
void SendInteger(int Tal)
{
	char int_string[7];
	itoa(Tal, int_string, 10);
	SendString(int_string);
}

/************************************************************************/