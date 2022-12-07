#include <avr/io.h>

enum LightState
{
	Off = 0,
	On = 1,
	Brake = 2	
};

class Light
{
	public:
		Light();
		void on();
		void off();
		void brake();
		void update();
		
	private:
		LightState state;
		int tick;
};