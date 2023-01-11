#define F_CPU 16000000
#include <util/delay.h>
#include "Headers/uart.h"
#include "Headers/mma8652.h"

#include "Headers/LedDriver.h"

#include "Headers/LightTimer.h"
extern LightTimer lightTimer;

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
	InitUART(9600,8);
	int time = 0;
	DDRA &= ~(1<<5);
	while (1)
	{
		while (PINA & (1<<5))
		{
		}
		driveLight.drive();
		M.setSpeed(100,2);
		PORTB |= (1<<0);
		while (P.getPosition() < 1)
		{
		}
		PORTB |= (1<<1);
		while (P.getPosition() < 2)
		{
		}
		PORTB |= (1<<2);
		while (P.getPosition() < 3)
		{
		}
		PORTB |= (1<<3);
		M.setSpeed(50,1);
		driveLight.brake(10);
		while (AccY()>-30) //-320    320
		{
		}
		M.setSpeed(100,0);
		TCNT3 = 0;
		time = T.getTime();
		while (T.getTime() > (time+2))
		{
		}
		M.setSpeed(-100,0);
		driveLight.brake(0);
		TCNT3 = 0;
		time = T.getTime();
		while (T.getTime() > (time+3))
		{
		}
		M.setSpeed(20,2);
		time = T.getTime();
		while (T.getTime() > (time+50))
		{
		}
		M.setSpeed(0,1);
		driveLight.brake(10);
	}
	return 0;
}