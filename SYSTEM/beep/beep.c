/********************������********************/

#include "beep.h"
GPIO_InitTypeDef	GPIO_InitBEEP;


/*��������ʼ��*/
void BEEP_init(void)
{
	//ʹ�ܶ�Ӧ�˿ڵ�ʱ��
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOF,ENABLE);
	
	//����GPIO�Ľṹ����Ϣ
	GPIO_InitBEEP.GPIO_Pin = GPIO_Pin_8;
	GPIO_InitBEEP.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_InitBEEP.GPIO_Speed = GPIO_Speed_100MHz;
	GPIO_InitBEEP.GPIO_OType = GPIO_OType_PP;
	GPIO_InitBEEP.GPIO_PuPd = GPIO_PuPd_UP;
	
	//��ʼ��GPIO
	GPIO_Init(GPIOF, &GPIO_InitBEEP);
	
	//����������Ϊ�͵�ƽ�����죩
	GPIO_ResetBits(GPIOF, GPIO_Pin_8);//����������
}
