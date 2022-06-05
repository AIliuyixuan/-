#include "includes.h"

// 定时器3中断资源初始化
void Tim3_Init(void)
{
	TIM_TimeBaseInitTypeDef t;
	NVIC_InitTypeDef n;
	
	// 第1步：使能TIM3的时钟
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM1, ENABLE);
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);
	
	// 第2步：设置定时器的参数
	t.TIM_ClockDivision=0;									// 分频因子为0
	t.TIM_CounterMode=TIM_CounterMode_Up;		// 向上计数
	t.TIM_Period=4999;											// 自动重装载周期值
	t.TIM_Prescaler=1299;										// 分频系数
	TIM_TimeBaseInit(TIM3, &t);
	
	// 第3步：设置定时器3允许更新中断
	TIM_ITConfig(TIM3, TIM_IT_Update, ENABLE);
	
	// 第4步：NVIC配置
	n.NVIC_IRQChannel=TIM2_IRQn;
	n.NVIC_IRQChannelCmd=ENABLE;
	n.NVIC_IRQChannelPreemptionPriority=3;
	n.NVIC_IRQChannelSubPriority=1;
	NVIC_Init(&n);
	
	// 第5步：使能TIM3
	TIM_Cmd(TIM3, ENABLE);
}

// 定时器2中断资源初始化
void Tim2_Init(void)
{
	TIM_TimeBaseInitTypeDef t;
	NVIC_InitTypeDef n;
	
	// 第1步：使能TIM2的时钟
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM1, ENABLE);
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);
	
	// 第2步：设置定时器的参数
	t.TIM_ClockDivision=0;									// 分频因子为0
	t.TIM_CounterMode=TIM_CounterMode_Up;		// 向上计数
	t.TIM_Period=4999;											// 自动重装载周期值
	t.TIM_Prescaler=599;										// 分频系数
	TIM_TimeBaseInit(TIM2, &t);
	
	// 第3步：设置定时器2允许更新中断
	TIM_ITConfig(TIM2, TIM_IT_Update, ENABLE);
	
	// 第4步：NVIC配置
	n.NVIC_IRQChannel=TIM2_IRQn;
	n.NVIC_IRQChannelCmd=ENABLE;
	n.NVIC_IRQChannelPreemptionPriority=3;
	n.NVIC_IRQChannelSubPriority=1;
	NVIC_Init(&n);
	
	// 第5步：使能TIM2
	TIM_Cmd(TIM2, ENABLE);
}

// 第6步：重写中断服务函数
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
//	if(TIM_GetITStatus(TIM2, TIM_IT_Update)!=RESET)	// 判断是否是更新中断
//	{
//		TIM_ClearITPendingBit(TIM2, TIM_IT_Update);		// 清楚更新中断标志位
//		SegDisNum_2++;
//		if(SegDisNum_2>=100)
//		{
//			SegDisNum_2=0;
//		}
//////		
//////		// 数码管循环显示0-9
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
	if(TIM_GetITStatus(TIM2, TIM_IT_Update)!=RESET)	// 判断是否是更新中断
	{
		TIM_ClearITPendingBit(TIM2, TIM_IT_Update);		// 清除更新中断标志位
		
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
