#include "pwm.h"

// ����PWM��ռ�ձ�
// timer: ��ʱ�� (TIM2, TIM3��TIM4)
// channel: PWMͨ�� (1-4)
// dutyCycle: ռ�ձ� (0-999)
void PWM_SetDutyCycle(TIM_TypeDef* TIMx, uint8_t channel, uint16_t dutyCycle) {
    if (dutyCycle > 999) {
        dutyCycle = 999;
    }

    switch (channel) {
        case 1:
            TIM_SetCompare1(TIMx, dutyCycle);
            break;
        case 2:
            TIM_SetCompare2(TIMx, dutyCycle);
            break;
        case 3:
            TIM_SetCompare3(TIMx, dutyCycle);
            break;
        case 4:
            TIM_SetCompare4(TIMx, dutyCycle);
            break;
        default:
            break;
    }
}
