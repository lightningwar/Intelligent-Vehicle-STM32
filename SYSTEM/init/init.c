#include "init.h"
#include "systick.h"
#include "usart.h"
#include "led.h"
#include "beep.h"
#include "key.h"
#include "wave.h"
#include "wheel.h"


//��ʼ������
void INIT(void)
{
	LED_init();						//LED�Ƴ�ʼ��
	KEY_init();						//������ʼ��
	BEEP_init();					//���ȳ�ʼ��
	WHEEL_init();					//С�����ֵ����ʼ��
	WAVE_init();					//������ģ���ʼ��
	Systick_init(168);		//ϵͳʱ��Ƶ��168MHZ
	uart_init(9600);			//����ģ�鲨����9600bps
}
