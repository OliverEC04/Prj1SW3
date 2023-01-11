#pragma once
#include <avr/io.h>

class LedDriver
{
	public:
	LedDriver(unsigned char port, unsigned char bit);
	void off() const;
	void on(unsigned char intensity = 100) const;
	
	private:
	unsigned char _port;
	unsigned char _bit;
};