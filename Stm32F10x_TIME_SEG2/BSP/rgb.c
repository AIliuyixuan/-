// 文件明：rgb.c
#include "includes.h"
void RGB_Init(void)
{
	GPIO_InitTypeDef g;
	
	// 使能B口时钟
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);
	
	// 初始化C6\C7\C8
	g.GPIO_Mode  = GPIO_Mode_Out_PP;
	g.GPIO_Pin   = GPIO_Pin_7 | GPIO_Pin_8 | GPIO_Pin_9;
	g.GPIO_Speed = GPIO_Speed_10MHz;
	GPIO_Init(GPIOC, &g);
	
	RGB_On_Off(0,0,0);
}

void RGB_On_Off(Int08U r, Int08U b, Int08U g)
{
	if(r==1)
	{
		GPIO_ResetBits(GPIOC, GPIO_Pin_9);
	}
	else
	{
		GPIO_SetBits(GPIOC, GPIO_Pin_9);
	}
	
	if(b==1)
	{
		GPIO_ResetBits(GPIOC, GPIO_Pin_7);
	}
	else
	{
		GPIO_SetBits(GPIOC, GPIO_Pin_7);
	}
	
	if(g==1)
	{
		GPIO_ResetBits(GPIOC, GPIO_Pin_8);
	}
	else
	{
		GPIO_SetBits(GPIOC, GPIO_Pin_8);
	}
}
