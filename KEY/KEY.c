#include "KEY.h"

int key_status_4()
{
    return GPIO_ReadInputDataBit(GPIOC, GPIO_Pin_9);// 按键按下时，GPIO_ReadInputDataBit 返回0
}

int key_status_3()
{
    return GPIO_ReadInputDataBit(GPIOC, GPIO_Pin_8); // 按键按下时，GPIO_ReadInputDataBit 返回0
}
