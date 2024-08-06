#include "Engine.h"

int go (uint16_t sp,u8 d)     //sp为占空比 d为方向 d=1前进 d=2后退
{
		if(d==1)
		{
				//电机1
				PWM_SetDutyCycle(TIM1, 1, sp); 
				PWM_SetDutyCycle(TIM1, 2, 0);  
			
				// 电机2
				PWM_SetDutyCycle(TIM1, 3, sp+15);   
				PWM_SetDutyCycle(TIM1, 4, 0); 

				// 电机3
				PWM_SetDutyCycle(TIM2, 1, sp); 
				PWM_SetDutyCycle(TIM2, 2, 0);   
			
				// 电机4
				PWM_SetDutyCycle(TIM2, 3, sp+10);   
				PWM_SetDutyCycle(TIM2, 4, 0); 
			
				return d;    //前进状态机1
		}
		else if(d==2)
		{
				//电机1
				PWM_SetDutyCycle(TIM1, 1, 0); 
				PWM_SetDutyCycle(TIM1, 2, sp);    

				// 电机2
				PWM_SetDutyCycle(TIM1, 3, 0);   
				PWM_SetDutyCycle(TIM1, 4, sp+15); 

				// 电机3
				PWM_SetDutyCycle(TIM2, 1, 0); 
				PWM_SetDutyCycle(TIM2, 2, sp); 
			
				// 电机4
				PWM_SetDutyCycle(TIM2, 3, 0);   
				PWM_SetDutyCycle(TIM2, 4, sp+10); 
			
			return d;    //后退状态机2
		}
		else return 0;
}

int stop()
{
		// 电机1
		PWM_SetDutyCycle(TIM1, 1, 0); 
		PWM_SetDutyCycle(TIM1, 2, 0);    

		// 电机2
		PWM_SetDutyCycle(TIM1, 3, 0);   
		PWM_SetDutyCycle(TIM1, 4, 0); 

		// 电机3
		PWM_SetDutyCycle(TIM2, 1, 0); 
		PWM_SetDutyCycle(TIM2, 2, 0);   
		// 电机4
		PWM_SetDutyCycle(TIM2, 3, 0);   
		PWM_SetDutyCycle(TIM2, 4, 0); 
	
	  return 0;       //停止状态机0
}
int LR(uint16_t sp,u8 d)  //d=3左平移  d=4右平移
{
		if(d==3)
		{

			// 电机1
			PWM_SetDutyCycle(TIM1, 1, sp); 
			PWM_SetDutyCycle(TIM1, 2, 0);    

			// 电机2
			PWM_SetDutyCycle(TIM1, 3, 0);   
			PWM_SetDutyCycle(TIM1, 4, sp+10); 

			// 电机3
			PWM_SetDutyCycle(TIM2, 1, 0); 
			PWM_SetDutyCycle(TIM2, 2, sp);   
			// 电机4
			PWM_SetDutyCycle(TIM2, 3, sp+10);   
			PWM_SetDutyCycle(TIM2, 4, 0);
			
			return 3;  //左移状态机3
		}
		else if(d==4)
		{
			// 电机1
			PWM_SetDutyCycle(TIM1, 1, 0);
			PWM_SetDutyCycle(TIM1, 2, sp);    

			// 电机2
			PWM_SetDutyCycle(TIM1, 3, sp+10);   
			PWM_SetDutyCycle(TIM1, 4, 0); 

			// 电机3
			PWM_SetDutyCycle(TIM2, 1, sp); 
			PWM_SetDutyCycle(TIM2, 2, 0);   
			// 电机4
			PWM_SetDutyCycle(TIM2, 3, 0);   
			PWM_SetDutyCycle(TIM2, 4, sp+10);

			return 4;  //右移状态机4
		}
		else return 0;
		
}
int turn(uint16_t sp,u8 d)  //d=0顺时针  d=1逆时针
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
	  // 电机1
		PWM_SetDutyCycle(TIM1, 1, a); 
		PWM_SetDutyCycle(TIM1, 2, b);    

		// 电机2
		PWM_SetDutyCycle(TIM1, 3, b);   
		PWM_SetDutyCycle(TIM1, 4, a); 

		// 电机3
		PWM_SetDutyCycle(TIM2, 1, a); 
		PWM_SetDutyCycle(TIM2, 2, b);   
		// 电机4
		PWM_SetDutyCycle(TIM2, 3, b);   
		PWM_SetDutyCycle(TIM2, 4, a);
		
		return 5;
}
