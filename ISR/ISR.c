#include "ISR.h"

static float* distf;  //����ȫ��ָ�� ����
static float* distb;
static float* distl;
static float* distr;

static int flag;
static int lrflag;
//static int *f;     //״̬��״ָ̬��

void TIM3_IRQHandler(void);

void TIM3_Config(float* dist_f,float* dist_b,float* dist_l,float* dist_r)
{
	  TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;
    NVIC_InitTypeDef NVIC_InitStructure;
	
		distf = dist_f; //ָ�봫��
		distb = dist_b;
		distl = dist_l;
		distr = dist_r;
	
    // ����TIM3ʱ��
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);

    // ��ʱ��TIM3����
    TIM_TimeBaseStructure.TIM_Period = 1000 - 1; // ��ʱ���� (1ms)
    TIM_TimeBaseStructure.TIM_Prescaler = 7200 - 1; // Ԥ��Ƶ�� (10kHz)
    TIM_TimeBaseStructure.TIM_ClockDivision = 0;
    TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;
    TIM_TimeBaseInit(TIM3, &TIM_TimeBaseStructure);

    // ��������жϱ�־λ
    TIM_ClearITPendingBit(TIM3, TIM_IT_Update);

    // ʹ�ܸ����ж�
    TIM_ITConfig(TIM3, TIM_IT_Update, ENABLE);

    // NVIC����
    NVIC_InitStructure.NVIC_IRQChannel = TIM3_IRQn;
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&NVIC_InitStructure);

    // ������ʱ��
    TIM_Cmd(TIM3, ENABLE);
}

void TIM3_IRQHandler(void)
{
		
    if (TIM_GetITStatus(TIM3, TIM_IT_Update) != RESET)
    {

			  TIM_ClearITPendingBit(TIM3, TIM_IT_Update);
				if(!key_status_4())
				{
						flag=go(210,1);
				}
				if(!key_status_3())
				{
						flag=stop();
				}
				if(flag==1)             //�ж�״̬��ʵ��
				{
						if( *distl <= 15 )
						{
								flag=LR(300,4);
							  return;
						}
						if( *distr <= 15 )
						{
								flag=LR(300,3);
							  return;
						}
						if( *distf <= 50 && *distl <= *distr && *distr > 30 )
						{
								flag=LR(300,4);
								lrflag=1;
						}
						if( *distf <= 50 && *distr < *distl && *distl > 30 )
						{
								flag=LR(300,3);
								lrflag=1;
						}

						if( *distf <= 50 && *distr <= 25 && *distl <= 25 && *distb >= 30 )
						{
								flag=go(210,2);
						}
						if( *distf <= 30 && *distr <= 30 && *distl <= 30 && *distb <= 30 )
						{
								flag=stop();
						}
				}
				if(flag==2)
				{
					if( *distl <= 15 )
						{
								flag=LR(300,4);
							  return;
						}
						if( *distr <= 15 )
						{
								flag=LR(300,3);
							  return;
						}
						if( *distf <= 30 && *distr <= 30 && *distl <= 30 && *distb <= 30 )
						{
								flag=stop();
						}
						if( *distb >= 30 && *distl > 15 && *distr > 15 )
						{
								flag=turn(220,0);
						}
						if( *distb < 30 && *distl <= *distr && *distr > 30)
						{
								flag=LR(300,4);
								lrflag=1;
						}
						if( *distb < 30 && *distr <= *distl && *distl > 30)
						{
								flag=LR(300,3);
								lrflag=1;
						}
							
						
				}
				if(flag==3)
				{
						if( *distf <= 15 )
						{
								flag=go(210,2);
							  return;
						}
						if( *distb <= 15 )
						{
								flag=go(210,1);
							  return;
						}
						if( *distf <= 25 && *distr <= 25 && *distl <= 25 && *distb <= 25 )
						{
								flag=stop();
						}
						if( *distf > 40 )
						{
								flag=go(210,1);
						}
						if( *distl <= 30 && lrflag==1 )
						{
								flag=LR(300,4);
								lrflag=2; 
						}
						if( *distl <= 30 && lrflag==2 )
						{
								flag=go(210,2);
								
						}
				}
				if(flag==4)
				{
						if( *distf <= 15 )
						{
								flag=go(210,2);
							  return;
						}
						if( *distb <= 15 )
						{
								flag=go(210,1);
							  return;
						}
						if( *distl <= 15 )
						{
								flag=LR(300,4);
							  return;
						}
						if( *distr <= 15 )
						{
								flag=LR(300,3);
							  return;
						}
						if( *distf <= 25 && *distr <= 25 && *distl <= 25 && *distb <= 25 )
						{
								flag=stop();
						}
						if( *distf > 40 )
						{
								flag=go(210,1);
						}
						if( *distr <= 30 && lrflag==1 )
						{
								flag=LR(300,3);
								lrflag=2; 
						}
						if( *distr <= 30 && lrflag==2 )
						{
								flag=go(210,2);
								
						}
				}
				if(flag==5)
				{
						if( *distf <= 25 && *distr <= 25 && *distl <= 25 && *distb <= 25 )
						{
								flag=stop();
						}
						if( *distf > 30 )
						{
								flag=go(210,1);
						}
				}
				if(flag==0)
				{
				}
				/*if(flag==0 && *distf<=35 && *distb<=35 && *distl<=35 && *distr<=35)
				{
						stop();
					  flag++;
				}
				if( *distf<=35&&flag==0&&stflag!=0)
					LR(250,0);
				if (*distl<=35&&flag==0&&stflag!=0)
					LR(250,1);
				if(*distr<=35&&flag==0&&stflag!=0)
					 go(250,1);
				if(*distb<=35&&flag==0&&stflag!=0)
					 LR(250,1);
				if(stflag!=0&&!key_status_3())
				{
						stop();
					  flag++;
				}
				*/
        // ��������жϱ�־λ
        /*
				if( *distf<10 || *distb<10 || *distl<10 ||*distr<10)
				{
						stop();
				}
LOOP1:	if( *distf > 30 )
				{
						go(220,0);
				}
				if( *distf <= 30 )
				{  
						go(150,0);
						if(*distf<=20)
						{
								stop();
								if( *distl <= 20 && *distl >= 10 && *distr >= 10 && *distr <= 20 && *distb > 20 )
								{
										turn(150,1);
										return;
								}
										
								else if(*distl >= 20 && lflag==0)
								{
										LR(150,0);
									  //rflag++;
									  goto LOOP1;
								}
								else if(*distl < 20 && rflag==0)
								{
										LR(150,1);
									  lflag++;
									  goto LOOP1;
								}
										if( *distf >20 )
										{
												stop();
												go(150,0);
												goto LOOP1;
										}	
										else if( *distl < 20 )
										{
												stop();
												LR(150,1);
												if( *distf > 20 )
												{
														stop();
														go(150,0);
														goto LOOP1;
												}
										}
									}
										else if( *distl >= *distr && *distr >= 20)
										{
												LR(150,0)
										}
								}
								
						}
				if(!key_status_3())
				stop();
    }
		*/
  
		
	}
}
