#ifndef __DISTMEA_H
#define __DISTMEA_H

#include "GPIO.h"
#include "Timer.h"
#include "stm32f10x.h"

void Dist_Init(GPIO_TypeDef* sin,uint16_t pin,GPIO_TypeDef* sout,uint16_t pout);

#endif
