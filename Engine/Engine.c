#include "Engine.h"

int go (uint16_t sp,u8 d)     //spΪռ�ձ� dΪ���� d=1ǰ�� d=2����
{
		if(d==1)
		{
				//���1
				PWM_SetDutyCycle(TIM1, 1, sp); 
				PWM_SetDutyCycle(TIM1, 2, 0);  
			
				// ���2
				PWM_SetDutyCycle(TIM1, 3, sp+15);   
				PWM_SetDutyCycle(TIM1, 4, 0); 

				// ���3
				PWM_SetDutyCycle(TIM2, 1, sp); 
				PWM_SetDutyCycle(TIM2, 2, 0);   
			
				// ���4
				PWM_SetDutyCycle(TIM2, 3, sp+10);   
				PWM_SetDutyCycle(TIM2, 4, 0); 
			
				return d;    //ǰ��״̬��1
		}
		else if(d==2)
		{
				//���1
				PWM_SetDutyCycle(TIM1, 1, 0); 
				PWM_SetDutyCycle(TIM1, 2, sp);    

				// ���2
				PWM_SetDutyCycle(TIM1, 3, 0);   
				PWM_SetDutyCycle(TIM1, 4, sp+15); 

				// ���3
				PWM_SetDutyCycle(TIM2, 1, 0); 
				PWM_SetDutyCycle(TIM2, 2, sp); 
			
				// ���4
				PWM_SetDutyCycle(TIM2, 3, 0);   
				PWM_SetDutyCycle(TIM2, 4, sp+10); 
			
			return d;    //����״̬��2
		}
		else return 0;
}

int stop()
{
		// ���1
		PWM_SetDutyCycle(TIM1, 1, 0); 
		PWM_SetDutyCycle(TIM1, 2, 0);    

		// ���2
		PWM_SetDutyCycle(TIM1, 3, 0);   
		PWM_SetDutyCycle(TIM1, 4, 0); 

		// ���3
		PWM_SetDutyCycle(TIM2, 1, 0); 
		PWM_SetDutyCycle(TIM2, 2, 0);   
		// ���4
		PWM_SetDutyCycle(TIM2, 3, 0);   
		PWM_SetDutyCycle(TIM2, 4, 0); 
	
	  return 0;       //ֹͣ״̬��0
}
int LR(uint16_t sp,u8 d)  //d=3��ƽ��  d=4��ƽ��
{
		if(d==3)
		{

			// ���1
			PWM_SetDutyCycle(TIM1, 1, sp); 
			PWM_SetDutyCycle(TIM1, 2, 0);    

			// ���2
			PWM_SetDutyCycle(TIM1, 3, 0);   
			PWM_SetDutyCycle(TIM1, 4, sp+10); 

			// ���3
			PWM_SetDutyCycle(TIM2, 1, 0); 
			PWM_SetDutyCycle(TIM2, 2, sp);   
			// ���4
			PWM_SetDutyCycle(TIM2, 3, sp+10);   
			PWM_SetDutyCycle(TIM2, 4, 0);
			
			return 3;  //����״̬��3
		}
		else if(d==4)
		{
			// ���1
			PWM_SetDutyCycle(TIM1, 1, 0);
			PWM_SetDutyCycle(TIM1, 2, sp);    

			// ���2
			PWM_SetDutyCycle(TIM1, 3, sp+10);   
			PWM_SetDutyCycle(TIM1, 4, 0); 

			// ���3
			PWM_SetDutyCycle(TIM2, 1, sp); 
			PWM_SetDutyCycle(TIM2, 2, 0);   
			// ���4
			PWM_SetDutyCycle(TIM2, 3, 0);   
			PWM_SetDutyCycle(TIM2, 4, sp+10);

			return 4;  //����״̬��4
		}
		else return 0;
		
}
int turn(uint16_t sp,u8 d)  //d=0˳ʱ��  d=1��ʱ��
{
		int a,b;
		if(d==0)
		{
			a=sp;
			b=0;
		}
		if(d==1)
		{
			a=0;
			b=sp;
		}
	  // ���1
		PWM_SetDutyCycle(TIM1, 1, a); 
		PWM_SetDutyCycle(TIM1, 2, b);    

		// ���2
		PWM_SetDutyCycle(TIM1, 3, b);   
		PWM_SetDutyCycle(TIM1, 4, a); 

		// ���3
		PWM_SetDutyCycle(TIM2, 1, a); 
		PWM_SetDutyCycle(TIM2, 2, b);   
		// ���4
		PWM_SetDutyCycle(TIM2, 3, b);   
		PWM_SetDutyCycle(TIM2, 4, a);
		
		return 5;
}
