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
		M.setBreak(2,40,1);
		while (TIMSK1 != 0)
		{
		}
		M.setSpeed(20,0);
		driveLight.brake(0);
		PORTB |= (1<<1);
		while (P.getPosition() < 2)
		{
		}
		M.setSpeed(5,0);
		PORTB |= (1<<2);
		for (int j=0; j<10;j++)
		{
			accArray[j] = AccY();
			accSum += accArray[j];
		}
		i = 0;
		while (accSum > -200) //-320    320
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
		M.setSpeed(40,0);
		PORTB |= (1<<3);
		for (int j=0; j<10;j++)
		{
			accArray[j] = AccY();
			accSum += accArray[j];
		}
		i = 0;
		while (accSum > -3500) //-320    320
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
		M.setSpeed(75,0);
		PORTB |= (1<<4);
		while (P.getPosition() < 3)
		{
		}
		M.setSpeed(5,0);
		for (int j=0; j<10;j++)
		{
			accArray[j] = AccY();
			accSum += accArray[j];
		}
		i = 0;
		while (accSum < 600) //-3200    3200
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
		M.setSpeed(-40,0);
		PORTB |= (1<<5);
		for (int j=0; j<10;j++)
		{
			accArray[j] = AccY();
			accSum += accArray[j];
		}
		i = 0;
		while (accSum < 3500) //-320    320
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
		M.setSpeed(20,0);
		PORTB |= (1<<5);
		while (P.getPosition() < 5)
		{
		}
		TCNT3 = 0;
		time = T.getTime() + 4;
		while (T.getTime() < time)
		{
		}
		M.setBreak(2,40,1);
		while (TIMSK1 != 0)
		{
		}
		M.setSpeed(20,0);
		while (P.getPosition() < 6)
		{
		}
		M.setSpeed(-20,0);
		M.setSpeed(-100,1);
		while (P.getPosition() < 7)
		{
		}
		TCNT3 = 0;
		time = T.getTime() + 5;
		while (T.getTime() < time)
		{
		}
		M.setSpeed(-1,0);
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
	}
	return 0;
}