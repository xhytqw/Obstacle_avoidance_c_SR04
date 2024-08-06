#include "Timer.h"

// ��ʼ��TIM1��PWM����
void TIM1_PWM_Init(u16 arr, u16 psc) {

    GPIO_InitTypeDef GPIO_InitStructure;
		
    TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;
    TIM_OCInitTypeDef TIM_OCInitStructure;
    // ʹ��TIM1��GPIOAʱ��

    RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM1, ENABLE);
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
		//RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, DISABLE);
	  //GPIO_PinRemapConfig(GPIO_Remap_SWJ_Disable, DISABLE);
	
    // ����GPIOA��8��9��10��11����Ϊ�����������
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8 | GPIO_Pin_9| GPIO_Pin_10| GPIO_Pin_11;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOA, &GPIO_InitStructure);

    // ��ʼ��TIM1��ʱ��
    TIM_TimeBaseStructure.TIM_Period = arr;
    TIM_TimeBaseStructure.TIM_Prescaler = psc;
    TIM_TimeBaseStructure.TIM_ClockDivision = 0;
    TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;
    TIM_TimeBaseInit(TIM1, &TIM_TimeBaseStructure);

    // ����TIM1������Ƚ�ģʽΪPWMģʽ1
    TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;
    TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
    TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;

    // ��ʼ��TIM1��ͨ��1
    TIM_OC1Init(TIM1, &TIM_OCInitStructure);
    TIM_OC1PreloadConfig(TIM1, TIM_OCPreload_Enable);

    // ��ʼ��TIM1��ͨ��2
    TIM_OC2Init(TIM1, &TIM_OCInitStructure);
    TIM_OC2PreloadConfig(TIM1, TIM_OCPreload_Enable);

    // ��ʼ��TIM1��ͨ��3
    TIM_OC3Init(TIM1, &TIM_OCInitStructure);
    TIM_OC3PreloadConfig(TIM1, TIM_OCPreload_Enable);

    // ��ʼ��TIM1��ͨ��4
    TIM_OC4Init(TIM1, &TIM_OCInitStructure);
    TIM_OC4PreloadConfig(TIM1, TIM_OCPreload_Enable);

    // ʹ��TIM1���Զ���װ�Ĵ���
    TIM_ARRPreloadConfig(TIM1, ENABLE);

    // ʹ��TIM1�������
    TIM_CtrlPWMOutputs(TIM1, ENABLE);

    // ����TIM1
    TIM_Cmd(TIM1, ENABLE);
}
    // ��ʼ��TIM2��PWM����
    void TIM2_PWM_Init(u16 arr, u16 psc) {
    GPIO_InitTypeDef GPIO_InitStructure;
    TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;
    TIM_OCInitTypeDef TIM_OCInitStructure;

    // ʹ��TIM2��GPIOAʱ��
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);

    // ����GPIOA��0��1��2��3����Ϊ�����������
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_3;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOA, &GPIO_InitStructure);

    // ��ʼ��TIM2��ʱ��
    TIM_TimeBaseStructure.TIM_Period = arr;
    TIM_TimeBaseStructure.TIM_Prescaler = psc;
    TIM_TimeBaseStructure.TIM_ClockDivision = 0;
    TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;
    TIM_TimeBaseInit(TIM2, &TIM_TimeBaseStructure);

    // ����TIM2������Ƚ�ģʽΪPWMģʽ1
    TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;
    TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
    TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;

    // ��ʼ��TIM2��ͨ��1
    TIM_OC1Init(TIM2, &TIM_OCInitStructure);
    TIM_OC1PreloadConfig(TIM2, TIM_OCPreload_Enable);

    // ��ʼ��TIM2��ͨ��2
    TIM_OC2Init(TIM2, &TIM_OCInitStructure);
    TIM_OC2PreloadConfig(TIM2, TIM_OCPreload_Enable);

    // ��ʼ��TIM2��ͨ��3
    TIM_OC3Init(TIM2, &TIM_OCInitStructure);
    TIM_OC3PreloadConfig(TIM2, TIM_OCPreload_Enable);

    // ��ʼ��TIM2��ͨ��4
    TIM_OC4Init(TIM2, &TIM_OCInitStructure);
    TIM_OC4PreloadConfig(TIM2, TIM_OCPreload_Enable);

    // ʹ��TIM2���Զ���װ�Ĵ���
    TIM_ARRPreloadConfig(TIM2, ENABLE);

    // ����TIM2
    TIM_Cmd(TIM2, ENABLE);
}
void TIM6_Init() {

    TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;

    // ʹ��TIM6
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM6, ENABLE);

    // ��ʼ��TIM6��ʱ��
    TIM_TimeBaseStructure.TIM_Period = 0xFFFF;
    TIM_TimeBaseStructure.TIM_Prescaler = 71;
    TIM_TimeBaseStructure.TIM_ClockDivision = 0;
    TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;
    TIM_TimeBaseInit(TIM6, &TIM_TimeBaseStructure);

    // ʹ��TIM6���Զ���װ�Ĵ���
    TIM_ARRPreloadConfig(TIM6, ENABLE);
}

