#include "stm32f4xx.h"
#include "init.h"
#include "basfn.h"

/*
- ʵ���ֻ���������С��
- ��С�����ϰ���һ������ᱨ��������
*/

//ʾ��
int main()
{
	float distance;
	INIT();
	while(1)
	{
		//��ó����ϰ���ľ���
		distance = DISTANCE_measure();
		//printf("%0.02f\n",distance/1000);
		
		//��������С������
		BT_DIRECTION(distance);
		
		//���ñ���ϵͳ
		EVADIBLE_sys(distance);
	}
}

