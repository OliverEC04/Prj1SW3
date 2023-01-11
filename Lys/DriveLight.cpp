#include "Headers/DriveLight.h"

#include "Headers/Timer.h"
extern Timer T;

#include "Headers/LightTimer.h"
extern LightTimer lightTimer;

DriveLight driveLight = DriveLight(LedDriver('H', 6), LedDriver('G', 5));

DriveLight::DriveLight(LedDriver frontLedDriver, LedDriver backLedDriver)
: _frontLedDriver(frontLedDriver), _backLedDriver(backLedDriver)
{
	int brakeOff = 0;
	
	off();
}

void DriveLight::off()
{
	_frontLedDriver.off();
	_backLedDriver.off();
}

void DriveLight::drive()
{
	_frontLedDriver.on(100);
	_backLedDriver.on(50);
}

<<<<<<< HEAD
void DriveLight::brake(int breaktime)
=======
void DriveLight::brake()
>>>>>>> 0c1fd34984301c6190ef5cf1ed804b5e384af99a
{
	_frontLedDriver.on(100);
	_backLedDriver.on(100);
	
	brakeOff = T.getTime() + breaktime + 5;
}
