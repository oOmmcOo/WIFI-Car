/****  Author: 上官可编程(抖音) ************
 ****  录播课堂代码，为小白学习功能实现 ****
 ****	 代码合理性和效率不做评估 ************
 ****  2022/3/22 3:35 **********************
********************************************/

#include "motor.h"
#include "delay.h"
#include "uart.h"
#include "reg52.h"
#include "time.h"
#include "stdio.h"

sbit speedIO = P3^2;//外部中断0
unsigned int speedCnt = 0; //统计格子，脉冲次数
extern unsigned int speed;//速度
extern char signal; //主程序发速度数据的通知
char speedMes[24];  //主程序发送速度数据的字符串缓冲区

void Ex0Init()
{
	EX0 = 1;//允许中断
	//EA = 1;在串口初始化函数中已经打开了总中断
	IT0 = 1;//外部中断的下降沿触发
}

void main()
{
	Time0Init();//定时器0初始化
	UartInit();//串口相关初始化
	//外部中断初始化
	Ex0Init();
	
	while(1){
		if(signal){//定时器1s到点，把signal置一，主程序发送速度
			sprintf(speedMes,"speed:%d cm/s",speed);//串口数据的字符串拼装，speed是格子，每个格子1cm
			SendString(speedMes);//速度发出去
			signal = 0;//清0speed,下次由定时器1s后的中断处理中再置一
		}
	}
}

void speedHandler() interrupt 0 //外部中断处理函数
{
	speedCnt++;//码盘转动了一个格子
}


