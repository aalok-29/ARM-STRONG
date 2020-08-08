#include <lpc214x.h>      // Header file for Philips LPC214x Family Microprocessors
#include <stdint.h>
void delay_ms(unsigned int count)     // Function for delay in milliseconds
{
  unsigned int j=0,i=0;
  for(j=0;j<count;j++)
  {
    for(i=0;i<6000;i++);           // Loop to generate 1 millisecond delay
  }
}

/* start the main program */
int main() 
{
    PINSEL2 = 0x000000;  //Configure the P1 Pins for GPIO;
    IODIR1 = 0xffffffff; //Configure the P1 pins as OUTPUT;

  while(1)
    {
       IOSET1 = 0xffffffff;     // Make all the Port pins as high  
         delay_ms(30);    // Delay for 30 milliseconds

       IOCLR1 = 0xffffffff;     // Make all the Port pins as low  
         delay_ms(30);    // Delay for 30 milliseconds
    }
}