// 文件明：rgb.c
#include "includes.h"
void RGB_Init(void)
{
	GPIO_InitTypeDef g;
	
	// 使能B口时钟
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
	
	// 初始化B0\B1\B2
	g.GPIO_Mode  = GPIO_Mode_Out_PP;
	g.GPIO_Pin   = GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_2;
	g.GPIO_Speed = GPIO_Speed_10MHz;
	GPIO_Init(GPIOB, &g);
	
	RGB_On_Off(0,0,0);
}

void RGB_On_Off(Int08U r, Int08U b, Int08U g)
{
	if(r==1)
	{
		GPIO_ResetBits(GPIOB, GPIO_Pin_0);
	}
	else
	{
		GPIO_SetBits(GPIOB, GPIO_Pin_0);
	}
	
	if(b==1)
	{
		GPIO_ResetBits(GPIOB, GPIO_Pin_1);
	}
	else
	{
		GPIO_SetBits(GPIOB, GPIO_Pin_1);
	}
	
	if(g==1)
	{
		GPIO_ResetBits(GPIOB, GPIO_Pin_2);
	}
	else
	{
		GPIO_SetBits(GPIOB, GPIO_Pin_2);
	}
}
