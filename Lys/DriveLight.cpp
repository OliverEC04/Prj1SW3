#include "Headers/DriveLight.h"

//#include "Headers/LightTimer.h"
//extern LightTimer lightTimer;

DriveLight driveLight = DriveLight(LedDriver('B', 5), LedDriver('G', 5));

DriveLight::DriveLight(LedDriver frontLedDriver, LedDriver backLedDriver)
: _frontLedDriver(frontLedDriver), _backLedDriver(backLedDriver)
{
}

void DriveLight::off() const
{
	_frontLedDriver.off();
	_backLedDriver.off();
}

void DriveLight::drive() const
{
	_frontLedDriver.on(255);
	_backLedDriver.on(52);
}

void DriveLight::brake() const
{
	_frontLedDriver.on(255);
	_backLedDriver.on(223);
	
	//lightTimer.addEvent(1000, testFunk);
}
