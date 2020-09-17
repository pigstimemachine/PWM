#include "pwm.h"
/*
�˿����֧�ֵ�PWM����ͨ�����ձ�
ͨ����       ��Ӧ����		��������
PWM1_CH1     PA8			PE9    
PWM1_CH2	 PA9			PE11
PWM1_CH3	 PA10			PE13
PWM1_CH4	 PA11			PE14

PWM2_CH1     PA0            PA15
PWM2_CH2	 PA1			PB3
PWM2_CH3	 PA2			PB10
PWM2_CH4	 PA3			PB11

PWM3_CH1 	 PA6			PB4
PWM3_CH2	 PA7			PB5
PWM3_CH3	 PB0			PC8
PWM4_CH4	 PB1			PC9

PWM4_CH1	 PB6			PD12
PWM4_CH2	 PB7			PD13
PWM4_CH3	 PB8			PD14
PWM4_CH4	 PB9			PD15



void main ()
{
PWM_Init(PWM1_CH1,0);//��ʼ��PWM1ͨ��1
while(1)
{
PWM_duty(PWM1_CH1,1000)//��PWM��Ϊ1000�����10000����10%;
}
}

*/



/*
��������PWM��ʼ������
������һ��PWMͨ��
	 ������ʼPWMֵ
ʱ�䣺2019.8.14
����PWM_Init(PWM1_CH1,0);
ע����pwm��ʼ���⣬���Կ���TIM1~TIM4��ʱ�����16·��ʱ��
TIM1->CCMR1|=7<<4;  	//CH1 PWM2ģʽ������led
*/
void PWM_Init(PWM_Ch n,u16 PWM_VAL)
{
	switch(n)
	{
		case PWM1_CH1://PA8
		{
			RCC->APB2ENR|=1<<11; 	//TIM1ʱ��ʹ��   
			RCC->APB2ENR|=1<<2; //GPIOAʱ��ʹ�� 			
			GPIOA->CRH&=0XFFFFFFF0;	//PA8���֮ǰ������
			GPIOA->CRH|=0X0000000B;	//���ù������ 
			
			TIM1->ARR=arr_init;			//�趨�������Զ���װֵ 
			TIM1->PSC=psc_init;			//Ԥ��Ƶ������ Ƶ��=72000 000/�� ��ARR+1����PSC+1�� ��*
			
			TIM1->CCMR1|=6<<4;  	//CH1 PWM1ģʽ		 
			TIM1->CCMR1|=1<<3; 		//CH1Ԥװ��ʹ��	 
			TIM1->CCER|=1<<0;   	//OC1 ���ʹ��	   
				TIM1->BDTR|=1<<15;   	//MOE �����ʹ��	   
			
			TIM1->CR1=0x0080;   	//ARPEʹ�� 
			TIM1->CR1|=0x01;    	//ʹ�ܶ�ʱ��1
			
			TIM1->CCR1 =PWM_VAL;
			
			break;
		}
		case PWM1_CH2://PA9
		{
			RCC->APB2ENR|=1<<11; 	//TIM1ʱ��ʹ��    
			RCC->APB2ENR|=1<<2; //GPIOAʱ��ʹ�� 
			GPIOA->CRH&=0XFFFFFF0F;	//PA9���֮ǰ������
			GPIOA->CRH|=0X000000B0;	//���ù������ 
	
			TIM1->ARR=arr_init;			//�趨�������Զ���װֵ 
			TIM1->PSC=psc_init;			//Ԥ��Ƶ������

			TIM1->CCMR1|=6<<12;//CH2 PWM1ģʽ
			TIM1->CCMR1|=1<<11; //CH2Ԥװ��ʹ�� 
			TIM1->CCER|=1<<4; //CH2���ʹ�� 
				TIM1->BDTR |= 1<<15;//TIM1����Ҫ��仰�������PWM
			
			TIM1->CR1=0x80; //ARPEʹ��
			TIM1->CR1|=0x01; //ʹ�ܶ�ʱ��2 
			 			
			TIM1->CCR2 =PWM_VAL;
			
			break;
		}
		case PWM1_CH3://PA10
		{
			RCC->APB2ENR|=1<<11; 	//TIM1ʱ��ʹ��
			RCC->APB2ENR|=1<<2; //GPIOAʱ��ʹ�� 			
			GPIOA->CRH&=0XFFFFF0FF;	//PA10���֮ǰ������
			GPIOA->CRH|=0X00000B00;	//���ù������ 
	
			TIM1->ARR=arr_init;			//�趨�������Զ���װֵ 
			TIM1->PSC=psc_init;			//Ԥ��Ƶ������

			TIM1->CCMR2|=6<<4;//CH2 PWM1ģʽ
			TIM1->CCMR2|=1<<3; //CH2Ԥװ��ʹ�� 
			TIM1->CCER|=1<<8; //CH2���ʹ�� 
				TIM1->BDTR |= 1<<15;//TIM1����Ҫ��仰�������PWM
			
			TIM1->CR1=0x80; //ARPEʹ��
			TIM1->CR1|=0x01; //ʹ�ܶ�ʱ��2 
			 
			TIM1->CCR3 =PWM_VAL;
			
			break;
		}
		case PWM1_CH4://PA11
		{
			RCC->APB2ENR|=1<<11; 	//TIM1ʱ��ʹ��
			RCC->APB2ENR|=1<<2; //GPIOAʱ��ʹ�� 			
			GPIOA->CRH&=0XFFFF0FFF;	//PA10���֮ǰ������
			GPIOA->CRH|=0X0000B000;	//���ù������ 
	
			TIM1->ARR=arr_init;			//�趨�������Զ���װֵ 
			TIM1->PSC=psc_init;			//Ԥ��Ƶ������

			TIM1->CCMR2|=6<<12;//CH2 PWM1ģʽ
			TIM1->CCMR2|=1<<11; //CH2Ԥװ��ʹ�� 
			TIM1->CCER|=1<<12; //CH2���ʹ�� 
				TIM1->BDTR |= 1<<15;//TIM1����Ҫ��仰�������PWM
			
			TIM1->CR1=0x80; //ARPEʹ��
			TIM1->CR1|=0x01; //ʹ�ܶ�ʱ��2 
			 
			TIM1->CCR3 =PWM_VAL;
			
			break;
		}
		////////////////////////////////////////////////////////////////////////
		case PWM2_CH1://PA0
		{
			RCC->APB1ENR|=1; //ʹ��TIM2ʱ�� 
			RCC->APB2ENR|=1<<2; //GPIOAʱ��ʹ�� 
			GPIOA->CRL&=0XFFFFFFF0; //PA 0 ��λ
			GPIOA->CRL|=0X0000000B; //PA 0 �������
		 
			TIM2->ARR=arr_init;//�趨�������Զ���װֵ
			TIM2->PSC=psc_init; //Ԥ��Ƶ������Ƶ
			
			TIM2->CCMR1|=6<<4; //CH1 PWM1ģʽ
			TIM2->CCMR1|=1<<3; //CH1Ԥװ��ʹ��
			TIM2->CCER|=1<<0; //CH1���ʹ��
			
			TIM2->CR1=0x80; //ARPEʹ��
			TIM2->CR1|=0x01; //ʹ�ܶ�ʱ��2
			
			TIM2->CCR1 =PWM_VAL;
		}
		case PWM2_CH2://PA1
		{
			RCC->APB1ENR|=1; //ʹ��TIM2ʱ�� 
			RCC->APB2ENR|=1<<2; //GPIOAʱ��ʹ�� 
			GPIOA->CRL&=0XFFFFFF0F; //PA  1��λ
			GPIOA->CRL|=0X000000B0; //PA  1�������

			TIM2->ARR=arr_init;//�趨�������Զ���װֵ
			TIM2->PSC=psc_init; //Ԥ��Ƶ������Ƶ
			
			TIM2->CCMR1|=6<<12;//CH2 PWM1ģʽ
			TIM2->CCMR1|=1<<11; //CH2Ԥװ��ʹ�� 
			TIM2->CCER|=1<<4; //CH2���ʹ�� 

			TIM2->CR1=0x80; //ARPEʹ��
			TIM2->CR1|=0x01; //ʹ�ܶ�ʱ��2 
			
			TIM2->CCR2 =PWM_VAL;
		}
		case PWM2_CH3://PA2
		{
			RCC->APB1ENR|=1; //ʹ��TIM2ʱ�� 
			RCC->APB2ENR|=1<<2; //GPIOAʱ��ʹ�� 
			GPIOA->CRL&=0XFFFFF0FF;	//PA2���֮ǰ������
			GPIOA->CRL|=0X00000B00;	//���ù������ 
	
			TIM2->ARR=arr_init;			//�趨�������Զ���װֵ 
			TIM2->PSC=psc_init;			//Ԥ��Ƶ������

			TIM2->CCMR2|=6<<4;//CH3 PWM1ģʽ
			TIM2->CCMR2|=1<<3; //CH3Ԥװ��ʹ�� 
			TIM2->CCER|=1<<8; //CH3���ʹ�� 
			
			TIM2->CR1=0x80; //ARPEʹ��
			TIM2->CR1|=0x01; //ʹ�ܶ�ʱ��2 
			 
			TIM2->CCR3 =PWM_VAL;
			
			break;
		}
		case PWM2_CH4://PA3
		{
			RCC->APB1ENR|=1; //ʹ��TIM2ʱ��   
			RCC->APB2ENR|=1<<2; //GPIOAʱ��ʹ�� 			
			GPIOA->CRL&=0XFFFF0FFF;	//PA3���֮ǰ������
			GPIOA->CRL|=0X0000B000;	//���ù������ 
	
			TIM2->ARR=arr_init;			//�趨�������Զ���װֵ 
			TIM2->PSC=psc_init;			//Ԥ��Ƶ������

			TIM2->CCMR2|=6<<12;//CH4 PWM1ģʽ
			TIM2->CCMR2|=1<<11; //CH4Ԥװ��ʹ�� 
			TIM2->CCER|=1<<12; //CH4���ʹ�� 
			
			TIM2->CR1=0x80; //ARPEʹ��
			TIM2->CR1|=0x01; //ʹ�ܶ�ʱ��2 
			 
			TIM2->CCR4 =PWM_VAL;
			
			break;
		}
		////////////////////////////////
		case PWM3_CH1://PA6
		{
			RCC->APB1ENR|=1<<1; //ʹ��TIM3ʱ�� 
			RCC->APB2ENR|=1<<2; //GPIOAʱ��ʹ�� 
			GPIOA->CRL&=0XF0FFFFFF; //PA6��λ
			GPIOA->CRL|=0X0B000000; //PA6 �������

			TIM3->ARR=arr_init;//�趨�������Զ���װֵ
			TIM3->PSC=psc_init; //Ԥ��Ƶ������Ƶ
			
			TIM3->CCMR1|=6<<4; //CH1 PWM1ģʽ
			TIM3->CCMR1|=1<<3; //CH1Ԥװ��ʹ��
			TIM3->CCER|=1<<0; //CH1���ʹ��
			
			TIM3->CR1=0x80; //ARPEʹ��
			TIM3->CR1|=0x01; //ʹ�ܶ�ʱ��2
			
			TIM3->CCR1 =PWM_VAL;
			
			break;
		}
		case PWM3_CH2://PA7
		{
			RCC->APB1ENR|=1<<1; //ʹ��TIM3ʱ�� 
			RCC->APB2ENR|=1<<2; //GPIOAʱ��ʹ�� 
			GPIOA->CRL&=0X0FFFFFFF; //PA7 ��λ
			GPIOA->CRL|=0XB0000000; //PA7 �������
		 
			TIM3->ARR=arr_init;//�趨�������Զ���װֵ
			TIM3->PSC=psc_init; //Ԥ��Ƶ������Ƶ
			
			TIM3->CCMR1|=6<<12;//CH2 PWM1ģʽ
			TIM3->CCMR1|=1<<11; //CH2Ԥװ��ʹ�� 
			TIM3->CCER|=1<<4; //CH2���ʹ�� 

			TIM3->CR1=0x80; //ARPEʹ��
			TIM3->CR1|=0x01; //ʹ�ܶ�ʱ��2 
			
			TIM3->CCR2 =PWM_VAL;
			
			break;
		}
		case PWM3_CH3://PB0
		{
			RCC->APB1ENR|=1<<1; //ʹ��TIM3ʱ��
			RCC->APB2ENR|=1<<3;			
			GPIOB->CRL&=0XFFFFFFF0;	//PB0���֮ǰ������
			GPIOB->CRL|=0X0000000B;	//���ù������ 
	
			TIM3->ARR=arr_init;			//�趨�������Զ���װֵ 
			TIM3->PSC=psc_init;			//Ԥ��Ƶ������

			TIM3->CCMR2|=6<<4;//CH3 PWM1ģʽ
			TIM3->CCMR2|=1<<3; //CH3Ԥװ��ʹ�� 
			TIM3->CCER|=1<<8; //CH3���ʹ�� 
			
			TIM3->CR1=0x80; //ARPEʹ��
			TIM3->CR1|=0x01; //ʹ�ܶ�ʱ��2 
			 
			TIM3->CCR3 =PWM_VAL;
			
			break;
		}
		case PWM3_CH4://PB1
		{
			RCC->APB1ENR|=1<<1; //ʹ��TIM3ʱ�� 
			RCC->APB2ENR|=1<<3;
			GPIOB->CRL&=0XFFFFFF0F;	//PB1���֮ǰ������
			GPIOB->CRL|=0X000000B0;	//���ù������ 
	
			TIM3->ARR=arr_init;			//�趨�������Զ���װֵ 
			TIM3->PSC=psc_init;			//Ԥ��Ƶ������

			TIM3->CCMR2|=6<<12;//CH4 PWM1ģʽ
			TIM3->CCMR2|=1<<11; //CH4Ԥװ��ʹ�� 
			TIM3->CCER|=1<<12; //CH4���ʹ�� 
			
			TIM3->CR1=0x80; //ARPEʹ��
			TIM3->CR1|=0x01; //ʹ�ܶ�ʱ��2 
			 
			TIM3->CCR4 =PWM_VAL;
			
			break;
		}
		
		///////////////////////////////////
		case PWM4_CH1://PB6
		{
			RCC->APB1ENR|=1<<2; //ʹ��TIM4ʱ�� 
			RCC->APB2ENR|=1<<3; //GPIOBʱ��ʹ�� 
			GPIOB->CRL&=0XF0FFFFFF; //PB6��λ
			GPIOB->CRL|=0X0B000000; //PB6 �������
		 
			TIM4->ARR=arr_init;//�趨�������Զ���װֵ
			TIM4->PSC=psc_init; //Ԥ��Ƶ������Ƶ
			
			TIM4->CCMR1|=6<<4; //CH1 PWM1ģʽ
			TIM4->CCMR1|=1<<3; //CH1Ԥװ��ʹ��
			TIM4->CCER|=1<<0; //CH1���ʹ��
			
			TIM4->CR1=0x80; //ARPEʹ��
			TIM4->CR1|=0x01; //ʹ�ܶ�ʱ��2
			
			TIM4->CCR1 =PWM_VAL;
			
			break;
		}
		case PWM4_CH2://PB7
		{
			RCC->APB1ENR|=1<<2; //ʹ��TIM4ʱ�� 
			RCC->APB2ENR|=1<<3; //GPIOBʱ��ʹ�� 
			GPIOB->CRL&=0X0FFFFFFF; //PB7��λ
			GPIOB->CRL|=0XB0000000; //PB7 �������
		 
			TIM4->ARR=arr_init;//�趨�������Զ���װֵ
			TIM4->PSC=psc_init; //Ԥ��Ƶ������Ƶ
			
			TIM4->CCMR1|=6<<12;//CH2 PWM1ģʽ
			TIM4->CCMR1|=1<<11; //CH2Ԥװ��ʹ�� 
			TIM4->CCER|=1<<4; //CH2���ʹ�� 

			TIM4->CR1=0x80; //ARPEʹ��
			TIM4->CR1|=0x01; //ʹ�ܶ�ʱ��2 
			
			TIM4->CCR2 =PWM_VAL;
			
			break;
		}
		case PWM4_CH3://PB8
		{
			RCC->APB1ENR|=1<<2; //ʹ��TIM4ʱ�� 
			RCC->APB2ENR|=1<<3; //GPIOBʱ��ʹ�� 
			GPIOB->CRH&=0XFFFFFFF0; //PB8��λ
			GPIOB->CRH|=0X0000000B; //PB8 �������
	
			TIM4->ARR=arr_init;//�趨�������Զ���װֵ
			TIM4->PSC=psc_init; //Ԥ��Ƶ������Ƶ

			TIM4->CCMR2|=6<<4;//CH3 PWM1ģʽ
			TIM4->CCMR2|=1<<3; //CH3Ԥװ��ʹ�� 
			TIM4->CCER|=1<<8; //CH3���ʹ�� 
			
			TIM4->CR1=0x80; //ARPEʹ��
			TIM4->CR1|=0x01; //ʹ�ܶ�ʱ��2 
			 
			TIM4->CCR3 =PWM_VAL;
			
			break;
		}
		case PWM4_CH4://PB9
		{
			RCC->APB1ENR|=1<<2; //ʹ��TIM4ʱ�� 
			RCC->APB2ENR|=1<<3; //GPIOBʱ��ʹ�� 
			GPIOB->CRH&=0XFFFFFF0F; //PB9��λ
			GPIOB->CRH|=0X000000B0; //PB9 �������
	
			TIM4->ARR=arr_init;//�趨�������Զ���װֵ
			TIM4->PSC=psc_init; //Ԥ��Ƶ������Ƶ

			TIM4->CCMR2|=6<<12;//CH4 PWM1ģʽ
			TIM4->CCMR2|=1<<11; //CH4Ԥװ��ʹ�� 
			TIM4->CCER|=1<<12; //CH4���ʹ�� 
			
			TIM4->CR1=0x80; //ARPEʹ��
			TIM4->CR1|=0x01; //ʹ�ܶ�ʱ��2 
			 
			TIM4->CCR4 =PWM_VAL;
			
			break;
		}
	}
}
/*
������:ռ�ձ����ú���
������һ��PWMͨ��
	 ����ռ�ձȴ�С��0~10000��
ʱ�䣺2019.8.14
����PWM_duty(PWM1_CH1,1000);
*/
void PWM_duty(PWM_Ch n,u16 PWM_DUTY)
{
	float PWM_VAL;

	PWM_VAL=(arr_init*PWM_DUTY/10000.0);
	switch(n)
	{
		case PWM1_CH1://PA8
		{
			TIM1->CCR1 =PWM_VAL;
			break;
		} 
		case PWM1_CH2://PA9
		{
			TIM1->CCR2 =PWM_VAL;
			break;
		} 
		case PWM1_CH3://PA10
		{
			TIM1->CCR3 =PWM_VAL;
			break;
		} 
		case PWM1_CH4://PA11
		{
			TIM1->CCR4 =PWM_VAL;
			break;
		} 
		
		case PWM2_CH1://PA0
		{
			TIM2->CCR1 =PWM_VAL;
			break;
		} 
		case PWM2_CH2://PA1
		{
			TIM2->CCR2 =PWM_VAL;
			break;
		}
		case PWM2_CH3://PA2
		{
			TIM2->CCR3 =PWM_VAL;
			break;
		}
		case PWM2_CH4://PA3
		{
			TIM2->CCR4 =PWM_VAL;
			break;
		}

		case PWM3_CH1://PA6
		{
			TIM3->CCR1 =PWM_VAL;
			break;
		} 
		case PWM3_CH2://PA7
		{
			TIM3->CCR2 =PWM_VAL;
			break;
		} 
		case PWM3_CH3://PB0
		{
			TIM3->CCR3 =PWM_VAL;
			break;
		} 
		case PWM3_CH4://PB1
		{
			TIM3->CCR4 =PWM_VAL;
			break;
		} 
		
		case PWM4_CH1://PB6
		{
			TIM4->CCR1 =PWM_VAL;
			break;
		} 
		case PWM4_CH2://PB7
		{
			TIM4->CCR2 =PWM_VAL;
			break;
		} 
		case PWM4_CH3://PB8
		{
			TIM4->CCR3 =PWM_VAL;
			break;
		} 
		case PWM4_CH4://PB9
		{
			TIM4->CCR4 =PWM_VAL;
			break;
		} 
	}
}
