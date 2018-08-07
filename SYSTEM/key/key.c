/********************按键********************/

#include "key.h"  
GPIO_InitTypeDef  GPIO_InitKEY;


/*按键初始化*/
void KEY_init(void)
{
	//使能对应端口的时钟
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA | RCC_AHB1Periph_GPIOE,ENABLE);
	
	//设置GPIO的结构体信息
	GPIO_InitKEY.GPIO_Pin = GPIO_Pin_0;
	GPIO_InitKEY.GPIO_Mode = GPIO_Mode_IN;
	GPIO_InitKEY.GPIO_Speed = GPIO_Speed_100MHz;
	GPIO_InitKEY.GPIO_OType = GPIO_OType_PP;
	GPIO_InitKEY.GPIO_PuPd = GPIO_PuPd_UP;
	
	//初始化GPIO
	GPIO_Init(GPIOA, &GPIO_InitKEY);
	
	//设置GPIO的结构体信息
	GPIO_InitKEY.GPIO_Pin = GPIO_Pin_2 | GPIO_Pin_3 | GPIO_Pin_4;
	
	//初始化GPIO
	GPIO_Init(GPIOE, &GPIO_InitKEY);
}
