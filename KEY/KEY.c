#include "KEY.h"

int key_status_4()
{
    return GPIO_ReadInputDataBit(GPIOC, GPIO_Pin_9);// ��������ʱ��GPIO_ReadInputDataBit ����0
}

int key_status_3()
{
    return GPIO_ReadInputDataBit(GPIOC, GPIO_Pin_8); // ��������ʱ��GPIO_ReadInputDataBit ����0
}
