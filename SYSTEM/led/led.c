/********************LED********************/

#include "led.h"  
GPIO_InitTypeDef	GPIO_InitLED;


/*LED�Ƴ�ʼ��*/
void LED_init(void)
{
	//ʹ�ܶ�Ӧ�˿ڵ�ʱ��  
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOF|RCC_AHB1Periph_GPIOE,ENABLE);
	
	//����GPIO�Ľṹ����Ϣ
	GPIO_InitLED.GPIO_Pin = GPIO_Pin_9|GPIO_Pin_10;
	GPIO_InitLED.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_InitLED.GPIO_Speed = GPIO_Speed_100MHz;
	GPIO_InitLED.GPIO_OType = GPIO_OType_PP;
	GPIO_InitLED.GPIO_PuPd = GPIO_PuPd_UP;
	
	//��ʼ��GPIO
	GPIO_Init(GPIOF, &GPIO_InitLED);
	
	//����GPIO�Ľṹ����Ϣ
	GPIO_InitLED.GPIO_Pin = GPIO_Pin_13|GPIO_Pin_14;
	
	//��ʼ��GPIO
	GPIO_Init(GPIOE, &GPIO_InitLED);
	
	//��LED��Ϊ�ߵ�ƽ����
	GPIO_SetBits(GPIOF, GPIO_Pin_9);//LED0��
	GPIO_SetBits(GPIOF, GPIO_Pin_10);//LED1��
	GPIO_SetBits(GPIOE, GPIO_Pin_13);//LED2��
	GPIO_SetBits(GPIOE, GPIO_Pin_14);//LED3��
}
