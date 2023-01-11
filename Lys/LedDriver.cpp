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
			
			if (_bit == 7)
			{
				// TIMER 0 (pin 13 (PB7)) -----
				
				TCCR0A = 0b10000011;
				TCCR0B = 0b00000001;
				OCR0A = 0;
				
				// ----------------------
			}
			else if (_bit == 5)
			{
				// TIMER 1 (pin 11 (PB5)) -----
				
				TCCR1A = 0b10000011;
				TCCR1B = 0b00000001;
				OCR1A = 0;
				
				// ----------------------
			}
			break;
			
		case 'C':
			DDRC |= (1<<(_bit));
			break;
		
		case 'H':
			DDRH |= (1<<(_bit));
			break;
			
		case 'G':
			DDRG |= (1<<(_bit));
			
			if (_bit == 5)
			{
				// TIMER 0 (pin 4 (PG5)) -----
				
				TCCR0A = 0b00100011;
				TCCR0B = 0b00000001;
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
			
			if (_bit == 7)
			{
				OCR0A = intensity;
			}
			else if (_bit == 5)
			{
				OCR1A = intensity / 255 * 65535;
			}
			break;
			
		case 'C':
			PORTC |= pattern;
			break;
		
		case 'H':
			PORTH |= pattern;
			break;
	}
}
