#include "includes.h"

// �ⲿ�ж���Դ��ʼ��
void Exti_Init(void)
{
	EXTI_InitTypeDef e;			// �ⲿ�жϳ�ʼ���ṹ��
	NVIC_InitTypeDef n;			// NVIC��ʼ���ṹ��
	
	// ��1������ʼ��IO��Ϊ����
	Key_Init();
	
	// ��2��������AFIO�����ù��ܣ�ʱ��
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE);
	
	// ��3��������IO�����ж��ߵ�ӳ���ϵ
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOA, GPIO_PinSource1);
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOA, GPIO_PinSource5);
	
	// ��4����IO���ⲿ�жϳ�ʼ��
	e.EXTI_Line=EXTI_Line1|EXTI_Line5;		// �ж���1���ж���5
	e.EXTI_LineCmd=ENABLE;								// ʹ��
	e.EXTI_Mode=EXTI_Mode_Interrupt;			// �ж�ģʽ
	e.EXTI_Trigger=EXTI_Trigger_Falling;	// �½��ش���
	EXTI_Init(&e);
	
	// ��5����NVIC����
	n.NVIC_IRQChannel=EXTI1_IRQn;						// �ж�ͨ��
	n.NVIC_IRQChannelCmd=ENABLE;						// ʹ��
	n.NVIC_IRQChannelPreemptionPriority=2;	// �������ȼ�����ռ���ȼ�Ϊ2
	n.NVIC_IRQChannelSubPriority=1;					// �������ȼ�����Ӧ���ȼ�Ϊ1
	NVIC_Init(&n);
	
	n.NVIC_IRQChannel=EXTI9_5_IRQn;					// �ж�ͨ��
	n.NVIC_IRQChannelCmd=ENABLE;						// ʹ��
	n.NVIC_IRQChannelPreemptionPriority=2;	// ��ռ���ȼ�Ϊ2
	n.NVIC_IRQChannelSubPriority=1;					// ��Ӧ���ȼ�Ϊ2
	NVIC_Init(&n);
}

extern int8_t shi,fen;
// A15�жϷ�����
void EXTI1_IRQHandler(void)
{
	if(EXTI_GetITStatus(EXTI_Line1) == SET)	// �ж��Ƿ����ж���15�ϲ������ж�
	{
			//TIM_Cmd(TIM2, DISABLE);
		// Ҫ��������
	   
			fen++;
			if(fen>=60)
			{
			   fen=0;
				shi=shi+1;
			}
		
		EXTI_ClearITPendingBit(EXTI_Line1);		// ����жϱ�־λ
	}
}

// A5�жϷ�����
void EXTI9_5_IRQHandler(void)
{
	if(EXTI_GetITStatus(EXTI_Line5) == SET)	// �ж��Ƿ����ж���15�ϲ������ж�
	{
			//TIM_Cmd(TIM2, ENABLE);
		// Ҫ��������
		
		fen--;
		if(fen<=-1)
		{
		   fen=59;
			shi=shi-1;
		}
		
		
		EXTI_ClearITPendingBit(EXTI_Line5);		// ����жϱ�־λ
	}
}
