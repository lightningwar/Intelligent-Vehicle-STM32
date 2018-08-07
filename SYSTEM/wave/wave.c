/********************超声波********************/

#include "wave.h"  
GPIO_InitTypeDef	GPIO_InitWAVE;


/*超声波模块初始化*/
void WAVE_init(void)
{
	//使能对应端口的时钟
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB | RCC_AHB1Periph_GPIOE,ENABLE);
	
	//设置GPIO的结构体信息
	GPIO_InitWAVE.GPIO_Pin = GPIO_Pin_6;
	GPIO_InitWAVE.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_InitWAVE.GPIO_Speed = GPIO_Speed_100MHz;
	GPIO_InitWAVE.GPIO_OType = GPIO_OType_PP;
	GPIO_InitWAVE.GPIO_PuPd = GPIO_PuPd_UP;
	
	//初始化GPIO
	GPIO_Init(GPIOB, &GPIO_InitWAVE);
	GPIO_InitWAVE.GPIO_Pin = GPIO_Pin_6;
	GPIO_InitWAVE.GPIO_Mode = GPIO_Mode_IN;
	GPIO_Init(GPIOE, &GPIO_InitWAVE);
}
