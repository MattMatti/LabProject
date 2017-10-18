#include "SysTick_helper.h"
#include "tm4c123gh6pm.h"

//must be accurate.. for systick setss the systick timer for 10 ms but the set period is set to 14.7 ms

int SetPeriod = 0x0011FFFF;

//Taken from peripheral driver library
void SysTick_Setup()
	
{
	SysTickPeriodSet(SetPeriod); // 14.7 ms wait
	SysTickEnable();
}

// Time delay using busy wait.
// The delay parameter is in units of the 80 MHz core clock. (12.5 ns)
void SysTickWait(unsigned long delay)
{
	NVIC_ST_RELOAD_R = delay-1;  // certain number of counts to wait
  NVIC_ST_CURRENT_R = 0;       // clears the value written to CURRENT
  while((NVIC_ST_CTRL_R & 0x00010000)==0)
	{ // wait for count flag
	}
}


// 800000*12.5ns equals 10ms

void SysTickWait10ms(unsigned long delay)
{
  unsigned long i;
  for(i=0; i<delay; i++)
	{
    SysTickWait(800000);  // wait 10ms
  }
}


