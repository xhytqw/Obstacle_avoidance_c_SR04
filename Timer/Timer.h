#ifndef __TIMER_H
#define __TIMER_H
#include "stm32f10x.h"
#include "stm32f10x_tim.h"

void TIM1_PWM_Init(u16 arr, u16 psc);
void TIM2_PWM_Init(u16 arr, u16 psc);
void TIM6_Init();
#endif
