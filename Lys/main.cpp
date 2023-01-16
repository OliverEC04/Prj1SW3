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
<<<<<<< Updated upstream
=======
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
				M.setSpeed(30,0);
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
		/*while (PINA & (1<<5))
		{
		}
		driveLight.drive();
		S.StartSound();
>>>>>>> Stashed changes
		M.setSpeed(80,0.8);
		PORTB |= (1<<0);
		while (P.getPosition() < 1)
		{
		}
		TCNT3 = 0;
		time = T.getTime() + 3;
		while (T.getTime() < time)
		{
		}
		M.setBreak(2,20,1);
		while (TIMSK1 != 0)
		{
		}
		M.setSpeed(20,1);
		driveLight.brake(0);
		while (P.getPosition() < 2)
		{
		}
		M.setSpeed(10,0);
		PORTB |= (1<<1);
		TCNT3 = 0;
		time = T.getTime() + 20;
		while (T.getTime() < time)
		{
		}
		M.setSpeed(30,1);
		PORTB |= (1<<2);
		TCNT3 = 0;
		time = T.getTime() + 10;
		while (T.getTime() < time)
		{
		}
		M.setSpeed(75,2);
		TCNT3 = 0;
		PORTB |= (1<<3);
		time = T.getTime() + 25;
		while (T.getTime() < time)
		{
		}
		for (int j=0; j<20;j++)
		{
			accArray[j] = AccY();
			accSum += accArray[j];
		}
		i = 0;
		while (accSum < -5300) //-320    320
		{
			if (i == 20)
			{
				i = 0;
			}
			acc = AccY();
			accSum += (acc - accArray[i]);
			accArray[i] = acc;
			i++;
		}
		M.setSpeed(65,0);
		M.setSpeed(10,1.2);
		PORTB |= (1<<4);
		while (P.getPosition() < 3)
		{
		}
		M.setSpeed(10,0);
		M.setSpeed(0,1);
		for (int j=0; j<20;j++)
		{
			accArray[j] = AccY();
			accSum += accArray[j];
		}
		i = 0;
		while (accSum < 6400) //-320    320
		{
			if (i == 20)
			{
				i = 0;
			}
			acc = AccY();
			accSum += (acc - accArray[i]);
			accArray[i] = acc;
			i++;
		}
		TCNT3 = 0;
		time = T.getTime() + 15;
		while (T.getTime() < time)
		{
		}
		M.setSpeed(20,0);
		TCNT3 = 0;
		PORTB |= (1<<6);
		time = T.getTime() + 5;
		while (T.getTime() < time)
		{
		}
		M.setSpeed(0,0);
		while (P.getPosition() < 4)
		{
		}
		M.setSpeed(10,0);
		M.setSpeed(80,1.6);
		while (P.getPosition() < 5)
		{
		}
		TCNT3 = 0;
		time = T.getTime() + 10;
		while (T.getTime() < time)
		{
		}
		M.setBreak(2,10,1);
		while (TIMSK1 != 0)
		{
		}
		if (P.getPosition() < 4)
		{
			M.setSpeed(20,0);
			TCNT3 = 0;
			time = T.getTime() + 10;
			while (T.getTime() < time)
			{
			}
		}
		while (P.getPosition() < 6)
		{
		}
		M.setSpeed(-1,0);
		TCNT3 = 0;
		time = T.getTime() + 10;
		while (T.getTime() < time)
		{
		}
		M.setSpeed(-100,2);
		while (P.getPosition() < 7)
		{
		}
		TCNT3 = 0;
		time = T.getTime() + 5;
		while (T.getTime() < time)
		{
		}
		M.setSpeed(-70,0);
		M.setSpeed(0,1);
		while (P.getPosition() < 8)
		{
		}
		TCNT3 = 0;
		time = T.getTime() + 20;
		while (T.getTime() < time)
		{
		}
		M.setSpeed(1,0);
		TCNT3 = 0;
		time = T.getTime() + 10;
		while (T.getTime() < time)
		{
		}
		M.setSpeed(100,2);
		while (P.getPosition() < 11)
		{
		}
		M.setSpeed(50,0);
		M.setSpeed(0,0.5);
		PORTB |= (1<<7);	
	}
	return 0;
}