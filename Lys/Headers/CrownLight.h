#include "LedDriver.h"

class CrownLight
{
	public:
		CrownLight(LedDriver[_ledAmount] ledDrivers);
		void setCount(char count);
		void countDown();
		void countUp();
		
	private:
		char _ledAmount = 11;
		LedDriver[_ledAmount] _ledDrivers;
		char _count;
};