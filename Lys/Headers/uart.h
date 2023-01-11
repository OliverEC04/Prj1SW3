/****************************************
* "uart.h":                             *
* Header file for Mega2560 UART driver. *
* Using UART 0.                         *
* Henning Hargaard, 5/4 2019            *
*****************************************/ 
#include <avr/io.h>
#include <stdlib.h>

void InitUART(unsigned long BaudRate, unsigned char DataBit);
unsigned char CharReady();
char ReadChar();
void SendChar(char Tegn);
void SendString(const char* Streng);
void SendInteger(int Tal);
/****************************************/
