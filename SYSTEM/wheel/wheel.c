/********************���********************/

#include "wheel.h"  
GPIO_InitTypeDef	GPIO_InitWHEEL;


/*С�������ʼ��*/
void WHEEL_init(void)
{
	//ʹ�ܶ�Ӧ�˿ڵ�ʱ��
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOC,ENABLE);
	
	//����GPIO�Ľṹ����Ϣ
	GPIO_InitWHEEL.GPIO_Pin = GPIO_Pin_6 | GPIO_Pin_7 | GPIO_Pin_8 | GPIO_Pin_9;
	GPIO_InitWHEEL.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_InitWHEEL.GPIO_Speed = GPIO_Speed_100MHz;
	GPIO_InitWHEEL.GPIO_OType = GPIO_OType_PP;
	GPIO_InitWHEEL.GPIO_PuPd = GPIO_PuPd_NOPULL;
	
	//��ʼ��GPIO
	GPIO_Init(GPIOC, &GPIO_InitWHEEL);
	GPIO_SetBits(GPIOC, GPIO_Pin_6);
	GPIO_SetBits(GPIOC, GPIO_Pin_7);
	GPIO_SetBits(GPIOC, GPIO_Pin_8);
	GPIO_SetBits(GPIOC, GPIO_Pin_9);
}
