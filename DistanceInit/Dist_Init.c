#include "Dist_Init.h"

void Dist_Init(GPIO_TypeDef* sin,uint16_t pin,GPIO_TypeDef* sout,uint16_t pout)
{	
		GPIO_MyInit(sin, pin, GPIO_Mode_IPD);
    GPIO_MyInit(sout, pout, GPIO_Mode_Out_PP);	
}			
