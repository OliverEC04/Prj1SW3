#include "Headers/CrownLight.h"

CrownLight::CrownLight(LedDriver[_ledAmount] ledDrivers)
{
	_ledDrivers = ledDrivers;
	_count = 0;
}

void CrownLight::setCount(char count)
{
	_count = count;
	
	for (char i = 0; i < _ledAmount; i++)
	{
		if (i < _count)
		{
			_ledDrivers[i].on(); // TODO: set intensity to 128
		}
		else
		{
			_ledDrivers[i].off();
		}
	}
}

void CrownLight::countDown()
{
	setCount(_count--);
}

void CrownLight::countUp()
{
	setCount(_count++);
}
