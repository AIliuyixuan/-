// ÎÄ¼şÃ÷£ºmain.c
#include "includes.h"
void delay(int n)
{
	int i,j;
	for(i=0; i<n; i++)
		for(j=0; j<5000; j++);
}

int main(void)
{
	RGB_Init();
	while(1)
	{
		RGB_On_Off(1,0,0);
		delay(2000);
		RGB_On_Off(0,1,0);
		delay(2000);
		RGB_On_Off(0,0,1);
		delay(2000);
	}
}
