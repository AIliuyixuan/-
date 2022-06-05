#include "vartypes.h"
#include "stdint.h"

#ifndef _LED_H
#define _LED_H

void LEDInit(void);
void LED0(Int08U);
void LED1(Int08U);
uint8_t GetLed0State(void);
uint8_t GetLed1State(void);

#endif
