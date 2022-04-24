#include "vartypes.h"
#include "stdint.h"

#ifndef _KEY_H
#define _KEY_H

void KEY0(Int08U);
void KEY1(Int08U);

#define KEY0 GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_2) //PB2
#define KEY1 GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_3) //PB3



void Key_Init(void);	// 按键端口初始化
int8_t KeyScan(void);	// 按键扫描

#endif
