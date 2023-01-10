/* 
* Timer.h
*
* Created: 05/01/2023 14.04.04
* Author: terke
*/

#include <avr/io.h>
#include <avr/interrupt.h>

#ifndef __TIMER_H__
#define __TIMER_H__


class Timer
{
//variables
public:
protected:
private:
unsigned char time10ms_;

//functions
public:
	Timer();
	~Timer();
	void setTime(unsigned char time);
	int getTime() const;
protected:
private:
	Timer( const Timer &c );
	Timer& operator=( const Timer &c );

}; //Timer

#endif //__TIMER_H__
