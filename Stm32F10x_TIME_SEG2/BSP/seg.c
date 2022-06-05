#include "includes.h"


void Seg_Init(void)
{
	GPIO_InitTypeDef g;
	
	// 使能C口时钟
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
	
	// 初始化B0\B1\B2
	g.GPIO_Mode  = GPIO_Mode_Out_PP;
	g.GPIO_Pin   = 0x00ff;						// PB高8位
	g.GPIO_Speed = GPIO_Speed_10MHz;
	GPIO_Init(GPIOC, &g);
	
	g.GPIO_Mode  = GPIO_Mode_Out_PP;
	g.GPIO_Pin   = 0x003f;						// PB高8位
	g.GPIO_Speed = GPIO_Speed_10MHz;
	GPIO_Init(GPIOB, &g);
	
	GPIO_Write(GPIOC, 0x0000);
	GPIO_Write(GPIOB, 0x0000);
}

void SegDisplay(int8_t num)
{
	GPIO_SetBits(GPIOC, 0x00ff);
	switch(num)
	{
		case 0:
			GPIO_ResetBits(GPIOC, 0x003f);
			break;
		case 1:
			GPIO_ResetBits(GPIOC, 0x0006);
			break;
		case 2:
			GPIO_ResetBits(GPIOC, 0x005b);
			break;
		case 3:
			GPIO_ResetBits(GPIOC, 0x004f);
			break;
		case 4:
			GPIO_ResetBits(GPIOC, 0x0066);
			break;
		case 5:
			GPIO_ResetBits(GPIOC, 0x006d);
			break;
		case 6:
			GPIO_ResetBits(GPIOC, 0x007d);
			break;
		case 7:
			GPIO_ResetBits(GPIOC, 0x0007);
			break;
		case 8:
			GPIO_ResetBits(GPIOC, 0x007f);
			break;
		case 9:
			GPIO_ResetBits(GPIOC, 0x006f);
			break;
		default:
			GPIO_SetBits(GPIOC, 0x00ff);
			break;
	}
}

/*
int8_t SegDisNum_2=12;
void SegDisplay_2()
{
	int8_t shi,ge;
	shi=SegDisNum_2/10;
	ge=SegDisNum_2%10;
	
	GPIO_ResetBits(GPIOB,0x003f);
	GPIO_SetBits(GPIOB,GPIO_Pin_0);	
	SegDisplay(shi);
	delay(25);
	
	GPIO_ResetBits(GPIOB,0x003f);
	GPIO_SetBits(GPIOB,GPIO_Pin_1);	
	SegDisplay(ge);
	delay(25);
}*/


int8_t shi=1,fen=58,miao=53;

void SegDisplay_6()
{
	int8_t shi_shi,shi_ge,fen_shi,fen_ge,miao_shi,miao_ge;
	
	 shi_shi=shi/10;
	 shi_ge=shi%10; 
	
	 fen_shi=fen/10;
	 fen_ge=fen%10;
	
	 miao_shi=miao/10;
	 miao_ge=miao%10;
	
	
	GPIO_ResetBits(GPIOB,0x003f);
	GPIO_SetBits(GPIOB,GPIO_Pin_0);	
	SegDisplay(shi_shi);
	delay(20);
	
	GPIO_ResetBits(GPIOB,0x003f);
	GPIO_SetBits(GPIOB,GPIO_Pin_1);	
	SegDisplay(shi_ge);
	delay(20);
	
	GPIO_ResetBits(GPIOB,0x003f);
	GPIO_SetBits(GPIOB,GPIO_Pin_2);	
	SegDisplay(fen_shi);
	delay(20);
	
	GPIO_ResetBits(GPIOB,0x003f);
	GPIO_SetBits(GPIOB,GPIO_Pin_3);	
	SegDisplay(fen_ge);
	delay(20);
	
	GPIO_ResetBits(GPIOB,0x003f);
	GPIO_SetBits(GPIOB,GPIO_Pin_4);	
	SegDisplay(miao_shi);
	delay(20);
	
	GPIO_ResetBits(GPIOB,0x003f);
	GPIO_SetBits(GPIOB,GPIO_Pin_5);	
	SegDisplay(miao_ge);
	delay(20);
	
}
