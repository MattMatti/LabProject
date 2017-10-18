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
		// Check if the peripheral access is enabled.
    while(!SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOF))
    {
    
		}
    
    while(1)
		{
		//if (string1 < 0xFFF);
	
  UpdateMyButtons();
//	
		if(GPIOPinRead(GPIO_PORTF_BASE,GPIO_PIN_0) == 0)
				{
					GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_3,GPIO_PIN_3);
				}
				else {
		GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_3,0);					
			SetUpPWM200HZ();
  		
		
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