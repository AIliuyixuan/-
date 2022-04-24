#include "includes.h"

void LEDInit(void)
{
	GPIO_InitTypeDef g;
	
	// 使能A、D.C口时钟
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA | RCC_APB2Periph_GPIOD, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);
	
	// 初始化A8
	g.GPIO_Mode=GPIO_Mode_Out_PP;
	g.GPIO_Pin=GPIO_Pin_8;
	g.GPIO_Speed=GPIO_Speed_10MHz;
	GPIO_Init(GPIOA, &g);
	
	// 初始化D2
	g.GPIO_Mode=GPIO_Mode_Out_PP;
	g.GPIO_Pin=GPIO_Pin_2;
	g.GPIO_Speed=GPIO_Speed_10MHz;
	GPIO_Init(GPIOD, &g);
	
	g.GPIO_Mode=GPIO_Mode_Out_PP;
	g.GPIO_Pin=0x00ff;
	g.GPIO_Speed=GPIO_Speed_10MHz;
	GPIO_Init(GPIOC, &g);
	
  GPIO_SetBits(GPIOC,0x00ff);
	
	LED0(0);
	LED1(0);
	

}

void LED0(Int08U state)
{
	if(state == 0)
	{
		GPIO_SetBits(GPIOA, GPIO_Pin_8);
	}
	else
	{
		GPIO_ResetBits(GPIOA, GPIO_Pin_8);
	}
}

void LED1(Int08U state)
{
	if(state == 0)
	{
		GPIO_SetBits(GPIOD, GPIO_Pin_2);
	}
	else
	{
		GPIO_ResetBits(GPIOD, GPIO_Pin_2);
	}
}



uint8_t GetLED0State(void)
{
  return !GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_8);
}

uint8_t GetLED1State(void)
{
  return !GPIO_ReadInputDataBit(GPIOD, GPIO_Pin_2);
}

uint8_t GetLED2State(void)
{
  return !GPIO_ReadInputDataBit(GPIOC, GPIO_Pin_0);
}
