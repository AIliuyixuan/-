#include "vartypes.h"
#include "stdint.h"

#ifndef _KEY16_H
#define _KEY16_H

void Key16_Init(void);	// 按键端口初始化
void Key16_Init_L(void);
int8_t Key16Scan(void);	// 按键扫描
void delay_init(void);
int8_t Key16ScanEX(void);
int8_t Key16Scan_L(void);

#endif
