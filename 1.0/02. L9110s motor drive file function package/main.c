#include "motor.h"
#include "delay.h"

void main()
{
	while(1){
		goForward();
		Delay1000ms();
		Delay1000ms();
		goBack();
		Delay1000ms();
		Delay1000ms();
		goLeft();
		Delay1000ms();
		Delay1000ms();
		goRight();
		Delay1000ms();
		Delay1000ms();
	}
}


