#include "led.h"


void LED_Init(void)
{
	GPIO_InitTypeDef  GPIO_InitStructure;
 		 //使能A端口时钟  RCC_APB2Periph_GPIOA|
	
	//GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8;	 
 	//GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		 //推挽输出
	//GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;//速度50MHz
 	//GPIO_Init(GPIOA, &GPIO_InitStructure);	  //初始化GPIOA
 	//GPIO_SetBits(GPIOA,GPIO_Pin_8);
}





