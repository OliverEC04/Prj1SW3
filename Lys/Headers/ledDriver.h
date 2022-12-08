#pragma once
#include <avr/io.h>

class LedDriver
{
	public:
		LedDriver(unsigned char port, unsigned char bit);
		void off();
		void on(unsigned char intensity = 255);
		
	private:
		unsigned char _port;
		unsigned char _bit;
};
