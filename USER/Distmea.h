#ifndef __DISTMEA_H
#define __DISTMEA_H

#include "Timer.h"
#include "stm32f10x.h"


extern float time;  // 声明外部变量
extern float dist;  // 声明外部变量

float distmea(GPIO_TypeDef* sin,uint16_t pin,GPIO_TypeDef* sout,uint16_t pout);

#endif
