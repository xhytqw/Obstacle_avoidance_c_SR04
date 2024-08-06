#ifndef __ISR_H
#define __ISR_H

#include "stm32f10x.h"
#include "stm32f10x_tim.h"
#include "Engine.h"
#include "KEY.h"
#include "Timer.h"

void TIM3_Config(float* dist_f,float* dist_b,float* dist_l,float* dist_r);

#endif
