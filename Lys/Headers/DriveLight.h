#pragma once
#include "LedDriver.h"

class DriveLight
{
	public:
		DriveLight(LedDriver frontLedDriver, LedDriver backLedDriver);
		void off() const;
		void drive() const;
		void brake() const;
		
	private:
		LedDriver _frontLedDriver;
		LedDriver _backLedDriver;
};