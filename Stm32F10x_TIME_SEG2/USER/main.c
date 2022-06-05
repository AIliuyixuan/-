// ÎÄ¼þÃ÷£ºmain.c
#include "includes.h"

int main(void)
{
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	Exti_Init();
	Seg_Init();	
	//Tim2_Init();
	while(1)
	{		
//		SegDisplay_2();
		 SegDisplay_6();
	}
}
