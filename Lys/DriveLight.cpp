#include "Headers/DriveLight.h"

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
	_frontLedDriver.on(85);
	_backLedDriver.on(42);
}

void DriveLight::brake()
{
	_frontLedDriver.on(85);
	_backLedDriver.on();
}
