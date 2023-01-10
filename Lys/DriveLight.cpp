#include "Headers/DriveLight.h"

DriveLight driveLight = DriveLight(LedDriver('B', 5), LedDriver('B', 7));

DriveLight::DriveLight(LedDriver frontLedDriver, LedDriver backLedDriver)
: _frontLedDriver(frontLedDriver), _backLedDriver(backLedDriver)
{
}

void DriveLight::off()
{
	_frontLedDriver.off();
	_backLedDriver.off();
}

void DriveLight::drive()
{
	_frontLedDriver.on(255);
	_backLedDriver.on(52);
}

void DriveLight::brake()
{
	_frontLedDriver.on(255);
	_backLedDriver.on(223);
}
