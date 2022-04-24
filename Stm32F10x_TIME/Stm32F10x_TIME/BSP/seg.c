#include "includes.h"
void SEG_Init(void)
{
	
	GPIO_InitTypeDef g;
	
	// ʹ��C��ʱ��
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);
	
	// ��ʼ��C0-C7
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
			GPIO_SetBits(GPIOC,0x3f);//��ʾ0
		  break;
		case 1:
			GPIO_SetBits(GPIOC,0x06);//��ʾ1
		  break;
		case 2:
			GPIO_SetBits(GPIOC,0x5b);//��ʾ2
		  break;
		case 3:
			GPIO_SetBits(GPIOC,0x4f);//��ʾ3
		  break;
		case 4:
			GPIO_SetBits(GPIOC,0x66);//��ʾ4
		  break;
		case 5:
			GPIO_SetBits(GPIOC,0x6d);//��ʾ5
		  break;
		case 6:
			GPIO_SetBits(GPIOC,0x7c);//��ʾ6
		  break;
		case 7:
			GPIO_SetBits(GPIOC,0x07);//��ʾ7
		  break;
		case 8:
			GPIO_SetBits(GPIOC,0x7f);//��ʾ8
		  break;
		case 9:
			GPIO_SetBits(GPIOC,0x67);//��ʾ9
		  break;
		default:
			GPIO_ResetBits(GPIOC,0xff);
	
	}
}
