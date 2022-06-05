#include "includes.h"

// 外部中断资源初始化
void Exti_Init(void)
{
	EXTI_InitTypeDef e;			// 外部中断初始化结构体
	NVIC_InitTypeDef n;			// NVIC初始化结构体
	
	// 第1步：初始化IO口为输入
	Key_Init();
	
	// 第2步：开启AFIO（复用功能）时钟
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE);
	
	// 第3步：设置IO口与中断线的映射关系
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOA, GPIO_PinSource1);
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOA, GPIO_PinSource5);
	
	// 第4步：IO口外部中断初始化
	e.EXTI_Line=EXTI_Line1|EXTI_Line5;		// 中断线1和中断线5
	e.EXTI_LineCmd=ENABLE;								// 使能
	e.EXTI_Mode=EXTI_Mode_Interrupt;			// 中断模式
	e.EXTI_Trigger=EXTI_Trigger_Falling;	// 下降沿触发
	EXTI_Init(&e);
	
	// 第5步：NVIC配置
	n.NVIC_IRQChannel=EXTI1_IRQn;						// 中断通道
	n.NVIC_IRQChannelCmd=ENABLE;						// 使能
	n.NVIC_IRQChannelPreemptionPriority=2;	// （主优先级）抢占优先级为2
	n.NVIC_IRQChannelSubPriority=1;					// （副优先级）响应优先级为1
	NVIC_Init(&n);
	
	n.NVIC_IRQChannel=EXTI9_5_IRQn;					// 中断通道
	n.NVIC_IRQChannelCmd=ENABLE;						// 使能
	n.NVIC_IRQChannelPreemptionPriority=2;	// 抢占优先级为2
	n.NVIC_IRQChannelSubPriority=1;					// 响应优先级为2
	NVIC_Init(&n);
}

extern int8_t shi,fen;
// A15中断服务函数
void EXTI1_IRQHandler(void)
{
	if(EXTI_GetITStatus(EXTI_Line1) == SET)	// 判断是否是中断线15上产生的中断
	{
			//TIM_Cmd(TIM2, DISABLE);
		// 要做的事情
	   
			fen++;
			if(fen>=60)
			{
			   fen=0;
				shi=shi+1;
			}
		
		EXTI_ClearITPendingBit(EXTI_Line1);		// 清空中断标志位
	}
}

// A5中断服务函数
void EXTI9_5_IRQHandler(void)
{
	if(EXTI_GetITStatus(EXTI_Line5) == SET)	// 判断是否是中断线15上产生的中断
	{
			//TIM_Cmd(TIM2, ENABLE);
		// 要做的事情
		
		fen--;
		if(fen<=-1)
		{
		   fen=59;
			shi=shi-1;
		}
		
		
		EXTI_ClearITPendingBit(EXTI_Line5);		// 清空中断标志位
	}
}
