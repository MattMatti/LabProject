//Matthew Matti & Lakeysha Green 
#include "project.h"

//*****************************************************************************
//
// Working on the ADC today 9/27/17
//
//*****************************************************************************

#ifdef DEBUG
void
__error__(char *pcFilename, uint32_t ui32Line)
{
}
#endif

//void (print_donkey)
	
//void SetupHardware()
//{
//       UartSetup();
//}

int  main(void)
{
	 SysCtlClockSet(SYSCTL_SYSDIV_1 | SYSCTL_USE_OSC | SYSCTL_OSC_MAIN | SYSCTL_XTAL_16MHZ); //set clock speed to 16 MHZ
	
    SysCtlPeripheralEnable(SYSCTL_PERIPH_ADC0); //enables ADC module 0
    SysCtlPeripheralReset(SYSCTL_PERIPH_ADC0); // resets ADC module 0 
	  //uint8_t temp;
	
    //SetupHardware();
	
		// Check if the peripheral access is enabled.
    while(!SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOF))
    {
    
		}
    
    while(1)
		{
		if (string1 < 0xFFF);
    {
			SetUpPWM200HZ();
		}			
    else
		{
		} 
	
		

//GPIO
	

//	GPIOSetup();
//	
//  UpdateMYButtons();
//	
//	if(MyButtons.SW1==0)
//				{
//				}
//				else
//				{				
//		
//			TurnOnLEDs();
//	
//	}
//	if(MyButtons.SW2==0)
//				{
//				}
//				else
//				{	

//				TurnOnLEDs2();
//		
//}
//			
			}
		}