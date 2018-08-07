/*Basic Function*/

#include <stdio.h>
#include "basfn.h"
#include "usart.h"
#include "systick.h"
#include "sys.h"

#define FRONT_LEFT	PCout(7)
#define FRONT_RIGHT PCout(9)
#define BACK_LEFT		PCout(6)
#define BACK_RIGHT	PCout(8)

#define LED0 PFout(9)
#define TRIG PBout(6)

#define ECHO PEin(6)
#define BEEP PFout(8)


//��������С������
void BT_DIRECTION(float distance)
{
	if(recvend == 1)
	{
		recvend =0;
		
		//��������ֹͣ
		if(recvbuf == 0x00)
		{
			LED0=1;
			BEEP = 0;
			FRONT_LEFT = 1;
			FRONT_RIGHT = 1;
			BACK_LEFT = 1;
			BACK_RIGHT = 1;
		}
		
		//��������ǰ��
		if(recvbuf == 0x01)
		{
			FRONT_LEFT = 0;
			FRONT_RIGHT = 0;
			//Σ�ղ�ǿ�ƽ�ֹǰ��
			if(distance < 100 && distance >= 0)
			{
				FRONT_LEFT = 1;
				FRONT_RIGHT = 1;
			}
		}
		
		//�������ƺ���
		if(recvbuf == 0x02)
		{
			BACK_LEFT = 0;
			BACK_RIGHT = 0;
		}
		
		//����������ת
		if(recvbuf == 0x03)
		{
			FRONT_RIGHT = 0;
			BACK_LEFT = 0;
			//Σ�ղ�ǿ�ƽ�ֹǰ��
			if(distance < 100 && distance >= 0)
			{
				FRONT_LEFT = 1;
				FRONT_RIGHT = 1;
			}
		}
		
		//����������ת
		if(recvbuf == 0x04)
		{
			FRONT_LEFT = 0;
			BACK_RIGHT = 0;
			//Σ�ղ�ǿ�ƽ�ֹǰ��
			if(distance < 100 && distance >= 0)
			{
				FRONT_LEFT = 1;
				FRONT_RIGHT = 1;
			}
		}
		
		//������������
		if(recvbuf == 0x05)
		{
			while(1)
			{
				BEEP = 1;
				if(recvbuf == 0x00)
					break;
			}
		}
	}
}

//תȦѭ��
void Cir_Montion(void)
{
	int t=10;
	while(1)
	{
		FRONT_LEFT = 0;
		delay_ms(50);
		FRONT_LEFT = 1;
		
		while(1)
		{
			FRONT_RIGHT = 0;
			delay_ms(15);
			FRONT_RIGHT = 1;
			delay_ms(5);
			break;
		}
		t--;
		if(t==0)
			break;
	}
}

//�������ѭ��
void RSParking(void)
{
	int a=10,b=10,c=10,d=10;
	while(1)
	{
		BACK_LEFT = 0;
		BACK_RIGHT = 0;
		delay_ms(75);
		a--;
		if(a == 0)
			break;
	}
	BACK_LEFT = 1;
	BACK_RIGHT = 1;
	while(1)
	{
		FRONT_RIGHT = 0;
		BACK_LEFT = 0;
		delay_ms(50);
		b--;
		if(b == 0)
			break;
	}
	FRONT_RIGHT = 1;
	BACK_LEFT = 1;
	while(1)
	{
		BACK_LEFT = 0;
		delay_ms(80);
		c--;
		if(c == 0)
			break;
	}
	BACK_LEFT = 1;
	while(1)
	{
		BACK_LEFT = 0;
		BACK_RIGHT = 0;
		delay_ms(70);
		d--;
		if(d == 0)
			break;
	}
	BACK_LEFT = 1;
	BACK_RIGHT = 1;
}

//����ϵͳ
void EVADIBLE_sys(float distance)
{
	//��ȫ����
	if(distance <= 500+100 && distance > 300+100)
	{
		BEEP = 1;
		LED0 = 0;
		delay_ms(300);
		LED0 = 1;
		BEEP = 0;
		delay_ms(300);
		//printf("��ȫ����:%0.02f\n",distance/1000);
	}
	
	//��ʾ����
	if(distance <= 300+100 && distance >= 100+100)
	{
		LED0 = 0;
		BEEP = 1;
		delay_ms(100);
		BEEP = 0;
		LED0 = 1;
		BEEP = 0;
		delay_ms(75);
		//printf("��ʾ����:%0.02f\n",distance/1000);
	}

	//Σ�վ���
	if(distance < 100+100 && distance >= 100)
	{
		LED0 = 0;
		BEEP = 1;
		FRONT_LEFT =1;
		FRONT_RIGHT = 1;
		delay_ms(60);
		LED0 = 1;
		BEEP = 0;
		delay_ms(25);
		//printf("Σ����:%0.02f\n",distance/1000);
	}
	
	//Σ�ղ�ǿ�ƽ�ֹǰ��
	if(distance < 100 && distance >=0)
	{
		FRONT_LEFT =1;
		FRONT_RIGHT = 1;
	}
}

//ͨ����������������
uint32_t SR04_get_distance(void)
{
	int time = 0;
	int distance;
	TRIG = 1;
	delay_us(20);
	TRIG = 0;
	while(ECHO == 0){}
		if(ECHO == 1)
		{
			while(ECHO == 1)
			{
				delay_us(8);
				time++;
			}
		}
	distance = time * 3;
	return distance;
}

//��ȡ��������õľ���
float DISTANCE_measure(void)
{
	float distance;
	distance = SR04_get_distance();
	//printf("%0.02f\n",distance/1000);
	//delay_ms(100);
	return distance;
}
