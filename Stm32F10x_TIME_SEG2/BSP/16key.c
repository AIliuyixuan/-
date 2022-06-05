#include "includes.h"

void delay(int n)
{
	int i,j;
	for(i=0; i<n; i++)
		for(j=0; j<150; j++);
}

// 4*4按键初始化
void Key16Init(void)
{
	GPIO_InitTypeDef g;
	
	// 使能C口时钟
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);
	
	// 初始化C0\C1\C2\C3
	g.GPIO_Mode  = GPIO_Mode_Out_PP;
	g.GPIO_Pin   = GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_3;	// 0x000f
	g.GPIO_Speed = GPIO_Speed_10MHz;
	GPIO_Init(GPIOC, &g);
	
	// 初始化C4\C5\C6\C7
	g.GPIO_Mode  = GPIO_Mode_IPD;
	g.GPIO_Pin   = GPIO_Pin_4 | GPIO_Pin_5 | GPIO_Pin_6 | GPIO_Pin_7;// 0x00f0
	g.GPIO_Speed = GPIO_Speed_10MHz;
	GPIO_Init(GPIOC, &g);
}
// 4*4按键扫描
// 若按键n按下，返回n；若没有按键按下，返回-1。
int8_t Key16Scan(void)
{
	int8_t key=-1;				// 记录按键号，作为返回值用。
	uint16_t retValue=0;	// 保存读取到的C口值
	
	// 扫描第1行
	GPIO_SetBits(GPIOC, GPIO_Pin_3);
	GPIO_ResetBits(GPIOC, GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_2);
	retValue = GPIO_ReadInputData(GPIOC) & 0x00f0;
	if(retValue != 0x0000)
	{
		delay(10);
		retValue = GPIO_ReadInputData(GPIOC) & 0x00f0;
		if(retValue != 0x0000)
		{
			switch(retValue)
			{
				case 0x0010:
					key=1;
				break;
				case 0x0020:
					key=2;
				break;
				case 0x0040:
					key=3;
				break;
				case 0x0080:
					key=4;
				break;
				default:
					key=-1;
				break;
			}
		}
	}
	
	// 扫描第2行
	GPIO_SetBits(GPIOC, GPIO_Pin_2);
	GPIO_ResetBits(GPIOC, GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_3);
	retValue = GPIO_ReadInputData(GPIOC) & 0x00f0;
	if(retValue != 0x0000)
	{
		delay(10);
		retValue = GPIO_ReadInputData(GPIOC) & 0x00f0;
		if(retValue != 0x0000)
		{
			switch(retValue)
			{
				case 0x0010:
					key=5;
				break;
				case 0x0020:
					key=6;
				break;
				case 0x0040:
					key=7;
				break;
				case 0x0080:
					key=8;
				break;
				default:
					key=-1;
				break;
			}
		}
	}
	
	// 扫描第3行
	GPIO_SetBits(GPIOC, GPIO_Pin_1);
	GPIO_ResetBits(GPIOC, GPIO_Pin_0 | GPIO_Pin_2 | GPIO_Pin_3);
	retValue = GPIO_ReadInputData(GPIOC) & 0x00f0;
	if(retValue != 0x0000)
	{
		delay(10);
		retValue = GPIO_ReadInputData(GPIOC) & 0x00f0;
		if(retValue != 0x0000)
		{
			switch(retValue)
			{
				case 0x0010:
					key=9;
				break;
				case 0x0020:
					key=10;
				break;
				case 0x0040:
					key=11;
				break;
				case 0x0080:
					key=12;
				break;
				default:
					key=-1;
				break;
			}
		}
	}
	
	// 扫描第4行
	GPIO_SetBits(GPIOC, GPIO_Pin_0);
	GPIO_ResetBits(GPIOC, GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_3);
	retValue = GPIO_ReadInputData(GPIOC) & 0x00f0;
	if(retValue != 0x0000)
	{
		delay(10);
		retValue = GPIO_ReadInputData(GPIOC) & 0x00f0;
		if(retValue != 0x0000)
		{
			switch(retValue)
			{
				case 0x0010:
					key=13;
				break;
				case 0x0020:
					key=14;
				break;
				case 0x0040:
					key=15;
				break;
				case 0x0080:
					key=16;
				break;
				default:
					key=-1;
				break;
			}
		}
	}
	return key;
}

// 按键扫描
// 若按键n按下，返回n；若没有按键按下，返回-1。
int8_t Key16ScanEx(void)
{
	uint8_t i;
	int8_t key=-1;				// 记录按键号，作为返回值用。
	uint16_t retValue=0;	// 保存读取到的C口值
	
	for(i=1; i<=4; i++)
	{
		GPIO_ResetBits(GPIOC, GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_3);
		GPIO_SetBits(GPIOC, GPIO_Pin_3>>(i-1));
		
		retValue = GPIO_ReadInputData(GPIOC) & 0x00f0;
		if(retValue!=0x0000)
		{
			retValue = GPIO_ReadInputData(GPIOC) & 0x00f0;
			if(retValue!=0x0000)
			{
				switch(retValue)
				{
					case 0x0010:
						key=1+4*(i-1);
					break;
					case 0x0020:
						key=2+4*(i-1);
					break;
					case 0x0040:
						key=3+4*(i-1);
					break;
					case 0x0080:
						key=4+4*(i-1);
					break;
					default:
						key=-1;
					break;
				}
			}
		}
	}
	return key;
}
