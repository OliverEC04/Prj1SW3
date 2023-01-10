/* 
* Timer.cpp
*
* Created: 05/01/2023 14.04.04
* Author: terke
*/


#include "Headers/Timer.h"

Timer T;

ISR(TIMER3_OVF_vect)
{
	T.setTime(T.getTime()+1);
	PORTB = T.getTime();
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
	
	time10ms_ = 0;
} //Timer

// default destructor
Timer::~Timer()
{
} //~Timer

void Timer::setTime(unsigned char time)
{
	time10ms_ = time;
}

int Timer::getTime() const
{
	return time10ms_;
}