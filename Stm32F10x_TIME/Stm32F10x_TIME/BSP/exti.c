#include "includes.h"
#include "key.h"
#include "delay.h"
#include "led.h"
void Exti_Init(void)
{
	
	//��������
	EXTI_InitTypeDef e;
	NVIC_InitTypeDef n;
  //��һ������ʼ��IO����Ϊ����˿�
   Key_Init();
	
	
	//�ڶ���:����AFIO(���ù���)ʱ��
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO,ENABLE);
  
	//������:����IO�����ж��ߵĶ�Ӧ��ϵ    //����ѡ��
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOB,GPIO_PinSource2);
   GPIO_EXTILineConfig(GPIO_PortSourceGPIOB,GPIO_PinSource3);
   GPIO_EXTILineConfig(GPIO_PortSourceGPIOB,GPIO_PinSource8);
	//���Ĳ���
	 e.EXTI_Line=EXTI_Line2 | EXTI_Line3 | EXTI_Line8; //ʹ���ж��� 5 ��15
	 e.EXTI_Mode=EXTI_Mode_Interrupt; //�ж�ģʽ
	 e.EXTI_Trigger=EXTI_Trigger_Rising;//�½��ش���
	 e.EXTI_LineCmd=ENABLE;//���빤��״̬
	 EXTI_Init(&e);	//��ʼ�������жϣ����ô�������
	
	//���岽 NVIC����
	
  n.NVIC_IRQChannel=EXTI2_IRQn; //�ⲿ�ж���10-15
  n.NVIC_IRQChannelCmd=ENABLE;     //���빤��״̬
  n.NVIC_IRQChannelPreemptionPriority=1;
  n.NVIC_IRQChannelSubPriority=2;	
  NVIC_Init(&n);

  n.NVIC_IRQChannel=EXTI3_IRQn; //�ⲿ�ж���10-15
  n.NVIC_IRQChannelCmd=ENABLE;     //���빤��״̬
  n.NVIC_IRQChannelPreemptionPriority=1;
  n.NVIC_IRQChannelSubPriority=1;	
  NVIC_Init(&n);
  
  n.NVIC_IRQChannel=EXTI9_5_IRQn; //�ⲿ�ж���9-5
  n.NVIC_IRQChannelCmd=ENABLE;     //���빤��״̬
  n.NVIC_IRQChannelPreemptionPriority=1;
  n.NVIC_IRQChannelSubPriority=0;	
  NVIC_Init(&n);
}
//�жϷ�����15-10
void EXTI3_IRQHandler(void)
{
	//�ж��Ƿ����ж���15�������ж�����
   if(EXTI_GetITStatus(EXTI_Line3) == SET) 
   {
	  //�жϴ������
	  LED0(!GetLED0State());
		
	//����жϱ�־λ
	EXTI_ClearITPendingBit(EXTI_Line3);
	}
}

void EXTI2_IRQHandler(void)
{
	//�ж��Ƿ����ж���15�������ж�����
   if(EXTI_GetITStatus(EXTI_Line2) == SET) 
   {
	  //�жϴ������
	    LED1(!GetLED1State());
		
		
	//����жϱ�־λ
	EXTI_ClearITPendingBit(EXTI_Line2);
	}
}
void EXTI9_5_IRQHandler(void)
{
	//�ж��Ƿ����ж���15�������ж�����
   if(EXTI_GetITStatus(EXTI_Line8) == SET) 
   {
	  //�жϴ������
	   LED1(!GetLED1State());
		
	//����жϱ�־λ
	EXTI_ClearITPendingBit(EXTI_Line8);
	}
}




