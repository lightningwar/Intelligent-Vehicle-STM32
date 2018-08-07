/********************��ʱ��********************/

//ʾ����ÿ��200ms��LED1ʵ�ֵ�ƽ��ת

#include "timer.h"

#include "Systick.h"
#include "sys.h"
#include "usart.h"

#define LED1 PFout(10)

GPIO_InitTypeDef					GPIO_PF10;
NVIC_InitTypeDef					NVIC_PinSourcTIM3;
TIM_TimeBaseInitTypeDef  	TIM_PinSource3;


//��ʼ��LED1
void LED1_init(void)
{
	//ʹ�ܶ�Ӧ�˿ڵ�ʱ��	F��	LED1	PF10
	
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOF,ENABLE);
	
	//����GPIO�Ľṹ����Ϣ
	GPIO_PF10.GPIO_Pin = GPIO_Pin_10;
	GPIO_PF10.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_PF10.GPIO_Speed = GPIO_Speed_100MHz;
	GPIO_PF10.GPIO_OType = GPIO_OType_PP;
	GPIO_PF10.GPIO_PuPd = GPIO_PuPd_UP;
	
	//��ʼ��GPIO
	GPIO_Init(GPIOF, &GPIO_PF10);
	LED1=1;
}

//��ʼ����ʱ��
void tim3_init(void)
{
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);
	
	TIM_PinSource3.TIM_ClockDivision = TIM_CKD_DIV1 ;
	TIM_PinSource3.TIM_CounterMode = TIM_CounterMode_Up ;
	TIM_PinSource3.TIM_Prescaler = 8400-1;
	TIM_PinSource3.TIM_Period = (10000/1000)-1;
	
	TIM_TimeBaseInit(TIM3,&TIM_PinSource3);
	
	//�����ж� + NVIC
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	NVIC_PinSourcTIM3.NVIC_IRQChannel = TIM3_IRQn;
	NVIC_PinSourcTIM3.NVIC_IRQChannelPreemptionPriority = 0;
	NVIC_PinSourcTIM3.NVIC_IRQChannelSubPriority=0;
	NVIC_PinSourcTIM3.NVIC_IRQChannelCmd = ENABLE;
	
	NVIC_Init(&NVIC_PinSourcTIM3);

	TIM_ITConfig(TIM3, TIM_IT_Update, ENABLE);
	
	TIM_Cmd(TIM3, ENABLE);
}

//LED1ʵ��ÿ��200ms��ƽ��ת
void Level_Toggling(void)
{
	LED1_init();
	tim3_init();
	while(1)
	{
		
	}
}

//�жϷ�����
void TIM3_IRQHandler(void)
{
	static uint32_t i = 0;
	
	//��ȡ��־λ
	if(TIM_GetITStatus(TIM3, TIM_IT_Update)==SET)
	{
		i++;
		
		//ÿ��200ms��LED1ʵ�ֵ�ƽ��ת
		if(i >= 200)
		{
			i = 0;
			LED1 ^= 1;    //LED1 = ~LED1;
		}
		TIM_ClearITPendingBit(TIM3, TIM_IT_Update);
	}
}
