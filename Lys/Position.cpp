/* 
* Position.cpp
*
* Created: 09/01/2023 11:00:58
* Author: terkel
*/

#include "Headers/Timer.h"
extern Timer T;

#include "Headers/CrownLight.h"
extern CrownLight crownLight;

#include "Headers/Position.h"

Position P;



ISR(INT0_vect)
{
	if (T.getTime() >= (P.getLastTime()+5))
	{
		P.setPosition(P.getPosition()+1);
		P.setLastTime(T.getTime());
		
		crownLight.countUp();
	}
}

ISR(INT1_vect)
{
	if (T.getTime() >= (P.getLastTime()+5))
	{
		P.setPosition(P.getPosition()+1);
		P.setLastTime(T.getTime());
		
		crownLight.countUp();
	}
}

// default constructor
Position::Position()
{
	DDRD &= 0b11111100;
	EICRA |= 0b00001111;
	EIMSK |= 0b00000011;
	position_ = 0;
	lastTime_ = 0;
} //Position

// default destructor
Position::~Position()
{
} //~Position

void Position::setPosition(int position)
{
	position_ = position;
}

int Position::getPosition() const
{
	return position_;
}

void Position::setLastTime(int time)
{
	lastTime_ = time;
}

int Position::getLastTime() const
{
	return lastTime_;
}
