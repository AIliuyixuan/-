#include "includes.h"

// 系统节拍定时器初始化
void SysTickInit(void)
{
	// 第1步：设置分频系数
	SysTick_CLKSourceConfig(SysTick_CLKSource_HCLK_Div8);
	
	// 第2步：给重装载寄存器设置初值
	SysTick_Config(80000);
}

// 第3步：重写中断服务函数
void SysTick_Handler(void)
{
	static uint8_t systickN=0;
	static uint8_t ledN=0;
	systickN++;
	if(systickN >= 100)
	{
		LED0(!GetLed0State());
		
		// 流水灯实现代码
		GPIO_SetBits(GPIOC, 0x00ff);
		GPIO_ResetBits(GPIOC, GPIO_Pin_0<<ledN);
		ledN++;
		if(ledN>=9)
		{
			ledN=0;
			GPIO_SetBits(GPIOC,0x00ff);
		}

		systickN=0;
	}
}
