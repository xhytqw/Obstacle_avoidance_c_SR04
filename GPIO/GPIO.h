#ifndef __GPIO_H
#define __GPIO_H

#include "stm32f10x.h"

// º¯ÊýÉùÃ÷
void GPIO_MyInit(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin, GPIOMode_TypeDef Mode);

#endif /* __GPIO_H */
