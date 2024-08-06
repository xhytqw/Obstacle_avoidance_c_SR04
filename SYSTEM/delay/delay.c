#include "delay.h"

static volatile uint32_t TimingDelay;

void delay_init(void)
{
    // ���� SysTick ��ÿ 1 us ����һ���ж�
    if (SysTick_Config(SystemCoreClock / 1000000))
    {
        // SysTick ���ô���
        while (1);
    }
}

void delay_ms(uint32_t ms)
{
    TimingDelay = ms * 1000;
    while (TimingDelay != 0);
}

void delay_us(uint32_t us)
{
    TimingDelay = us;
    while (TimingDelay != 0);
}

// SysTick �жϷ�����
void SysTick_Handler(void)
{
    if (TimingDelay != 0)
    {
        TimingDelay--;
    }
}
























