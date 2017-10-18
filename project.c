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
	
		
// UART
//			{
//		  UARTCharPut(UART0_BASE, temp);
//			printf("Type in a character \n");
//			
//			//printf("This is your character \n"); 
//			 printf("Print a variable %c\n\r", temp);
//			//printf("select an option \n");
//			//printf("1: This is the first thing \n");
//			//printf("2: This is the second thing \n");
//			//printf("3: This is the third thing \n");
//	 
//	temp = getc(stdin);
//	 }
			//switch(temp)
			//{
				//case '1': print_chicken;
				//break;
				//case '2': print_something;
				//break;
				//case '3': print_somethingelse;
				//break; 
				
				
		//	}

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
//			}
		}