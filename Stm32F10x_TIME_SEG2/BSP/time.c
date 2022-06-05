#include "includes.h"

// ��ʱ��3�ж���Դ��ʼ��
void Tim3_Init(void)
{
	TIM_TimeBaseInitTypeDef t;
	NVIC_InitTypeDef n;
	
	// ��1����ʹ��TIM3��ʱ��
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM1, ENABLE);
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);
	
	// ��2�������ö�ʱ���Ĳ���
	t.TIM_ClockDivision=0;									// ��Ƶ����Ϊ0
	t.TIM_CounterMode=TIM_CounterMode_Up;		// ���ϼ���
	t.TIM_Period=4999;											// �Զ���װ������ֵ
	t.TIM_Prescaler=1299;										// ��Ƶϵ��
	TIM_TimeBaseInit(TIM3, &t);
	
	// ��3�������ö�ʱ��3��������ж�
	TIM_ITConfig(TIM3, TIM_IT_Update, ENABLE);
	
	// ��4����NVIC����
	n.NVIC_IRQChannel=TIM2_IRQn;
	n.NVIC_IRQChannelCmd=ENABLE;
	n.NVIC_IRQChannelPreemptionPriority=3;
	n.NVIC_IRQChannelSubPriority=1;
	NVIC_Init(&n);
	
	// ��5����ʹ��TIM3
	TIM_Cmd(TIM3, ENABLE);
}

// ��ʱ��2�ж���Դ��ʼ��
void Tim2_Init(void)
{
	TIM_TimeBaseInitTypeDef t;
	NVIC_InitTypeDef n;
	
	// ��1����ʹ��TIM2��ʱ��
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM1, ENABLE);
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);
	
	// ��2�������ö�ʱ���Ĳ���
	t.TIM_ClockDivision=0;									// ��Ƶ����Ϊ0
	t.TIM_CounterMode=TIM_CounterMode_Up;		// ���ϼ���
	t.TIM_Period=4999;											// �Զ���װ������ֵ
	t.TIM_Prescaler=599;										// ��Ƶϵ��
	TIM_TimeBaseInit(TIM2, &t);
	
	// ��3�������ö�ʱ��2��������ж�
	TIM_ITConfig(TIM2, TIM_IT_Update, ENABLE);
	
	// ��4����NVIC����
	n.NVIC_IRQChannel=TIM2_IRQn;
	n.NVIC_IRQChannelCmd=ENABLE;
	n.NVIC_IRQChannelPreemptionPriority=3;
	n.NVIC_IRQChannelSubPriority=1;
	NVIC_Init(&n);
	
	// ��5����ʹ��TIM2
	TIM_Cmd(TIM2, ENABLE);
}

// ��6������д�жϷ�����
void TIM3_IRQHandler(void)
{
	if(TIM_GetITStatus(TIM3, TIM_IT_Update)!=RESET)
	{
		TIM_ClearITPendingBit(TIM3, TIM_IT_Update);
		LED0(!GetLed0State());
	}
}

//extern int8_t SegDisNum_2;
//void TIM2_IRQHandler(void)
//{
//	if(TIM_GetITStatus(TIM2, TIM_IT_Update)!=RESET)	// �ж��Ƿ��Ǹ����ж�
//	{
//		TIM_ClearITPendingBit(TIM2, TIM_IT_Update);		// ��������жϱ�־λ
//		SegDisNum_2++;
//		if(SegDisNum_2>=100)
//		{
//			SegDisNum_2=0;
//		}
//////		
//////		// �����ѭ����ʾ0-9
//////		static int8_t time_SegN=0;
//////		if(time_SegN>=10)
//////			time_SegN=0;
//////		SegDisplay(time_SegN);
//////		time_SegN++;
//	}		
//}

extern int8_t shi,fen,miao;
void TIM2_IRQHandler(void)
{
	if(TIM_GetITStatus(TIM2, TIM_IT_Update)!=RESET)	// �ж��Ƿ��Ǹ����ж�
	{
		TIM_ClearITPendingBit(TIM2, TIM_IT_Update);		// ��������жϱ�־λ
		
		miao++;
		if(miao>=60)
		{
			miao=0;
			fen+=1;
			if(fen>=60)
			{
				fen=0;
				shi+=1;
			}
		}
	}
}
