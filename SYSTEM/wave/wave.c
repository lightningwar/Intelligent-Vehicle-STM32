/********************������********************/

#include "wave.h"  
GPIO_InitTypeDef	GPIO_InitWAVE;


/*������ģ���ʼ��*/
void WAVE_init(void)
{
	//ʹ�ܶ�Ӧ�˿ڵ�ʱ��
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB | RCC_AHB1Periph_GPIOE,ENABLE);
	
	//����GPIO�Ľṹ����Ϣ
	GPIO_InitWAVE.GPIO_Pin = GPIO_Pin_6;
	GPIO_InitWAVE.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_InitWAVE.GPIO_Speed = GPIO_Speed_100MHz;
	GPIO_InitWAVE.GPIO_OType = GPIO_OType_PP;
	GPIO_InitWAVE.GPIO_PuPd = GPIO_PuPd_UP;
	
	//��ʼ��GPIO
	GPIO_Init(GPIOB, &GPIO_InitWAVE);
	GPIO_InitWAVE.GPIO_Pin = GPIO_Pin_6;
	GPIO_InitWAVE.GPIO_Mode = GPIO_Mode_IN;
	GPIO_Init(GPIOE, &GPIO_InitWAVE);
}
