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

#include "Headers/Speaker_driver.h"
extern Speaker_driver S;

int main(void)
{		
	InitUART(9600,8);
	DDRA &= ~(1<<5);
	sei();
	int time = 0;
	
	S.initSpeakerdriver();
	
	while (1)
	{
		while (PINA & (1<<5))
		{
		}
		S.StartSound();
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
		M.setSpeed(50,1);
		driveLight.brake(10);
		time = T.getTime();
		while (T.getTime() > (time+15)) //-320    320
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
		S.EndSound();
	}
	return 0;
}