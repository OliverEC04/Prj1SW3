#include "Headers/CrownLight.h"

CrownLight::CrownLight(LedDriver* ledDrivers, char ledAmount)
: _ledDrivers(ledDrivers), _ledAmount(ledAmount), _count(0)
{
}

void CrownLight::setCount(char count)
{
	_count = count;
	
	for (char i = 0; i < _ledAmount; i++)
	{
		if (i < _count)
		{
			_ledDrivers[i].on();
		}
		else
		{
			_ledDrivers[i].off();
		}
	}
}

void CrownLight::countDown()
{
	if (_count > 0)
	{
		setCount(--_count);	
	}
}

void CrownLight::countUp()
{
	if (_count < _ledAmount)
	{
		setCount(++_count);
	}
}
