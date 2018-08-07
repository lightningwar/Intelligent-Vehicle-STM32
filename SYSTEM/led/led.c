/********************LED********************/

#include "led.h"  
GPIO_InitTypeDef	GPIO_InitLED;


/*LED灯初始化*/
void LED_init(void)
{
	//使能对应端口的时钟  
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOF|RCC_AHB1Periph_GPIOE,ENABLE);
	
	//设置GPIO的结构体信息
	GPIO_InitLED.GPIO_Pin = GPIO_Pin_9|GPIO_Pin_10;
	GPIO_InitLED.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_InitLED.GPIO_Speed = GPIO_Speed_100MHz;
	GPIO_InitLED.GPIO_OType = GPIO_OType_PP;
	GPIO_InitLED.GPIO_PuPd = GPIO_PuPd_UP;
	
	//初始化GPIO
	GPIO_Init(GPIOF, &GPIO_InitLED);
	
	//设置GPIO的结构体信息
	GPIO_InitLED.GPIO_Pin = GPIO_Pin_13|GPIO_Pin_14;
	
	//初始化GPIO
	GPIO_Init(GPIOE, &GPIO_InitLED);
	
	//将LED设为高电平（灭）
	GPIO_SetBits(GPIOF, GPIO_Pin_9);//LED0灭
	GPIO_SetBits(GPIOF, GPIO_Pin_10);//LED1灭
	GPIO_SetBits(GPIOE, GPIO_Pin_13);//LED2灭
	GPIO_SetBits(GPIOE, GPIO_Pin_14);//LED3灭
}
