#pragma once

//struct Event
//{
	//int ms;
	//void (*callback)();
	//Event *nextEvent;
	//
	//Event(int ms, void (*callback)());
//}*nextEvent, *newEvent;
//
//class LightTimer
//{
	//public:
		//LightTimer();
		//void addEvent(int ms, void (*callback)());
		//void setTimer(int ms);
		//
	//private:
		//Event *preEvent;
//};

class LightTimer
{
	public:
		LightTimer();
		void event(int ms);
};