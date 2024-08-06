#include "Distmea.h"

float time;  
float dist; 

float distmea(GPIO_TypeDef* sin,uint16_t pin,GPIO_TypeDef* sout,uint16_t pout)  //���ʵ��  sΪ������ĸ����ѡ�� pΪ���ź�����ѡ�� in��Ӧecho�� out��Ӧtrig��
{

		GPIO_SetBits(sout,pout);
		delay_us(50);
		GPIO_ResetBits(sout, pout);

		while (GPIO_ReadInputDataBit(sin, pin) == 0);
        
		TIM_SetCounter(TIM6, 0);
		TIM_Cmd(TIM6, ENABLE);

		while (GPIO_ReadInputDataBit(sin, pin) != 0);
        
		time = TIM_GetCounter(TIM6);
		TIM_Cmd(TIM6, DISABLE);
 
		dist = time * 0.01725;
		time=0;
		return dist;
}
