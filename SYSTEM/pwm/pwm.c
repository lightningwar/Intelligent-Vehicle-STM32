/********************脉冲宽度调制********************/

//示例：PWM控制LED0的亮度

#include "pwm.h"
#include "Systick.h"
#include "sys.h"
#include "usart.h"

GPIO_InitTypeDef					GPIO_PF9;
TIM_TimeBaseInitTypeDef  	TIM_PinSource14;
TIM_OCInitTypeDef					TIM_OCInitStruct;

#define LED0   PFout(9)


//初始化LED0
void LED0_init(void)
{
	//使能对应端口的时钟	F组	LED0	PF9
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOF,ENABLE);
	
	//设置GPIO的结构体信息
	GPIO_PF9.GPIO_Pin = GPIO_Pin_9;
	GPIO_PF9.GPIO_Mode = GPIO_Mode_AF;
	GPIO_PF9.GPIO_Speed = GPIO_Speed_100MHz;
	GPIO_PF9.GPIO_OType = GPIO_OType_PP;
	GPIO_PF9.GPIO_PuPd = GPIO_PuPd_UP;
	
	//初始化GPIO
	GPIO_Init(GPIOF, &GPIO_PF9);
}

//初始化对应引脚的PWM
void tim14_init(void)
{
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM14, ENABLE);
	
	GPIO_PinAFConfig(GPIOF, GPIO_PinSource9,GPIO_AF_TIM14);
	
	TIM_PinSource14.TIM_ClockDivision = TIM_CKD_DIV1 ;
	TIM_PinSource14.TIM_CounterMode = TIM_CounterMode_Up ;
	TIM_PinSource14.TIM_Prescaler = 8400-1;
	TIM_PinSource14.TIM_Period = (10000/100)-1;
	TIM_TimeBaseInit(TIM14,&TIM_PinSource14);

	TIM_OCInitStruct.TIM_OCMode = TIM_OCMode_PWM1;
	TIM_OCInitStruct.TIM_OutputState = TIM_OutputState_Enable ;
	TIM_OCInitStruct.TIM_OCPolarity = TIM_OCPolarity_High;
	TIM_OC1Init(TIM14, &TIM_OCInitStruct);
	
	TIM_OC1PreloadConfig(TIM14, TIM_OCPreload_Enable);
	
	TIM_ARRPreloadConfig(TIM14,ENABLE);
	
	TIM_Cmd(TIM14, ENABLE);
}

//LED0亮度调节
void Dimming(void)
{
	int i=0;
	LED0_init();
	tim14_init();
	Systick_init(168);
	LED0=0;
	while(1)
	{
		for(i=0;i<50;i++)
		{
			TIM_SetCompare1(TIM14, i);
			delay_ms(20);
		}
		
		for(i=50;i>0;i--)
		{
			TIM_SetCompare1(TIM14, i);
			delay_ms(20);
		}
	}
}
