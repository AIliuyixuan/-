#include "includes.h"
#include "key.h"
#include "delay.h"
#include "led.h"
void Exti_Init(void)
{
	
	//触发函数
	EXTI_InitTypeDef e;
	NVIC_InitTypeDef n;
  //第一步：初始化IO口作为输入端口
   Key_Init();
	
	
	//第二步:开启AFIO(复用功能)时钟
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO,ENABLE);
  
	//第三步:设置IO口与中断线的对应关系    //引脚选择
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOB,GPIO_PinSource2);
   GPIO_EXTILineConfig(GPIO_PortSourceGPIOB,GPIO_PinSource3);
   GPIO_EXTILineConfig(GPIO_PortSourceGPIOB,GPIO_PinSource8);
	//第四步：
	 e.EXTI_Line=EXTI_Line2 | EXTI_Line3 | EXTI_Line8; //使用中断线 5 和15
	 e.EXTI_Mode=EXTI_Mode_Interrupt; //中断模式
	 e.EXTI_Trigger=EXTI_Trigger_Rising;//下降沿触发
	 e.EXTI_LineCmd=ENABLE;//进入工作状态
	 EXTI_Init(&e);	//初始化线上中断，设置触发条件
	
	//第五步 NVIC配置
	
  n.NVIC_IRQChannel=EXTI2_IRQn; //外部中断线10-15
  n.NVIC_IRQChannelCmd=ENABLE;     //进入工作状态
  n.NVIC_IRQChannelPreemptionPriority=1;
  n.NVIC_IRQChannelSubPriority=2;	
  NVIC_Init(&n);

  n.NVIC_IRQChannel=EXTI3_IRQn; //外部中断线10-15
  n.NVIC_IRQChannelCmd=ENABLE;     //进入工作状态
  n.NVIC_IRQChannelPreemptionPriority=1;
  n.NVIC_IRQChannelSubPriority=1;	
  NVIC_Init(&n);
  
  n.NVIC_IRQChannel=EXTI9_5_IRQn; //外部中断线9-5
  n.NVIC_IRQChannelCmd=ENABLE;     //进入工作状态
  n.NVIC_IRQChannelPreemptionPriority=1;
  n.NVIC_IRQChannelSubPriority=0;	
  NVIC_Init(&n);
}
//中断服务函数15-10
void EXTI3_IRQHandler(void)
{
	//判断是否是中断线15发生了中断请求
   if(EXTI_GetITStatus(EXTI_Line3) == SET) 
   {
	  //中断处理程序
	  LED0(!GetLED0State());
		
	//清楚中断标志位
	EXTI_ClearITPendingBit(EXTI_Line3);
	}
}

void EXTI2_IRQHandler(void)
{
	//判断是否是中断线15发生了中断请求
   if(EXTI_GetITStatus(EXTI_Line2) == SET) 
   {
	  //中断处理程序
	    LED1(!GetLED1State());
		
		
	//清楚中断标志位
	EXTI_ClearITPendingBit(EXTI_Line2);
	}
}
void EXTI9_5_IRQHandler(void)
{
	//判断是否是中断线15发生了中断请求
   if(EXTI_GetITStatus(EXTI_Line8) == SET) 
   {
	  //中断处理程序
	   LED1(!GetLED1State());
		
	//清楚中断标志位
	EXTI_ClearITPendingBit(EXTI_Line8);
	}
}




