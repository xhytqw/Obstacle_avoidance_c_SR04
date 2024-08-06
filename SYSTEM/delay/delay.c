#include "delay.h"

static volatile uint32_t TimingDelay;

void delay_init(void)
{
    // 配置 SysTick 以每 1 us 产生一次中断
    if (SysTick_Config(SystemCoreClock / 1000000))
    {
        // SysTick 配置错误
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

// SysTick 中断服务函数
void SysTick_Handler(void)
{
    if (TimingDelay != 0)
    {
        TimingDelay--;
    }
}
























