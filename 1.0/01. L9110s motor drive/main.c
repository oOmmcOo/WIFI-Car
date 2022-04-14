#include "reg52.h"
#include "intrins.h"

sbit RightCon1A = P3^2;
sbit RightCon1B = P3^3;

sbit LeftCon1A = P3^4;
sbit LeftCon1B = P3^5;

void Delay1000ms()		//@11.0592MHz
{
	unsigned char i, j, k;

	_nop_();
	i = 8;
	j = 1;
	k = 243;
	do
	{
		do
		{
			while (--k);
		} while (--j);
	} while (--i);
}


void goForward()
{
	LeftCon1A = 0;
	LeftCon1B = 1;
	
	RightCon1A = 0;
	RightCon1B = 1;
}

void goRight()
{
	LeftCon1A = 0;
	LeftCon1B = 1;
	
	RightCon1A = 0;
	RightCon1B = 0;
}


void goLeft()
{
	LeftCon1A = 0;
	LeftCon1B = 0;
	
	RightCon1A = 0;
	RightCon1B = 1;
}

void goBack()
{
	LeftCon1A = 1;
	LeftCon1B = 0;
	
	RightCon1A = 1;
	RightCon1B = 0;
}

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


