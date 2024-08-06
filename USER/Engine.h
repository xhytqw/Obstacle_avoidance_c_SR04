#ifndef __ENGINE_H
#define __ENGINE_H

#include "PWM.h"
#include "stm32f10x.h"
#include "delay.h"

int go (uint16_t sp,u8 d);   //sp为占空比 d为方向 d=0前进 d=1后退
int stop();
int LR(uint16_t sp,u8 d);  //d=0左平移  d=1右平移
int turn(uint16_t sp,u8 d);  //d=0逆时针  d=1顺时针

#endif
