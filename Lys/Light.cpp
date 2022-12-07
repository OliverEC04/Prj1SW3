#include "Headers/light.h"

Light::Light()
{
	tick = 0;
	DDRH = 0xFF;
}

void Light::on()
{
	state = On;
}

void Light::off()
{
	state = Off;
}

void Light::brake()
{
	state = Brake;
}

void Light::update()
{
	switch(state)
	{
		case Off:
			PORTH &= 0b10011111;
			break;
			
		case On:
			if(tick % 3 == 0)
			{
				PORTH |= 0b01000000;
			}
			else
			{
				PORTH &= 0b10111111;
			}
			if(tick % 6 == 0)
			{
				PORTH |= 0b00100000;
			}
			else
			{
				PORTH &= 0b11011111;
			}
			
			break;
			
		case Brake:
			if(tick % 2 == 0)
			{
				PORTH |= 0b01000000;
			}
			else
			{
				PORTH &= 0b10111111;
			}
			if(tick % 2 == 0)
			{
				PORTH |= 0b00100000;
			}
			else
			{
				PORTH &= 0b11011111;
			}
			
			break;
	}
	
	tick++;
	
	if(tick > 64000)
	{
		tick = 0;
	}
}
