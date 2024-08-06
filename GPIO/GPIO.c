#include "gpio.h"

// 启用 GPIO 时钟
static void GPIO_EnableClock(GPIO_TypeDef* GPIOx)
{
    if (GPIOx == GPIOA)
    {
        RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
    }
    else if (GPIOx == GPIOB)
    {
        RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
    }
    else if (GPIOx == GPIOC)
    {
        RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);
    }
    else if (GPIOx == GPIOD)
    {
        RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOD, ENABLE);
    }
    else if (GPIOx == GPIOE)
    {
        RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOE, ENABLE);
    }
}

// 初始化 GPIO 引脚
void GPIO_MyInit(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin, GPIOMode_TypeDef Mode)
{
    GPIO_InitTypeDef GPIO_InitStructure;

    // 启用 GPIO 时钟
    GPIO_EnableClock(GPIOx);

    // 配置 GPIO 引脚
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin;
    GPIO_InitStructure.GPIO_Mode = Mode;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;


    // 初始化 GPIO
    GPIO_Init(GPIOx, &GPIO_InitStructure);
}
