/* 
* Motor.cpp
*
* Created: 08/12/2022 09.53.10
* Author: terke
*/


#include "Headers/Motor.h"

#include "Headers/mma8652.h"

Motor M;
// if ((OCR4A != M.getTargetOCR()) || ((PORTH & (1<<0)) != M.getTargetDirection()))
ISR(TIMER5_OVF_vect)
{
	unsigned int targetOCR = M.getTargetOCR();
	int targetDirection = M.getTargetDirection();
	if ((OCR4A != targetOCR) || ((PORTH & (1<<0)) != targetDirection))
	{
		if ((OCR4A >= 24000) && ((PORTH & (1<<0)) != targetDirection))
		{
			PORTH ^= (1<<0);
			OCR4A = 23980;
		}
		else if ((OCR4A < targetOCR) || ((PORTH & (1<<0)) != targetDirection))
		{
			OCR4A += 20;
			if (OCR4A >= 24000)
			{
				OCR4A = 32000;
			}
		} 
		else
		{
			if (OCR4A >= 24000)
			{
				OCR4A = 23980;
			}
			OCR4A -= 20;
		}
	}
}

// default constructor
Motor::Motor()
{
	// motor PWM
	DDRH |= 0b00001001;
	TCCR4A = 0b11000010;
	TCCR4B = 0b00011001;
	ICR4 = 31999;
	OCR4A = 32000;
	PORTH &= ~(1<<0);
	
	// interupt timer
	TCCR5A = 0b00000001;
	TCCR5B = 0b00010011;
	OCR5A = 12500 - 1; // 0.1 s
	TIMSK5 = 0b00000001;
	
	initAcc();
	
	targetOCR_ = 32000;
	
	targetDirection_ = 0;
	
	speed_ = 0;
} //Motor

// default destructor
Motor::~Motor()
{
	OCR4A = 32000;
} //~Motor

void Motor::setSpeed(int speed, double time)
{
	// set targetOCR_
	if (speed < 0)
	{
		targetDirection_ = 1;
		if (speed < -100)
		{
			targetOCR_ = 0;
		} 
		else
		{
			targetOCR_ = 24000 + speed*240;
		}
	} 
	else
	{
		targetDirection_ = 0;
		if (speed > 100)
		{
			targetOCR_ = 0;
		}
		else if (speed == 0)
		{
			targetOCR_ = 32000;
		}
		else
		{
			targetOCR_ = 24000 - speed*240;
		}
	}
	if (time == 0)
	{
		OCR4A = targetOCR_;
		PORTH |= targetDirection_;
	}
	else if ((31250*time-3*(abs(speed-speed_)))/(3*(abs(speed-speed_))) >= 65535)
	{
		OCR5A = 65535;
	}
	else
	{
		OCR5A = (31250*time-3*(abs(speed-speed_)))/(3*(abs(speed-speed_)));
	}
	
	speed_ = speed;
}

unsigned int Motor::getTargetOCR() const
{
	return targetOCR_;
}

char Motor::getTargetDirection() const
{
	return targetDirection_;
}