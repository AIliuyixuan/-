#include "vartypes.h"
#include "stdint.h"

#ifndef _16KEY_H
#define _16KEY_H

void delay(int n);
void Key16Init(void);		// 按键端口初始化
int8_t Key16Scan(void);	// 按键扫描
int8_t Key16ScanEx(void);	// 按键扫描

#endif
