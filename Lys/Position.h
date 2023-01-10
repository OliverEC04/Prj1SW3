/* 
* Position.h
*
* Created: 09/01/2023 11:00:59
* Author: terke
*/

#include <avr/interrupt.h>

#ifndef __POSITION_H__
#define __POSITION_H__


class Position
{
//variables
public:
protected:
private:
	int position_;
	int lastTime_;

//functions
public:
	Position();
	~Position();
	void setPosition(int position);
	int getPosition() const;
	void setLastTime(int time);
	int getLastTime() const;
protected:
private:
	Position( const Position &c );
	Position& operator=( const Position &c );

}; //Position

#endif //__POSITION_H__
