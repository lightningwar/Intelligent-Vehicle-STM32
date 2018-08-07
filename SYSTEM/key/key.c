/********************����********************/

#include "key.h"  
GPIO_InitTypeDef  GPIO_InitKEY;


/*������ʼ��*/
void KEY_init(void)
{
	//ʹ�ܶ�Ӧ�˿ڵ�ʱ��
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA | RCC_AHB1Periph_GPIOE,ENABLE);
	
	//����GPIO�Ľṹ����Ϣ
	GPIO_InitKEY.GPIO_Pin = GPIO_Pin_0;
	GPIO_InitKEY.GPIO_Mode = GPIO_Mode_IN;
	GPIO_InitKEY.GPIO_Speed = GPIO_Speed_100MHz;
	GPIO_InitKEY.GPIO_OType = GPIO_OType_PP;
	GPIO_InitKEY.GPIO_PuPd = GPIO_PuPd_UP;
	
	//��ʼ��GPIO
	GPIO_Init(GPIOA, &GPIO_InitKEY);
	
	//����GPIO�Ľṹ����Ϣ
	GPIO_InitKEY.GPIO_Pin = GPIO_Pin_2 | GPIO_Pin_3 | GPIO_Pin_4;
	
	//��ʼ��GPIO
	GPIO_Init(GPIOE, &GPIO_InitKEY);
}
