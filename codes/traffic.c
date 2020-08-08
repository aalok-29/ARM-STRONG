#include<lpc214x.h>    // Header file for Philips LPC214x Family Microprocessors
#include<stdint.h>

void delay_ms(uint16_t j)   // Function for delay in milliseconds
{
	uint16_t x,i;
	for(i=0;i<j;++i)
	{
		for(x=0;x<6000;x++);    // Loop to generate 1 millisecond delay
	}
	
}

int main(void)
{
	IO0DIR=0x000000FF;     // Set P0.0 to P0.7 bits as output bits writing 1 in IODIR register corresponding to those bits.
	while(1)
	{
		IO0PIN=IO0PIN | 0x00000001;
		delay_ms(150);
		IO0PIN=IO0PIN & 0xFFFFFF00;
		//delay_ms(150);
		IO0PIN=IO0PIN | 0x00000002;
		delay_ms(150);
		IO0PIN=IO0PIN & 0xFFFFFF00;
		//delay_ms(150);
		IO0PIN=IO0PIN | 0x00000004;
		delay_ms(150);
		IO0PIN=IO0PIN & 0xFFFFFF00;
	}
}