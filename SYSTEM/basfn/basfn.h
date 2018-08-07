#ifndef __BASFN_H
#define __BASFN_H	 
#include "stm32f4xx.h" 																	  	 

void BT_DIRECTION(float distance);
void Cir_Montion(void);
void RSParking(void);
void EVADIBLE_sys(float distance);
uint32_t SR04_get_distance(void);
float DISTANCE_measure(void);

#endif
