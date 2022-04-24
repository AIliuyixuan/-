#include "includes.h"
void LEDInit(void)
{
	GPIO_InitTypeDef g;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA|RCC_APB2Periph_GPIOD, ENABLE);
	
	g.GPIO_Mode=GPIO_Mode_Out_PP;
	g.GPIO_Pin=GPIO_Pin_8;
	g.GPIO_Speed=GPIO_Speed_10MHz;
	GPIO_Init(GPIOA, &g);
	
	
	g.GPIO_Mode=GPIO_Mode_Out_PP;
	g.GPIO_Pin=GPIO_Pin_2;
	g.GPIO_Speed=GPIO_Speed_10MHz;
	GPIO_Init(GPIOD, &g);
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
