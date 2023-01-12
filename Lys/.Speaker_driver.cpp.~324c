
// ---- PROJECT 1 - 21.01.2023 -

#include "Headers/uart.h"
#include "Headers/Speaker_driver.h"
#include "Headers/uart2.h"
#define F_CPU 16000000
#include <util/delay.h>

Speaker_driver S;

////////// SOUND //////////

void Speaker_driver::StartSound()
{
	//startlyd: 001
	char array[] = {0x7E, 0x0F, 0x00, 0x01, 0x01, 0xFF, 0xEF, 0xEF};
	sendCommand(array);
}


void Speaker_driver::ReflektorSound()
{
	//Reflektorlyd: 002
	char array[] = {0x7E, 0x0F, 0x00, 0x01, 0x02, 0xFF, 0xEE, 0xEF};
	sendCommand2(array);
}


void Speaker_driver::EndSound()
{
	//Endsound: 003
	char array[] = {0x7E, 0x0F, 0x00, 0x01, 0x03, 0xFF, 0xED, 0xEF};
	sendCommand(array);
}


////////// VOLUME //////////

void Speaker_driver::setVolume()
{
	char array[] = {0x7E, 0x06, 0x00, 0x00, 0x1E, 0xFF, 0xDC, 0xEF};
	sendCommand(array);
	sendCommand2(array);
}

void Speaker_driver::initSpeakerdriver()
{
	
	// Initialize UART: Baud = 9600, 8 data bits, No Parity
	InitUART(9600, 8);
	InitUART2(9600, 8);
	_delay_ms(200);
	
	setVolume();
	_delay_ms(200);
	
	char array[] = {0x7E, 0x0C, 0x00, 0x00, 0x00, 0xFF, 0xF4, 0xEF};
	sendCommand(array);
	sendCommand2(array);
}

void Speaker_driver::sendCommand(char array[])
{
	for (int i = 0; i<8; i++)
	{
		SendChar(array[i]);
	}
}

void Speaker_driver::sendCommand2(char array[])
{
	for (int i = 0; i<8; i++)
	{
		SendChar2(array[i]);
	}
}
