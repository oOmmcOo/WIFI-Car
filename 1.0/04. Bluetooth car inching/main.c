#include "motor.h"
#include "delay.h"
#include "uart.h"

void main()
{
	UartInit();
	
	while(1){
		stop();
	}
}


