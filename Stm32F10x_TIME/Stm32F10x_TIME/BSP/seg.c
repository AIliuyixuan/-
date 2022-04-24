#include "includes.h"
void SEG_Init(void)
{
	
	GPIO_InitTypeDef g;
	
	// 使能C口时钟
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);
	
	// 初始化C0-C7
	g.GPIO_Mode  = GPIO_Mode_Out_PP;
	g.GPIO_Pin   = 0Xff;
	g.GPIO_Speed = GPIO_Speed_10MHz;
	GPIO_Init(GPIOC, &g);
}


void SegDisplay(Int08U n)
{
    GPIO_ResetBits(GPIOC,0xff);
	switch(n)
	{
	  case 0:
			GPIO_SetBits(GPIOC,0x3f);//显示0
		  break;
		case 1:
			GPIO_SetBits(GPIOC,0x06);//显示1
		  break;
		case 2:
			GPIO_SetBits(GPIOC,0x5b);//显示2
		  break;
		case 3:
			GPIO_SetBits(GPIOC,0x4f);//显示3
		  break;
		case 4:
			GPIO_SetBits(GPIOC,0x66);//显示4
		  break;
		case 5:
			GPIO_SetBits(GPIOC,0x6d);//显示5
		  break;
		case 6:
			GPIO_SetBits(GPIOC,0x7c);//显示6
		  break;
		case 7:
			GPIO_SetBits(GPIOC,0x07);//显示7
		  break;
		case 8:
			GPIO_SetBits(GPIOC,0x7f);//显示8
		  break;
		case 9:
			GPIO_SetBits(GPIOC,0x67);//显示9
		  break;
		default:
			GPIO_ResetBits(GPIOC,0xff);
	
	}
}
