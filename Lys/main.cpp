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

#include "Headers/Speaker_driver.h"
extern Speaker_driver S;

int main(void)
{		
	InitUART(9600,8);
	initAcc();
	DDRA &= ~(1<<5);
	sei();
	int time;
	int acc = 0;
	int accSum = 0;
	int accArray[20];
	int i;
	
	S.initSpeakerdriver();
	
	while (1)
	{
		while ((PINA & (1<<5)) & (PINA & (1<<2)))
		{
		}
		driveLight.drive();
		S.StartSound();
		if ((PINA & (1<<5)) == 0)
		{
			while (1)
			{
				M.setSpeed(15,0);
				TCNT3 = 0;
				time = T.getTime() + 15;
				while (T.getTime() < time)
				{
				}
				M.setSpeed(0,0);
				TCNT3 = 0;
				time = T.getTime() + 15;
				while (T.getTime() < time)
				{
				}
			}
		}
		if ((PINA & (1<<2)) == 0)
		{
			while (1)
			{
				M.setSpeed(100,0);
				TCNT3 = 0;
				time = T.getTime() + 10;
				while (T.getTime() < time)
				{
				}
				M.setSpeed(-100,0);
				TCNT3 = 0;
				time = T.getTime() + 7;
				while (T.getTime() < time)
				{
				}
			}
		}
	}
	return 0;
}