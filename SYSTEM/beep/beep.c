/********************蜂鸣器********************/

#include "beep.h"
GPIO_InitTypeDef	GPIO_InitBEEP;


/*蜂鸣器初始化*/
void BEEP_init(void)
{
	//使能对应端口的时钟
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOF,ENABLE);
	
	//设置GPIO的结构体信息
	GPIO_InitBEEP.GPIO_Pin = GPIO_Pin_8;
	GPIO_InitBEEP.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_InitBEEP.GPIO_Speed = GPIO_Speed_100MHz;
	GPIO_InitBEEP.GPIO_OType = GPIO_OType_PP;
	GPIO_InitBEEP.GPIO_PuPd = GPIO_PuPd_UP;
	
	//初始化GPIO
	GPIO_Init(GPIOF, &GPIO_InitBEEP);
	
	//将蜂鸣器设为低电平（不响）
	GPIO_ResetBits(GPIOF, GPIO_Pin_8);//蜂鸣器不响
}
