
// ---- PROJECT 1 - 21.01.2023 ----

// "uart.h" specifications:
// * Header file for Mega2560 UART driver
// * Using UART 0

#ifndef UART2_H_
#define UART2_H_

void InitUART2(unsigned long BaudRate, unsigned char DataBit);

unsigned char CharReady2();
char ReadChar2();

void SendChar2(char Tegn);
void SendString2(const char* Streng);
void SendInteger2(int Tal);

#endif /* UART2_H_ */

