#pragma once
#include "LedDriver.h"

class DriveLight
{
	public:
		DriveLight(LedDriver frontLedDriver, LedDriver backLedDriver);
<<<<<<< HEAD
		void off() const;
		void drive() const;
		void brake(int breaktime);
=======
		void off();
		void drive();
		void brake();
>>>>>>> 0c1fd34984301c6190ef5cf1ed804b5e384af99a
		int brakeOff;
		
	private:
		LedDriver _frontLedDriver;
		LedDriver _backLedDriver;
};