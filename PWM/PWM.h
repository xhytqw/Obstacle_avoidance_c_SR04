#ifndef __PWM_H
#define __PWM_H
#include "stm32f10x.h"

// 设置PWM的占空比
// timer: 定时器 (TIM2, TIM3或TIM4)
// channel: PWM通道 (1-4)
// dutyCycle: 占空比 (0-999)
void PWM_SetDutyCycle(TIM_TypeDef* TIMx, uint8_t channel, uint16_t dutyCycle);

#endif
