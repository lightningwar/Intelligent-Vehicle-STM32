/********************电机********************/

#include "wheel.h"  
GPIO_InitTypeDef	GPIO_InitWHEEL;


/*小车电机初始化*/
void WHEEL_init(void)
{
	//使能对应端口的时钟
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOC,ENABLE);
	
	//设置GPIO的结构体信息
	GPIO_InitWHEEL.GPIO_Pin = GPIO_Pin_6 | GPIO_Pin_7 | GPIO_Pin_8 | GPIO_Pin_9;
	GPIO_InitWHEEL.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_InitWHEEL.GPIO_Speed = GPIO_Speed_100MHz;
	GPIO_InitWHEEL.GPIO_OType = GPIO_OType_PP;
	GPIO_InitWHEEL.GPIO_PuPd = GPIO_PuPd_NOPULL;
	
	//初始化GPIO
	GPIO_Init(GPIOC, &GPIO_InitWHEEL);
	GPIO_SetBits(GPIOC, GPIO_Pin_6);
	GPIO_SetBits(GPIOC, GPIO_Pin_7);
	GPIO_SetBits(GPIOC, GPIO_Pin_8);
	GPIO_SetBits(GPIOC, GPIO_Pin_9);
}
