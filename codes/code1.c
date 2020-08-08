#include<lpc214x.h>      // Header file for Philips LPC214x Family Microprocessors
#include<stdint.h>
void delay(uint16_t n)   // Function for delay in milliseconds
{
	uint16_t i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<6000;j++);     // Loop to generate 1 millisecond delay
	}
}
int main(void)
{
	IO0DIR = 0x000000FF;     // Set P0.0 to P0.7 bits as output bits writing 1 in IODIR register corresponding to those bits.
	while(1)
	{
		IO0PIN = IO0PIN | 0x000000FF;    // Make P0.0 to P0.7 HIGH while others are unchanged 
		delay(30);      // Delay for 30 milliseconds 
		IO0PIN = IO0PIN & 0xFFFFFF00;    // Make P0.0 to P0.7 LOW while other bits unchanged
		delay(30);      // Delay for 30 milliseconds 
	}
}