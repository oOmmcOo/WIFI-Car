#include "motor.h"
#include "reg52.h"

extern unsigned int speedCnt;
unsigned int speed;
char signal = 0;
unsigned int cnt = 0;

void Time0Init()
{
	//1. 配置定时器0工作模式位16位计时
	TMOD = 0x01;
	//2. 给初值，定一个0.5出来
	TL0=0x33;
	TH0=0xFE;
	//3. 开始计时
	TR0 = 1;
	TF0 = 0;
	//4. 打开定时器0中断
	ET0 = 1;
	//5. 打开总中断EA
	EA = 1;
}

void Time0Handler() interrupt 1
{
	cnt++;  //统计爆表的次数. cnt=1的时候，报表了1
	//重新给初值
	TL0=0x33;
	TH0=0xFE;
	
	if(cnt == 2000){//爆表2000次，经过了1s
		signal = 1;
		cnt = 0;  //当100次表示1s，重新让cnt从0开始，计算下一次的1s
		//计算小车的速度，也就是拿到speedCnt的值
		speed = speedCnt;
		speedCnt = 0;//1秒后拿到speedCnt个格子，就能算出这1s的速度，格子清零
	}
		
}