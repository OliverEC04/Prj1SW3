/* 
* Timer.cpp
*
* Created: 05/01/2023 14.04.04
* Author: terke
*/

#include "Headers/DriveLight.h"
extern DriveLight driveLight;

#include "Headers/Timer.h"

Timer T;

ISR(TIMER3_OVF_vect)
{
	T.setTime(T.getTime()+1);
	//PORTB = T.getTime();
	
	if (T.getTime() == driveLight.brakeOff)
	{
		driveLight.drive();
	}
}

// default constructor
Timer::Timer()
{
	DDRB = 0xFF;			//Port B output
	PORTB = 0;
	
	// interupt timer
	TCCR3A = 0b00000001;
	TCCR3B = 0b00010011;
	OCR3A = 12500 - 1; // 0.1 s
	TIMSK3 = 0b00000001;
	sei();
	
	time100ms_ = 0;
} //Timer

// default destructor
Timer::~Timer()
{
} //~Timer

void Timer::setTime(unsigned int time)
{
	time100ms_ = time;
}

int Timer::getTime() const
{
	return time100ms_;
}