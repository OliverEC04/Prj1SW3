#include "Headers/DriveLight.h"

#include "Headers/LightTimer.h"
extern LightTimer lightTimer;

DriveLight driveLight = DriveLight(LedDriver('B', 7), LedDriver('B', 6));

DriveLight::DriveLight(LedDriver frontLedDriver, LedDriver backLedDriver)
: _frontLedDriver(frontLedDriver), _backLedDriver(backLedDriver)
{
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
	_backLedDriver.on(20);
}

void DriveLight::brake() const
{
	_frontLedDriver.on(100);
	_backLedDriver.on(87);
	
	lightTimer.event(2000);
	
	//lightTimer.addEvent(1000, testFunk);
}
