#include "vartypes.h"
#include "stdint.h"

#ifndef _SEG_H
#define _SEG_H

void Seg_Init(void);	// 按键端口初始化
void SegDisplay(int8_t num);	// 显示
void SegDisplay_2(void);
void SegDisplay_4(void);

#endif
