//Matthew Matti & Lakeysha Green 
#include "project.h"

//*****************************************************************************
//
// 10/18 Starting lab project
//
//*****************************************************************************

#ifdef DEBUG
void
__error__(char *pcFilename, uint32_t ui32Line)
{
}
#endif


int  main(void)
{
	 SysCtlClockSet(SYSCTL_SYSDIV_1 | SYSCTL_USE_OSC | SYSCTL_OSC_MAIN | SYSCTL_XTAL_16MHZ); //set clock speed to 16 MHZ
	
    SysCtlPeripheralEnable(SYSCTL_PERIPH_ADC0); //enables ADC module 0
    SysCtlPeripheralReset(SYSCTL_PERIPH_ADC0); // resets ADC module 0 
	  
	  GPIOSetup();
		//UART_setup();
	  SetupADCPins();
		SetupADC();
	  SetupPWM();
		FPUEnable();
		FPULazyStackingEnable();
	
	  
		// Check if the peripheral access is enabled.
    while(!SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOE))
    {
		}   
  while(1)
	{
		read_adc();
		ReadFSR1();
		ADCReadString1();
		ADCReadString2();
		ReadDutyKnob();
		
		
	}
		} 
	
