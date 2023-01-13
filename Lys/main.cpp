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
	int time = 0;
	int acc = 0;
	int accSum = 0;
	int accArray[10];
	int i;
	
	S.initSpeakerdriver();
	
	while (1)
	{
		while (PINA & (1<<5))
		{
		}
		driveLight.drive();
		S.StartSound();
		M.setSpeed(100,1);
		PORTB |= (1<<0);
		while (P.getPosition() < 1)
		{
		}
		TCNT3 = 0;
		time = T.getTime() + 1;
		while (T.getTime() < time)
		{
		}
		M.setSpeed(1,0);
		driveLight.brake(0);
		PORTB |= (1<<1);
		while (P.getPosition() < 2)
		{
		}
		/*M.setSpeed(-1,0);
		TCNT3 = 12000;
		driveLight.brake(1);
		time = T.getTime() + 1;
		while (T.getTime() < time)
		{
		}*/
		M.setSpeed(20,0.5);
		PORTB |= (1<<2);
		for (int j=0; j<10;j++)
		{
			accArray[j] = AccY();
			accSum += accArray[j];
		}
		i = 0;
		while (accSum > -100) //-320    320
		{
			if (i == 10)
			{
				i = 0;
			}
			acc = AccY();
			accSum += (acc - accArray[i]);
			accArray[i] = acc;
			i++;
		}
		M.setSpeed(75,2);
		PORTB |= (1<<3);
		while (P.getPosition() < 3)
		{
		}
		M.setSpeed(10,0);
		for (int j=0; j<10;j++)
		{
			accArray[j] = AccY();
			accSum += accArray[j];
		}
		i = 0;
		while (accSum < 2000) //-320    320
		{
			if (i == 10)
			{
				i = 0;
			}
			acc = AccY();
			accSum += (acc - accArray[i]);
			accArray[i] = acc;
			i++;
		}
		M.setSpeed(-1,0);
		for (int j=0; j<10;j++)
		{
			accArray[j] = AccY();
			accSum += accArray[j];
		}
		i = 0;
		while (accSum < 3200) //-320    320
		{
			if (i == 10)
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
		M.setSpeed(100,2);
		PORTB |= (1<<4);
		while (P.getPosition() < 5)
		{
		}
		M.setSpeed(0,1);
		while (P.getPosition() < 6)
		{
		}
		M.setSpeed(-20,0);
		M.setSpeed(-100,2);
		while (P.getPosition() < 7)
		{
		}
		TCNT3 = 0;
		time = T.getTime() + 10;
		while (T.getTime() < time)
		{
		}
		M.setSpeed(-20,0);
		while (P.getPosition() < 8)
		{
		}
		M.setSpeed(20,0);
		M.setSpeed(100,2);
		while (P.getPosition() < 11)
		{
		}
		M.setSpeed(0,0);
		PORTB |= (1<<7);
		/*PORTB |= (1<<1);
		
		M.setSpeed(100,0);
		TCNT3 = 0;
		time = T.getTime() + 5;
		while (T.getTime() < time)
		{
		}
		M.setSpeed(50,1);
		PORTB |= (1<<3);
		while (P.getPosition() < 3)
		{
		}
		M.setSpeed(0,0);
		PORTB |= (1<<4);*/
		/*
		TCNT3 = 0;
		time = T.getTime();
		PORTB |= (1<<2);
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
		M.setSpeed(30,2);
		while (AccY() > -320) //-320    320
		{
		}
		M.setSpeed(90,3);
		PORTB |= (1<<4);
		while (P.getPosition() < 3)
		{
		}
		M.setSpeed(30,3);
		PORTB |= (1<<5);
		while (P.getPosition() < 4)
		{
		}
		M.setSpeed(100,2);
		PORTB |= (1<<6);
		while (P.getPosition() < 5)
		{
		}
		time = T.getTime();
		PORTB |= (1<<7);
		while (T.getTime() > (time+10))
		{
		}
		M.setSpeed(50,1);
		while (P.getPosition() < 6)
		{
		}
		M.setSpeed(-100,3);
		while (P.getPosition() < 7)
		{
		}
		time = T.getTime();
		while (T.getTime() > (time+10))
		{
		}
		M.setSpeed(-50,1);
		while (P.getPosition() < 8)
		{
		}
		M.setSpeed(100,3);
		while (P.getPosition() < 11)
		{
		}
		time = T.getTime();
		while (T.getTime() > (time+15))
		{
		}
		M.setSpeed(0,2);
		S.EndSound();*/
		/*time = T.getTime();
		
		time = T.getTime();
		while (T.getTime() > (time+50))
		{
		}
		M.setSpeed(0,1);
		driveLight.brake(10);*/
		
	}
	return 0;
}