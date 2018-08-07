#include "stm32f4xx.h"
#include "init.h"
#include "basfn.h"

/*
- 实现手机蓝牙控制小车
- 当小车距障碍物一定距离会报警并避障
*/

//示例
int main()
{
	float distance;
	INIT();
	while(1)
	{
		//获得车到障碍物的距离
		distance = DISTANCE_measure();
		//printf("%0.02f\n",distance/1000);
		
		//蓝牙控制小车方向
		BT_DIRECTION(distance);
		
		//启用避障系统
		EVADIBLE_sys(distance);
	}
}

