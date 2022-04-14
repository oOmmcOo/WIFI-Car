#include "reg52.h"
#include "motor.h"
#include "string.h"
#include "delay.h"
sbit D5 = P3^7;
#define SIZE 12

sfr AUXR = 0x8E;
char buffer[SIZE];

void UartInit(void)		//9600bps@11.0592MHz
{
	AUXR = 0x01;
	SCON = 0x50; //配置串口工作方式1，REN使能接收
	TMOD &= 0xF0;
	TMOD |= 0x20;//定时器1工作方式位8位自动重装
	
	TH1 = 0xFD;
	TL1 = 0xFD;//9600波特率的初值
	TR1 = 1;//启动定时器
	
	EA = 1;//开启总中断
	ES = 1;//开启串口中断
}

//M1qian  M2 hou M3 zuo  M4 you
void Uart_Handler() interrupt 4
{
	static int i = 0;//静态变量，被初始化一次
	char tmp;

	if(RI)//中断处理函数中，对于接收中断的响应
	{
			RI = 0;//清除接收中断标志位
			tmp = SBUF;
			if(tmp == 'M'){
				i = 0;
			}
			buffer[i++] = tmp;
		
			//灯控指令
			if(buffer[0] == 'M'){
				switch(buffer[1]){
					case '1':
						goForward();
						Delay10ms();
						break;
					case '2':
						goBack();
						Delay10ms();
						break;
					case '3':
						goLeft();
						Delay10ms();
						break;
					case '4':
						goRight();
						Delay10ms();
						break;
					default:
						stop();
						break;
				}
			}
		
			if(i == 12) {
				memset(buffer, '\0', SIZE);
				i = 0;
			}
	}
		
}