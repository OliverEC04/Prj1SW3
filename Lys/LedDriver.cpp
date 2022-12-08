#include "Headers/LedDriver.h"

LedDriver::LedDriver(unsigned char port, unsigned char bit)
{
	_port = port;
	_bit = bit;
	
	switch(_port)
	{
		case 'B':
			DDRB = 0xFF;
			break;
		
		case 'H':
			DDRH = 0xFF;
			break;
	}
}

void LedDriver::off()
{
	unsigned char pattern = 0b11111110 << _bit;
	
	switch(_port)
	{
		case 'B':
			PORTB &= pattern;
			break;
		
		case 'H':
			PORTH &= pattern;
			break;
	}
}

void LedDriver::on(unsigned char intensity = 255)
{
	unsigned char pattern = 0b00000001 << _bit;
	
	switch(_port)
	{
		case 'B':
			PORTB |= pattern;
			break;
		
		case 'H':
			PORTH |= pattern;
			break;
	}
}
