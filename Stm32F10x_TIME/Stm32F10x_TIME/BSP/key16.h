#include "vartypes.h"
#include "stdint.h"

#ifndef _KEY16_H
#define _KEY16_H

void Key16_Init(void);	// �����˿ڳ�ʼ��
void Key16_Init_L(void);
int8_t Key16Scan(void);	// ����ɨ��
void delay_init(void);
int8_t Key16ScanEX(void);
int8_t Key16Scan_L(void);

#endif
