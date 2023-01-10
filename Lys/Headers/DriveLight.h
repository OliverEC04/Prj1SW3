#pragma once
#include "LedDriver.h"

class DriveLight
{
	public:
		DriveLight(LedDriver frontLedDriver, LedDriver backLedDriver);
		void off();
		void drive();
		void brake();
		
	private:
		LedDriver _frontLedDriver;
		LedDriver _backLedDriver;
};