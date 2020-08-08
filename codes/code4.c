#include<lpc214x.h>

void delay_ms(unsigned int count)      // Function for delay in milliseconds
{
  unsigned int j=0,i=0;
  for(j=0;j<count;j++)
  {
    for(i=0;i<6000;i++);        // Loop to generate 1 millisecond delay
  }
}
/* start the main program */
int main() 
{
IO0DIR = (1<<2);   //Configure P0.2 as Output

while(1)
{
	IO0SET=(1<<2);    //Making Port0 pin 2 as HIGH
	delay_ms(30);    // Delay for 30 milliseconds
	IO0CLR=(1<<2);     //Making Port0 pin 2 as LOW
	delay_ms(30);    // Delay for 30 milliseconds
}
}
