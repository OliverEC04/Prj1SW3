#include "Headers/LedDriver.h"
#include "Headers/DriveLight.h"
#include "Headers/CrownLight.h"

int main(void)
{
	const unsigned char crownLedAmount = 11;
	
	LedDriver crownLedDrivers[crownLedAmount] = {
		LedDriver('B', 1),
		LedDriver('B', 1),	
		LedDriver('B', 1),	
		LedDriver('B', 1),	
		LedDriver('B', 1),	
		LedDriver('B', 1),	
		LedDriver('B', 1),	
		LedDriver('B', 1),	
		LedDriver('B', 1),	
		LedDriver('B', 1),	
		LedDriver('B', 1)
	};
	
	DriveLight driveLight = DriveLight(LedDriver('H', 6), LedDriver('H', 5));
	CrownLight crownLight = CrownLight(crownLedDrivers, crownLedAmount);
	
	driveLight.drive();
	
	while(1)
	{
		crownLight.countUp();
	}
}
