#include <LPC214x.h>     // Header file for Philips LPC214x Family Microprocessors
void pwm_init(void)
{
	PINSEL0= 0x8002;
	PWMPCR = 0x600;
	PWMMR0 =150000;
	PWMTCR = 0x09;
	PWMMCR = 0x02;
}
// starts the main program
void main()
{
	pwm_init();
	while(1);
	{
		PWMMR1 = 75000;
		PWMMR2 = 100000;
		PWMLER = 0x6;
	}
}