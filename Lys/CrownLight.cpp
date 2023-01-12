#include "Headers/CrownLight.h"

#include "Headers/Speaker_driver.h"
extern Speaker_driver S;

const unsigned char crownLedAmount = 11;

LedDriver crownLedDrivers[crownLedAmount] = {
	LedDriver('L', 5),
	LedDriver('L', 7),
	LedDriver('G', 1),
	LedDriver('D', 7),
	LedDriver('C', 1),
	LedDriver('C', 3),
	LedDriver('L', 4),
	LedDriver('L', 6),
	LedDriver('G', 0),
	LedDriver('G', 2),
	LedDriver('C', 0)
};

CrownLight crownLight = CrownLight(crownLedDrivers, crownLedAmount);

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
		S.ReflektorSound();
	}
}
