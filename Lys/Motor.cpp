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
	char targetDirection = M.getTargetDirection();
	if ((OCR4A != targetOCR) || ((PORTH & (1<<4)) != targetDirection))
	{
		if ((OCR4A >= 24000) && ((PORTH & (1<<4)) != targetDirection))
		{
			PORTH ^= (1<<4);
			OCR4A = 23980;
		}
		else if ((OCR4A < targetOCR) || ((PORTH & (1<<4)) != targetDirection))
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

ISR(TIMER1_COMPA_vect)
{
	OCR4A = 32000;
	if (M.getCurrentBreak()>0)
	{
		OCR1B = 12500 - 125*M.getBreakForce();
	}
	if (M.getBreaks() <= M.getCurrentBreak())
	{
		TIMSK1 = 0b00000000;
		TIMSK5 = 0b00000001;
	}
}

ISR(TIMER1_COMPB_vect)
{
	if (M.getBreakDirection() != 0)
	{
		PORTH |= (1<<4);
		OCR4A = 31500;
	} 
	else
	{
		PORTH &= ~(1<<4);
		OCR4A = 31500;
	}
	M.setCurrentBreak(M.getCurrentBreak()+1);
}

// default constructor
Motor::Motor()
{
	// motor PWM
	DDRH |= 0b00011000;
	TCCR4A = 0b11000010;
	TCCR4B = 0b00011001;
	ICR4 = 31999;
	OCR4A = 32000;
	PORTH &= ~(1<<4);
	
	// interupt timer
	TCCR5A = 0b00000001;
	TCCR5B = 0b00010011;
	OCR5A = 12500 - 1; // 0.1 s
	TIMSK5 = 0b00000001;
	
	// break timer
	TCCR1A = 0b00000001;
	TCCR1B = 0b00010011;
	OCR1A = 12500 - 1;//32437; // 1.038 s
	
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
		targetDirection_ = 0b00010000;
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
		if (targetDirection_)
		{
			PORTH |= targetDirection_;
		}
		else
		{
			PORTH &= ~(1<<4);
		}
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

void Motor::setBreak(int breaks, int breakForce, char breakDirection)
{
	TCNT1 = 0;
	TIFR1 = 0b00000111;
	
	currentBreak_ = 0;
	
	if (breakForce < 0)
	{
		breakForce_ = 0;
	} 
	else if (breakForce > 100)
	{
		breakForce_ = 100;
	}
	else
	{
		breakForce_ = breakForce;
	}
	
	OCR1B = 12500 - 60*breakForce_;
	
	breakDirection_ = breakDirection;
	
	if (breaks > 0)
	{
		breaks_ = breaks;
		TIMSK1 = 0b00000110;
		TIMSK5 = 0b00000000;
		OCR4A = 32000;
	}
	else
	{
		breaks_ = 0;
	}
}

int Motor::getBreaks() const
{
	return breaks_;
}

int Motor::getBreakForce() const
{
	return breakForce_;
}

char Motor::getBreakDirection() const
{
	return breakDirection_;
}

int Motor::getCurrentBreak() const
{
	return currentBreak_;
}

void Motor::setCurrentBreak(int currentBreak)
{
	currentBreak_ = currentBreak;
}