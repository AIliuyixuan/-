#include "includes.h"
// 按键端口初始化
void Key_Init(void)
{
	GPIO_InitTypeDef g;
	
	//RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA | RCC_APB2Periph_GPIOC, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
	
	
	// 初始化B2/B3口
	g.GPIO_Mode=GPIO_Mode_IPU;		// 上拉输入
	g.GPIO_Pin=GPIO_Pin_2|GPIO_Pin_3|GPIO_Pin_8;				// 2号引脚
	g.GPIO_Speed=GPIO_Speed_10MHz;// 速度
	GPIO_Init(GPIOB, &g);

}
// 按键扫描
// 若KEY0按下，返回0；
// 若KEY1按下，返回1；
// 若两个同时按下,返回2；
// 若没有按键按下，返回-1。



int8_t KeyScan(void)
{
	uint8_t key0=1,key1=1;
	key0=GPIO_ReadInputDataBit(GPIOC, GPIO_Pin_5);
	key1=GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_15);
	if(0==key0 && 0==key1)
		return 2;
	else if(0==key0)
		return 0;
	else if(0==key1)
		return 1;
	else
		return -1;
}
