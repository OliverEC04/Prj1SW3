#include "Headers/LedDriver.h"

LedDriver::LedDriver(unsigned char port, unsigned char bit)
: _port(port), _bit(bit)
{
	switch(_port)
	{
		case 'A':
		DDRA |= (1<<(_bit));
		break;
		
		case 'B':
		DDRB |= (1<<(_bit));
		break;
		
		case 'C':
		DDRC |= (1<<(_bit));
		break;
		
		case 'H':
		DDRH |= (1<<(_bit));
		
		if (_bit == 6)
		{
			// TIMER 2 (pin 9 (PH6)) -----
			
			TCCR2A = 0b00110001;
			TCCR2B = 0b00001001;
			OCR2A = 0;
			
			// ----------------------
		}
		break;
		
		case 'G':
		DDRG |= (1<<(_bit));
		
		if (_bit == 5)
		{
			// TIMER 0 (pin 4 (PG5)) -----
			
			TCCR0A = 0b00110001;
			TCCR0B = 0b00001001;
			OCR0A = 0;
			
			// ----------------------
		}
		break;
	}
}

void LedDriver::off() const
{
	unsigned char pattern = ~(1<<_bit);
	
	switch(_port)
	{
		case 'A':
		PORTA &= pattern;
		break;
		
		case 'B':
		PORTB &= pattern;
		
		break;
		
		case 'C':
		PORTC &= pattern;
		break;
		
		case 'H':
		PORTH &= pattern;
		break;
	}
}

void LedDriver::on(unsigned char intensity) const
{
	unsigned char pattern = (0b00000001 << _bit);
	
	switch(_port)
	{
		case 'A':
		PORTA |= pattern;
		break;
		
		case 'B':
		PORTB |= pattern;
		break;
		
		case 'C':
		PORTC |= pattern;
		break;
		
		case 'H':
		PORTH |= pattern;
		
		if (_bit == 6)
		{
			OCR2A = intensity / 100 * 255;
		}
		break;
		
		case 'G':
		PORTG |= pattern;
		if (_bit == 5)
		{
			OCR0A = intensity / 100 * 255;
		}
		
		break;		
	}
}