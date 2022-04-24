#include "includes.h"
// �����˿ڳ�ʼ��
void Key_Init(void)
{
	GPIO_InitTypeDef g;
	
	//RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA | RCC_APB2Periph_GPIOC, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
	
	
	// ��ʼ��B2/B3��
	g.GPIO_Mode=GPIO_Mode_IPU;		// ��������
	g.GPIO_Pin=GPIO_Pin_2|GPIO_Pin_3|GPIO_Pin_8;				// 2������
	g.GPIO_Speed=GPIO_Speed_10MHz;// �ٶ�
	GPIO_Init(GPIOB, &g);

}
// ����ɨ��
// ��KEY0���£�����0��
// ��KEY1���£�����1��
// ������ͬʱ����,����2��
// ��û�а������£�����-1��



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
