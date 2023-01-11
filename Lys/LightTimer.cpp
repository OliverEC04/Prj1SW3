#include <avr/io.h>
#include <avr/interrupt.h>
/*
#include "Headers/LightTimer.h"
#include "Headers/Types.h"

// Delay maa maks vaere 4000 ms (4 sek)

LightTimer lightTimer;

Event::Event(int _ms, void (*_callback)())
{
	ms = _ms;
	callback = _callback;
}

Event 

ISR (TIMER1_OVF_vect)
{
	if (nextEvent->ms == 0)
	{
		TIMSK1 = 0;
	}
	else
	{
		(nextEvent->callback)();
		
		nextEvent = nextEvent->nextEvent;
		
		lightTimer.setTimer(nextEvent->ms);
	}
}

LightTimer::LightTimer()
{
	TCCR1A = 0b00000000;
	TCCR1B = 0b00000101;
}

void LightTimer::addEvent(int ms, void (*callback)())
{
	Event *preEvent = nextEvent;
	
	// Hvis dette event er det eneste
	if (nextEvent->ms == 0)
	{
		nextEvent->ms = ms;
		nextEvent->callback = callback;
		
		setTimer(ms);
		
		return;
	}
	
	// Ellers find den rigtige plads i listen (sorteret efter ms)
	while (preEvent->ms != 0 || ms >= 0)
	{
		if (ms - preEvent->ms < 0)
		{
			break;
		}
		else if (ms - preEvent->ms == 0) // Det her må helst ikke ske
		{
			ms++;
		}
		ms -= preEvent->ms;
		preEvent = preEvent->nextEvent;
	}
	
	newEvent->ms = ms;
	newEvent->callback = callback;
	newEvent->nextEvent = preEvent->nextEvent;
	
	preEvent->nextEvent = newEvent;
	
	newEvent->nextEvent->ms -= ms;
}

void LightTimer::setTimer(int ms)
{
	uint8 x = 65536 - ms / 64000;
	
	TIMSK1 = 1 << 0;
	TCNT1 = 65535 - x;
}
*/