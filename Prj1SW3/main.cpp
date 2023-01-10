#define F_CPU 16000000
#include <util/delay.h>
#include "Headers/uart.h"
#include "Headers/mma8652.h"

#include "Headers/LedDriver.h"
#include "Headers/DriveLight.h"
#include "Headers/CrownLight.h"

#include "Headers/Motor.h"
extern Motor M;

#include "Headers/Timer.h"
extern Timer T;

#include "Headers/Position.h"
extern Position P;

int main(void)
{	
	const unsigned char crownLedAmount = 11;
	
	LedDriver crownLedDrivers[crownLedAmount] = {
		LedDriver('C', 1),
		LedDriver('C', 3),	
		LedDriver('C', 5),	
		LedDriver('C', 7),	
		LedDriver('A', 6),	
		LedDriver('A', 4),	
		LedDriver('C', 0),	
		LedDriver('C', 2),	
		LedDriver('C', 4),	
		LedDriver('C', 6),	
		LedDriver('A', 7)
	};
	
	DriveLight driveLight = DriveLight(LedDriver('B', 5), LedDriver('B', 7));
	CrownLight crownLight = CrownLight(crownLedDrivers, crownLedAmount);
	
	while(1)
	{
		crownLight.countUp();
		driveLight.drive();
	}
}
