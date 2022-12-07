/************************************************
* "uart.c":                                     *
* Implementation file for Mega2560 UART driver. *
* Using UART 0.                                 *
* Henning Hargaard, 5/4 2019                    *
*************************************************/
#include <avr/io.h>
#include <stdlib.h>
#include "Headers/uart_int.h"

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
void InitUART(unsigned long BaudRate, unsigned char DataBit, unsigned char Rx_Interrupt)
{
	//UCSR0A = 0b00100000;
	UCSR0B = 0b00011000;
	UCSR0C = 0b00000110; //Min løsning
	//UCSR0C = (DataBit-5)<<1;//Hennings løsning
	//BAUD = 9600 = 16M / 16(x+1)	x = 103,17
	UBRR0 = XTAL / (16*BaudRate) - 1;
	
	if (Rx_Interrupt == 0){
		UCSR0B &= 0b01111111;//Disable modtage  interrupt
	}
	else{
		UCSR0B |= 0b10000000;//Enable modtage interrupt
	}
	
}

/*************************************************************************
  Returns 0 (FALSE), if the UART has NOT received a new character.
  Returns value <> 0 (TRUE), if the UART HAS received a new character.
*************************************************************************/
unsigned char CharReady()
{
   if ((UCSR0A & 0b10000000) != 0){
	   return 1;
   } else {
	   return 0;
   }
   
   //return UCSR0A & (1<<7); //Hennings løsning
}

/*************************************************************************
Awaits new character received.
Then this character is returned.
*************************************************************************/
char ReadChar()
{
	while (CharReady() == 0){}
	//char x = UDR0;
	return UDR0; //Returner den værdi som er i UDR0
	}
	//while((UCSR0A & (1<<7)) == 0){}	 //Hennings løsning
		//return UDR0;					//
/*************************************************************************
Awaits transmitter register ready.
Then send the character.
Parameter :
	Tegn : Character for sending. 
*************************************************************************/
void SendChar(char Tegn)
{
	while ((UCSR0A & 0b00100000) == 0){}
   UDR0 = Tegn;
}

/*************************************************************************
Sends 0 terminated string.
Parameter:
   Streng: Pointer to the string. 
*************************************************************************/
void SendString(char* Streng)
{
	while (*Streng != 0){ // 0 er det samme som \0
		SendChar(*Streng);
		Streng++;	
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
	char array[7];
	
	itoa(Tal, array, 10);
	SendString(array);
}

/************************************************************************/