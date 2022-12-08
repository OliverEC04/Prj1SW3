#include "Headers/DriveLight.h"
#include "Headers/CrownLight.h"

void main()
{		
	DriveLight driveLight = DriveLight(LedDriver('H', 6), LedDriver('H', 5));
	/*
	CrownLight crownLight = CrownLight({
		LedDriver(),
		LedDriver(),
		LedDriver(),
		LedDriver(),
		LedDriver(),
		LedDriver(),
		LedDriver(),
		LedDriver(),
		LedDriver(),
		LedDriver(),
		LedDriver()
	});
	*/
	
	driveLight.drive();
	
	while(1)
	{
		
	}
}
