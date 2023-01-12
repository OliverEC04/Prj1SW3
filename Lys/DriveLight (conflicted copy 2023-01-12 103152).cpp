#include "Headers/DriveLight.h"

#include "Headers/Timer.h"
extern Timer T;

DriveLight driveLight = DriveLight(LedDriver('H', 6), LedDriver('G', 5));

DriveLight::DriveLight(LedDriver frontLedDriver, LedDriver backLedDriver)
: _frontLedDriver(frontLedDriver), _backLedDriver(backLedDriver)
{
	int brakeOff = 0;
	
	off();
}

void DriveLight::off() const
{
	_frontLedDriver.off();
	_backLedDriver.off();
}

void DriveLight::drive() const
{
	_frontLedDriver.on(100);
	_backLedDriver.on(50);
}

void DriveLight::brake(int breaktime)
{
	_frontLedDriver.on(100);
	_backLedDriver.on(100);
	
	brakeOff = T.getTime() + breaktime + 5;
}
