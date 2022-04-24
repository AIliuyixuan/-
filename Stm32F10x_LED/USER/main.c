#include "includes.h"
int main(void)
{
	LEDInit();
	delay_init();
	LED0(0);
	LED1(0);
	
	while(1)
	{
		LED0(1);
		LED1(0);
		delay_ms(3000);
		LED0(0);
		LED1(1);
		delay_ms(3000);
	}
}
