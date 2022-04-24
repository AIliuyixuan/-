#include "includes.h"
#include "delay.h"
#include "key.h"

//4*4�����˿ڳ�ʼ��
// C0-C7��
void Key16_Init(void)
{
  	GPIO_InitTypeDef g;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC,ENABLE);
	
	// ��ʼ��C0/C1/C2/C3��
	g.GPIO_Mode=GPIO_Mode_Out_PP;		// �������
	g.GPIO_Pin=GPIO_Pin_0 | GPIO_Pin_1 |GPIO_Pin_2 | GPIO_Pin_3;				
	//g.GPIO_Pin=0x000f;
	g.GPIO_Speed=GPIO_Speed_10MHz;// �ٶ�
	GPIO_Init(GPIOC, &g);
	
	// ��ʼ��C4/C5/C6/C7��
	g.GPIO_Mode=GPIO_Mode_IPD;		// ��������
	g.GPIO_Pin=GPIO_Pin_4 | GPIO_Pin_5 | GPIO_Pin_6 | GPIO_Pin_7;				
	g.GPIO_Speed=GPIO_Speed_10MHz;// �ٶ�
	GPIO_Init(GPIOC, &g);
}

// 4*4 ����ɨ��
//����ɨ��
//�� ���� key -n ���£�����n����û�а������£����� -1;
int8_t Key16Scan(void)
{
  int8_t key=-1; //��¼����ֵ
	int16_t tmp=0; //��¼��ȡ�Ķ˿�ֵ
	
	
	//ɨ���һ��
 GPIO_SetBits(GPIOC,GPIO_Pin_0); //C0 ����ߵ�ƽ
 GPIO_ResetBits(GPIOC,GPIO_Pin_1 |GPIO_Pin_2 | GPIO_Pin_3); //C1/C2/C3����͵�ƽ
 tmp=GPIO_ReadInputData(GPIOC)&0x00f0;
if(tmp != 0x0000) //�а�������
{
  delay_ms(10); //������������
  tmp=GPIO_ReadInputData(GPIOC)&0x00f0;
	if(tmp != 0x0000)
	{
	  switch(tmp)
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
	//ɨ��ڶ���
 GPIO_SetBits(GPIOC,GPIO_Pin_1); //C1 ����ߵ�ƽ
 GPIO_ResetBits(GPIOC,GPIO_Pin_0 |GPIO_Pin_2 | GPIO_Pin_3); //C0/C2/C3����͵�ƽ
 tmp=GPIO_ReadInputData(GPIOC)&0x00f0;
if(tmp != 0x0000) //�а�������
{
  delay_ms(10); //������������
  tmp=GPIO_ReadInputData(GPIOC)&0x00f0;
	if(tmp != 0x0000)
	{
	  switch(tmp)
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
	//ɨ�������
 GPIO_SetBits(GPIOC,GPIO_Pin_2); //C2 ����ߵ�ƽ
 GPIO_ResetBits(GPIOC,GPIO_Pin_0 |GPIO_Pin_1 | GPIO_Pin_3); //C0/C1/C3����͵�ƽ
 tmp=GPIO_ReadInputData(GPIOC)&0x00f0;
if(tmp != 0x0000) //�а�������
{
  delay_ms(10); //������������
  tmp=GPIO_ReadInputData(GPIOC)&0x00f0;
	if(tmp != 0x0000)
	{
	  switch(tmp)
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

//ɨ�������
 GPIO_SetBits(GPIOC,GPIO_Pin_3); //C3 ����ߵ�ƽ
 GPIO_ResetBits(GPIOC,GPIO_Pin_0 |GPIO_Pin_1 | GPIO_Pin_2); //C0/C1/C2����͵�ƽ
 tmp=GPIO_ReadInputData(GPIOC)&0x00f0;
if(tmp != 0x0000) //�а�������
{
  delay_ms(10); //������������
  tmp=GPIO_ReadInputData(GPIOC)&0x00f0;
	if(tmp != 0x0000)
	{
	  switch(tmp)
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


// 4*4 ����ɨ��
//����ɨ��
//�� ���� key -n ���£�����n����û�а������£����� -1;
int8_t Key16ScanEX(void)
{
  uint8_t i=0; //ѭ������
	int8_t key=-1; //��¼������
	uint16_t tmp=0; //�����ȡ�Ķ˿�ֵ
	for(i=0;i<4;i++)
	{
	  GPIO_ResetBits(GPIOC,GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_3 );
		GPIO_SetBits(GPIOC,GPIO_Pin_0<<(i-1));
		tmp = GPIO_ReadInputData(GPIOC)&0x00f0;
		if(tmp != 0x0000)
		{
		  delay_ms(10);
			tmp = GPIO_ReadInputData(GPIOC)&0x00f0;
		  if(tmp != 0x000)
			{
				switch(tmp)
			{
				case 0x0010:
				key=1+(4*(i-1));
				break;
				
				case 0x0020:
				key=2+(4*(i-1));
				break;
				
				case 0x0040:
				key=3+(4*(i-1));
				break;
				
				case 0x0080:
				key=4+(4*(i-1));
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



//����ɨ��
void Key16_Init_L(void)
{
  	GPIO_InitTypeDef g;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC,ENABLE);
	
	// ��ʼ��C4/C5/C6/C7��
	g.GPIO_Mode=GPIO_Mode_Out_PP;		// �������
	g.GPIO_Pin=GPIO_Pin_4 | GPIO_Pin_5 |GPIO_Pin_6 | GPIO_Pin_7;				
	//g.GPIO_Pin=0x000f;
	g.GPIO_Speed=GPIO_Speed_10MHz;// �ٶ�
	GPIO_Init(GPIOC, &g);
	
	// ��ʼ��C0/C1/C2/C3��
	g.GPIO_Mode=GPIO_Mode_IPD;		// ��������
	g.GPIO_Pin=GPIO_Pin_0| GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_3;				
	g.GPIO_Speed=GPIO_Speed_10MHz;// �ٶ�
	GPIO_Init(GPIOC, &g);
}

int8_t Key16Scan_L(void)
{
  uint8_t i=0; //ѭ������
	int8_t key=-1; //��¼������
	uint16_t tmp=0; //�����ȡ�Ķ˿�ֵ
	for(i=0;i<4;i++)
	{
	  GPIO_ResetBits(GPIOC,GPIO_Pin_4 | GPIO_Pin_5 | GPIO_Pin_6 | GPIO_Pin_7 );
		GPIO_SetBits(GPIOC,GPIO_Pin_4<<(i-1));
		tmp = GPIO_ReadInputData(GPIOC)&0x000f;
		if(tmp != 0x0000)
		{
		  delay_ms(10);
			tmp = GPIO_ReadInputData(GPIOC)&0x000f;
		  if(tmp != 0x000)
			{
				switch(tmp)
			{
				case 0x0001:
				key=1+(i-1);
				break;
				
				case 0x0002:
				key=5+(i-1);
				break;
				
				case 0x0004:
				key=9+(i-1);
				break;
				
				case 0x0008:
				key=13+(i-1);
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











