#include "includes.h"

// ϵͳ���Ķ�ʱ����ʼ��
void SysTickInit(void)
{
	// ��1�������÷�Ƶϵ��
	SysTick_CLKSourceConfig(SysTick_CLKSource_HCLK_Div8);
	
	// ��2��������װ�ؼĴ������ó�ֵ
	SysTick_Config(80000);
}

// ��3������д�жϷ�����
void SysTick_Handler(void)
{
	static uint8_t systickN=0;
	static uint8_t ledN=0;
	systickN++;
	if(systickN >= 100)
	{
		LED0(!GetLed0State());
		
		// ��ˮ��ʵ�ִ���
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
