#include "KEY_Init.h"

void key_init()
{
		GPIO_MyInit(GPIOC, GPIO_Pin_9, GPIO_Mode_IPU);
		GPIO_MyInit(GPIOC, GPIO_Pin_8, GPIO_Mode_IPU);
}
