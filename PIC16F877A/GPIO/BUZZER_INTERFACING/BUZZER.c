#include<pic.h>
#define _XTAL_FREQ 4000000
void main()
{
	TRISB0=0;
	while(1)
	{
		RB0=1;
		__delay_ms(500);
		RB0=0;
		__delay_ms(500);
		}
		}