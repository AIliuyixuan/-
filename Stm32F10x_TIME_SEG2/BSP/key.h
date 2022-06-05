#include "vartypes.h"
#include "stdint.h"

#ifndef _KEY_H
#define _KEY_H

void Key_Init(void);	// 按键端口初始化
int8_t KeyScan(void);	// 按键扫描

#endif
