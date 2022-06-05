#include "includes.h"
// �����˿ڳ�ʼ��
void Key_Init(void)
{
	GPIO_InitTypeDef g;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	
	// ��ʼ��A1\A5��
	g.GPIO_Mode=GPIO_Mode_IPU;		// ��������
	g.GPIO_Pin=GPIO_Pin_1 | GPIO_Pin_5;				// 15������
	g.GPIO_Speed=GPIO_Speed_10MHz;// �ٶ�
	GPIO_Init(GPIOA, &g);
	
	
}
// ����ɨ��
// ��KEY0���£�����0��
// ��KEY1���£�����1��
// ������ͬʱ����,����2��
// ��û�а������£�����-1��
int8_t KeyScan(void)
{
	uint8_t key0=1,key1=1;
	key0=GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_1);
	key1=GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_5);
	if(0==key0 && 0==key1)
		return 2;
	else if(0==key0)
		return 0;
	else if(0==key1)
		return 1;
	else
		return -1;
	
}
