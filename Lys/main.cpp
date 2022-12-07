#include <avr/io.h>
#include "Headers/light.h"
#include "Headers/uart_int.h"

int main(void)
{
    int i = 0;
	
	Light light = Light();
	
    while (1) 
    {
		if (i < 1000)
		{
			light.on();			
		}
		else
		{
			light.off();
		}
		
		light.update();
		
		i++;
    }
}

