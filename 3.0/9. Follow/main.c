#include "motor.h"
#include "delay.h"
#include "reg52.h"

//sbit leftSensor = P2^7;
//sbit rightSensor = P2^6;

sbit leftSensor = P2^5;
sbit rightSensor = P2^4;

void main()
{

	while(1){
		if(leftSensor == 0 && rightSensor == 0){
			goForward();
		}
		if(leftSensor == 1 && rightSensor == 0){
			goRight();
		}
		
		if(leftSensor == 0 && rightSensor == 1){
			
			goLeft();
		}
		
		if(leftSensor == 1 && rightSensor == 1){
			//停
			stop();
		}
	}
}


