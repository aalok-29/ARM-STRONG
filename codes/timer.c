#include<LPC214x.h>       // Header file for Philips LPC214x Family Microprocessors
void delay(unsigned n)    // Function for delay in milliseconds using timer mode
{
	T0MR0= n;   // Loading our time limit in Match Register
	T0MCR = 0x00000004;    // Stop on MR0
	T0TCR = 1;     // Enable Timer 0
	while(T0TC !=T0MR0);    // waits until TC reaches the desired delay
	T0TC = 0;       // Reset Timer
}
// main function starts
int main(void)
{
	IODIR0 = 0x000000FF;      // Set P0.0 to P0.7 bits as output bits writing 1 in IODIR register corresponding to those bits.
	while(1)
	{
		IOSET0 = 0x000000FF;   // Making P0.0 to P0.7 pins HIGH
		delay(10000);   // delay of 10000 milliseconds
		IOCLR0 = 0x000000FF;   // Making P0.0 to P0.7 pins LOW
		delay(10000);   // delay of 10000 milliseconds
	}
}