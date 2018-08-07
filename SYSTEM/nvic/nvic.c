/********************�жϿ�����********************/

//�ж�ʹKEY0����LED0

#include "nvic.h"
#include "Systick.h"
#include "sys.h"
#include "usart.h"

GPIO_InitTypeDef		GPIO_Pin9;
GPIO_InitTypeDef		KEY_InitStructure0;
EXTI_InitTypeDef		EXTI_PinSourceEXTI0;
NVIC_InitTypeDef		NVIC_PinSourceEXTI0;

#define LED0   PFout(9)

//��ʼ��LED0
void NVIC_LED0_init(void)
{
	//ʹ�ܶ�Ӧ�˿ڵ�ʱ��	F��	LED0	PF9
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOF,ENABLE);
	//����GPIO�Ľṹ����Ϣ
	GPIO_Pin9.GPIO_Pin = GPIO_Pin_9;
	GPIO_Pin9.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_Pin9.GPIO_Speed = GPIO_Speed_100MHz;
	GPIO_Pin9.GPIO_OType = GPIO_OType_PP;
	GPIO_Pin9.GPIO_PuPd = GPIO_PuPd_UP;
	//��ʼ��GPIO
	GPIO_Init(GPIOF, &GPIO_Pin9);
	LED0=1;
}

//��ʼ��KEY0
void NVIC_KEY0_init(void)
{
	//ʹ�ܶ�Ӧ�˿ڵ�ʱ��
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA,ENABLE);
	
	//����GPIO�Ľṹ����Ϣ
	KEY_InitStructure0.GPIO_Pin = GPIO_Pin_0;
	KEY_InitStructure0.GPIO_Mode = GPIO_Mode_IN;
	KEY_InitStructure0.GPIO_Speed = GPIO_Speed_100MHz;
	KEY_InitStructure0.GPIO_OType = GPIO_OType_PP;
	KEY_InitStructure0.GPIO_PuPd = GPIO_PuPd_UP;
	
	//��ʼ��GPIO
	GPIO_Init(GPIOA, &KEY_InitStructure0);
}

//�����жϵ�EXTI
void exti_init(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_SYSCFG, ENABLE);
	
	SYSCFG_EXTILineConfig(EXTI_PortSourceGPIOA, EXTI_PinSource0);
	
	EXTI_PinSourceEXTI0.EXTI_Line = EXTI_Line0;

	EXTI_PinSourceEXTI0.EXTI_Mode = EXTI_Mode_Interrupt;
	EXTI_PinSourceEXTI0.EXTI_Trigger = EXTI_Trigger_Rising_Falling;
	EXTI_PinSourceEXTI0.EXTI_LineCmd = ENABLE;
	
	//��ʼ��EXTI
	EXTI_Init(&EXTI_PinSourceEXTI0);

}

//�����жϵ�NVIC
void nvic_init(void)
{
	NVIC_PinSourceEXTI0.NVIC_IRQChannel = EXTI0_IRQn;
	NVIC_PinSourceEXTI0.NVIC_IRQChannelPreemptionPriority = 0;
	NVIC_PinSourceEXTI0.NVIC_IRQChannelSubPriority=0;
	NVIC_PinSourceEXTI0.NVIC_IRQChannelCmd = ENABLE;
	
	//��ʼ��NVIC
	NVIC_Init(&NVIC_PinSourceEXTI0);
}

//KEY0����LED0
void NVIC_KEY0_LED0_exINT(void)
{
	NVIC_LED0_init();
	NVIC_KEY0_init();
	exti_init();
	nvic_init();
	while(1)
	{
		
	}
}

//�жϷ�����
void EXTI0_IRQHandler(void)
{
	//��ȡ�ж���EXTI_Line0���ж��Ƿ���
	if(EXTI_GetITStatus(EXTI_Line0)==SET)
	{
		LED0=0;
		//����ж���EXTI_Line0���жϱ�־
		EXTI_ClearITPendingBit(EXTI_Line0);
	}
} 

void EXTI2_IRQHandler(void)
{
	//��ȡ�ж���EXTI_Line2�ϵ��ж��Ƿ���
	if(EXTI_GetITStatus(EXTI_Line2)==SET)
	{
		LED0=0;
		//����ж���EXTI_Line2�ϵ��жϱ�־
		EXTI_ClearITPendingBit(EXTI_Line2);
	}
} 
