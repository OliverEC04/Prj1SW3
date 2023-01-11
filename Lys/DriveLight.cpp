#include "Headers/DriveLight.h"

#include "Headers/LightTimer.h"
extern LightTimer lightTimer;

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

void DriveLight::brake() const
{
	_frontLedDriver.on(100);
	_backLedDriver.on(100);
	
	brakeOff = T.getTime() + 20;
}
