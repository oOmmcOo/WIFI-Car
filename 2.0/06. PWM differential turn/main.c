#include "motor.h"
#include "delay.h"
#include "uart.h"
#include "time.h"

extern char speedLeft;
extern char speedRight;

void main()
{
	Time0Init();
	Time1Init();
	//UartInit();
	
	while(1){
		speedLeft = 10;//10份单位时间全速运行，30份停止，所以慢，20ms是40份的500us
		speedRight = 40;
		Delay1000ms();
		Delay1000ms();
	
		speedLeft = 40;
		speedRight = 10;
		Delay1000ms();
		Delay1000ms();
	}
}


