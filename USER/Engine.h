#ifndef __ENGINE_H
#define __ENGINE_H

#include "PWM.h"
#include "stm32f10x.h"
#include "delay.h"

int go (uint16_t sp,u8 d);   //spΪռ�ձ� dΪ���� d=0ǰ�� d=1����
int stop();
int LR(uint16_t sp,u8 d);  //d=0��ƽ��  d=1��ƽ��
int turn(uint16_t sp,u8 d);  //d=0��ʱ��  d=1˳ʱ��

#endif
