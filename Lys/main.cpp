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
	int acc;
	int accSum = 0;
	int accArray[20];
	int i;
	
	S.initSpeakerdriver();
	
	while (1)
	{
		while (PINA & (1<<5))
		{
		}
		driveLight.drive();
		S.StartSound();
		P.setPosition(0);
		crownLight.setCount(0);
		M.setSpeed(65,0.65);
		PORTB |= (1<<0);
		T.setTime(0);
		while (P.getPosition() < 1)
		{
		}
		M.setSpeed(10,0.5);
		driveLight.brake(0);
		while (P.getPosition() < 2)
		{
		}
		M.setSpeed(10,0);
		TCNT3 = 0;
		time = T.getTime() + 10;
		while (T.getTime() < time)
		{
		}
		M.setSpeed(20,0);
		M.setSpeed(40,0.7);
		TCNT3 = 0;
		PORTB |= (1<<1);
		time = T.getTime() + 8;
		while (T.getTime() < time)
		{
		}
		M.setSpeed(60,0);
		M.setSpeed(94,1);	
		TCNT3 = 0;
		PORTB |= (1<<2);
		time = T.getTime() + 12;
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
		M.setSpeed(60,0);
		M.setSpeed(10,0.9);
		while (P.getPosition() < 3)
		{
		}
		M.setSpeed(5,0);
		TCNT3 = 0;
		time = T.getTime() + 7;
		while (T.getTime() < time)
		{
		}
		M.setSpeed(0,0);
		TCNT3 = 0;
		PORTB |= (1<<3);
		time = T.getTime() + 2;
		while (T.getTime() < time)
		{
		}
		M.setSpeed(-1,0);
		M.setBreak(3,30,1);
		PORTB |= (1<<4);
		while (TIMSK1 != 0)
		{
		}
		M.setBreak(4,70,1);
		PORTB |= (1<<5);
		while (TIMSK1 != 0)
		{
		}
		M.setSpeed(-1,0);
		TCNT3 = 0;
		PORTB |= (1<<3);
		time = T.getTime() + 20;
		while (T.getTime() < time)
		{
		}
		M.setSpeed(0,0);
		TCNT3 = 0;
		PORTB |= (1<<3);
		time = T.getTime() + 3;
		while (T.getTime() < time)
		{
		}
		M.setBreak(30,10,1);
		PORTB |= (1<<6);
		while (TIMSK1 != 0)
		{
		}
		M.setSpeed(10,0);
		PORTB |= (1<<7);
		while (P.getPosition() < 4)
		{
		}
		M.setSpeed(20,0);
		M.setSpeed(70,0.8);
		while (P.getPosition() < 5)
		{
		}
		TCNT3 = 0;
		time = T.getTime() + 4;
		while (T.getTime() < time)
		{
		}
		M.setSpeed(10,0.6);
		while (P.getPosition() < 6)
		{
		}
		M.setSpeed(0,0);
		TCNT3 = 0;
		time = T.getTime() + 6;
		while (T.getTime() < time)
		{
		}
		M.setSpeed(-1,0);
		TCNT3 = 0;
		time = T.getTime() + 5;
		while (T.getTime() < time)
		{
		}
		M.setSpeed(-100,2);
		while (P.getPosition() < 7)
		{
		}
		TCNT3 = 0;
		time = T.getTime() + 7;
		while (T.getTime() < time)
		{
		}
		M.setSpeed(-50,0);
		M.setSpeed(-10,0.5);
		while (P.getPosition() < 8)
		{
		}
		M.setSpeed(0,0);
		TCNT3 = 0;
		time = T.getTime() + 10;
		while (T.getTime() < time)
		{
		}
		M.setSpeed(1,0);
		TCNT3 = 0;
		time = T.getTime() + 6;
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
		/*while ((PINA & (1<<5)) & (PINA & (1<<2)))
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
		}*/
	}
	return 0;
}