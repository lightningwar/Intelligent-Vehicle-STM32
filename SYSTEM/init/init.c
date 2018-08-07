#include "init.h"
#include "systick.h"
#include "usart.h"
#include "led.h"
#include "beep.h"
#include "key.h"
#include "wave.h"
#include "wheel.h"


//初始化函数
void INIT(void)
{
	LED_init();						//LED灯初始化
	KEY_init();						//按键初始化
	BEEP_init();					//喇叭初始化
	WHEEL_init();					//小车车轮电机初始化
	WAVE_init();					//超声波模块初始化
	Systick_init(168);		//系统时钟频率168MHZ
	uart_init(9600);			//蓝牙模块波特率9600bps
}
