#pragma once
#include "LedDriver.h"

class CrownLight
{
	public:
		CrownLight(LedDriver* ledDrivers, char ledAmount);
		void setCount(char count);
		void countDown();
		void countUp();
		
	private:
		LedDriver* _ledDrivers;
		char _ledAmount;
		char _count;
};