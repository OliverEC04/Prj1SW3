#include "Headers/DriveLight.h"

DriveLight::DriveLight(LedDriver frontLedDriver, LedDriver backLedDriver)
{
	_frontLedDriver = frontLedDriver;
	_backLedDriver = backLedDriver;
}

void DriveLight::off()
{
	_frontLedDriver.off();
	_backLedDriver.off();
}

void DriveLight::drive()
{
	_frontLedDriver.on(); // TODO: set intensity to 85
	_backLedDriver.on(); // TODO: set intensity to 42
}

void DriveLight::brake()
{
	_frontLedDriver.on(); // TODO: set intensity to 85
	_backLedDriver.on();
}
