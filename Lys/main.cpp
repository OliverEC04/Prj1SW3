#define F_CPU 16000000
#include <util/delay.h>
#include "Headers/uart.h"
#include "Headers/mma8652.h"

#include "Headers/LedDriver.h"
#include "Headers/DriveLight.h"
extern DriveLight driveLight;

#include "Headers/CrownLight.h"
extern CrownLight crownLight;

#include "Headers/Motor.h"
extern Motor M;

#include "Headers/Timer.h"
extern Timer T;

#include "Headers/Position.h"
extern Position P;

int main(void)
{		
	while(1)
	{
		crownLight.countUp();
		driveLight.drive();
	}
}
