#include <avr/io.h>
#include "Headers/light.h"

int main(void)
{
	Light light = Light();
	light.on();
	
    while (1) 
    {
		light.update();
    }
}

