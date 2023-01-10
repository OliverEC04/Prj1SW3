/* 
* Motor.h
*
* Created: 08/12/2022 09.53.10
* Author: terke
*/

#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdlib.h>

#ifndef __MOTOR_H__
#define __MOTOR_H__


class Motor
{
//variables
public:
protected:
private:
	unsigned int targetOCR_;
	char targetDirection_; //0 er frem 1 er tilbage
	int speed_; // hvad hastighedden var sidst
	

//functions
public:
	Motor();
	~Motor();
	void setSpeed(int speed, double time);
	unsigned int getTargetOCR() const;
	char getTargetDirection() const;
protected:
private:
	Motor( const Motor &c );
	Motor& operator=( const Motor &c );

}; //Motor

#endif //__MOTOR_H__
