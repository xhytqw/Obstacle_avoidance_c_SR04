#include "delay.h"
#include "lcd_init.h"
#include "lcd.h"
#include "PWM.h"
#include "Engine.h"
#include "Distmea.h"
#include "Dist_Init.h"
#include "KEY_Init.h"
#include "ISR.h"
int main()
{
 
	  float dist_f,dist_b,dist_l,dist_r;
	  int flag; 
	
    Dist_Init(GPIOA,GPIO_Pin_4,GPIOA,GPIO_Pin_5);    //right sensor  ����������ĸ ������������ ���������ĸ �����������
	  Dist_Init(GPIOA,GPIO_Pin_7,GPIOA,GPIO_Pin_6);    //left sensor
	  Dist_Init(GPIOC,GPIO_Pin_12,GPIOC,GPIO_Pin_11);  //front sensor 
	  Dist_Init(GPIOC,GPIO_Pin_6,GPIOC,GPIO_Pin_7);    //back sensor
	
    delay_init();
	
		               // �ж϶�ʱ��
	  TIM1_PWM_Init(999, 71);       // ��ʼ�� TIM1: �⽫����1kHz��PWM�ź� (72MHz / (71+1) / (999+1))
    TIM2_PWM_Init(999, 71);       // ��ʼ�� TIM2: ͬ��������
		TIM6_Init();                  // ����ö�ʱ����ʼ��
	
    key_init();
	
		LCD_Init();  // LCD��ʼ��
    LCD_Fill(0, 0, LCD_W, LCD_H, WHITE);  
	
		TIM3_Config(&dist_f,&dist_b,&dist_l,&dist_r); 
    //turn(220,0);
	  //delay_ms(10000);
	  //LR(220,0);  //0�� 1��
	  //delay_ms(10000);
		//stop();
		//PWM_SetDutyCycle(TIM1, 1, 0);   
		//PWM_SetDutyCycle(TIM1, 2, 0); 
		//PWM_SetDutyCycle(TIM1, 3, 220);   
		//PWM_SetDutyCycle(TIM1, 4, 0); 
	
    while(1)
    {
				//fdist=distmea(GPIOA,GPIO_Pin_5,GPIOA,GPIO_Pin_4);//���ʵ��  sΪ������ĸ����ѡ�� pΪ���ź�����ѡ�� in��Ӧecho�� out��Ӧtrig��
            
				dist_f=distmea(GPIOC,GPIO_Pin_12,GPIOC,GPIO_Pin_11);
				dist_b=distmea(GPIOC,GPIO_Pin_6,GPIOC,GPIO_Pin_7); 
				dist_l=distmea(GPIOA,GPIO_Pin_7,GPIOA,GPIO_Pin_6);
				dist_r=distmea(GPIOA,GPIO_Pin_4,GPIOA,GPIO_Pin_5);
			
        LCD_ShowString(14, 0, "Barrier Dist", BLACK, WHITE, 16, 0);
			  LCD_ShowString(20,20,"FD:",BLACK,WHITE,16,0);
			  LCD_ShowFloatNum1(50,20,distmea(GPIOC,GPIO_Pin_12,GPIOC,GPIO_Pin_11),5,BLACK,WHITE,16);
			  delay_ms(5);
			  LCD_ShowString(20,40,"BD:",BLACK,WHITE,16,0);
				LCD_ShowFloatNum1(50,40,distmea(GPIOC,GPIO_Pin_6,GPIOC,GPIO_Pin_7),5,BLACK,WHITE,16);
				delay_ms(5);
				LCD_ShowString(20,60,"LD:",BLACK,WHITE,16,0);
				LCD_ShowFloatNum1(50,60,distmea(GPIOA,GPIO_Pin_7,GPIOA,GPIO_Pin_6),5,BLACK,WHITE,16);
			  delay_ms(5);
				LCD_ShowString(20,80,"RD:",BLACK,WHITE,16,0);
				LCD_ShowFloatNum1(50,80,distmea(GPIOA,GPIO_Pin_4,GPIOA,GPIO_Pin_5),5,BLACK,WHITE,16);
			  delay_ms(5);
				//delay_ms(10);
         //LCD_ShowPicture(65, 80, 40, 40, gImage_1);
        
    }
}
