#include "vartypes.h"
#include "stdint.h"

#ifndef _16KEY_H
#define _16KEY_H

void delay(int n);
void Key16Init(void);		// �����˿ڳ�ʼ��
int8_t Key16Scan(void);	// ����ɨ��
int8_t Key16ScanEx(void);	// ����ɨ��

#endif
