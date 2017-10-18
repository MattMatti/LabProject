#include "GPIO_helper.h"

void UpdateMYbuttons()
	{
		uint8_t WorkingMode;
		
		WorkingMode= GPIOPinRead(GPIO_PORTF_BASE,GPIO_PIN_4);
		
		if (WorkingMode !=0) MyButtons.SW1=0;
		else MyButtons.SW1 = 1;

		WorkingMode= GPIOPinRead(GPIO_PORTF_BASE,GPIO_PIN_0);
		
		if (WorkingMode!=0) MyButtons.SW2=0;
		else MyButtons.SW2 = 1;

		
	}
	void GPIOSetup()
	{
		SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);
		
	{
	}
	
		GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE, GPIO_PIN_1);
		GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE, GPIO_PIN_2);
    GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE, GPIO_PIN_3);
		
	}
	void TurnOnLEDs()
	{		

		 volatile uint32_t ui32Loop;
		// Turn the LED red
			GPIOPinWrite (GPIO_PORTF_BASE, GPIO_PIN_1, 0XF );
			 // Delay for a bit.
       for(ui32Loop = 0; ui32Loop < 1000000; ui32Loop++)
	     {
			 }
			 GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_1, 0x0);
       // Delay for a bit.
       for(ui32Loop = 0; ui32Loop < 1000000; ui32Loop++)
       {
			 }				 
			
			//Turn the LED blue
			GPIOPinWrite (GPIO_PORTF_BASE, GPIO_PIN_2, 0XF );
			 // Delay for a bit.
       for(ui32Loop = 0; ui32Loop < 1000000; ui32Loop++)		
        {
        } 	
	
		  GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_2, 0x0);

       // Delay for a bit.
        for(ui32Loop = 0; ui32Loop < 1000000; ui32Loop++)
        {
				}					

			
			// Turn the LED green
			GPIOPinWrite (GPIO_PORTF_BASE, GPIO_PIN_3, 0XF );
      // Delay for a bit.
        for(ui32Loop = 0; ui32Loop < 1000000; ui32Loop++)
        {
        }
																										         
      GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_3, 0x0);

        for(ui32Loop = 0; ui32Loop < 1000000; ui32Loop++) // Delay for a bit.
				{
				}
			//purple 	
			GPIOPinWrite (GPIO_PORTF_BASE, GPIO_PIN_2, 0XF );
			GPIOPinWrite (GPIO_PORTF_BASE, GPIO_PIN_1, 0XF );
				
				for(ui32Loop = 0; ui32Loop < 1000000; ui32Loop++)
				{
				}
			
			GPIOPinWrite (GPIO_PORTF_BASE, GPIO_PIN_2, 0X0 );
			GPIOPinWrite (GPIO_PORTF_BASE, GPIO_PIN_1, 0X0 );
				
				for(ui32Loop = 0; ui32Loop < 1000000; ui32Loop++)
				{
				}
			//yellow
			GPIOPinWrite (GPIO_PORTF_BASE, GPIO_PIN_3, 0XF );
			GPIOPinWrite (GPIO_PORTF_BASE, GPIO_PIN_1, 0XF );
				
				for(ui32Loop = 0; ui32Loop < 1000000; ui32Loop++)
        {
        }
				
      GPIOPinWrite (GPIO_PORTF_BASE, GPIO_PIN_3, 0X0 );
			GPIOPinWrite (GPIO_PORTF_BASE, GPIO_PIN_1, 0X0 );
				
				for(ui32Loop = 0; ui32Loop < 1000000; ui32Loop++)
				{
				}
			//cyan
			GPIOPinWrite (GPIO_PORTF_BASE, GPIO_PIN_3, 0XF );
			GPIOPinWrite (GPIO_PORTF_BASE, GPIO_PIN_2, 0XF );
				
				for(ui32Loop = 0; ui32Loop < 1000000; ui32Loop++)
				{
				}
	    GPIOPinWrite (GPIO_PORTF_BASE, GPIO_PIN_3, 0X0 );
			GPIOPinWrite (GPIO_PORTF_BASE, GPIO_PIN_2, 0X0 );

				for(ui32Loop = 0; ui32Loop < 1000000; ui32Loop++)
				{
				}
				
			//white	
			GPIOPinWrite (GPIO_PORTF_BASE, GPIO_PIN_3, 0XF );
			GPIOPinWrite (GPIO_PORTF_BASE, GPIO_PIN_2, 0XF );
			GPIOPinWrite (GPIO_PORTF_BASE, GPIO_PIN_1, 0XF );
				
				for(ui32Loop = 0; ui32Loop < 1000000; ui32Loop++)
				
				{
				}

	    GPIOPinWrite (GPIO_PORTF_BASE, GPIO_PIN_3, 0X0 );
			GPIOPinWrite (GPIO_PORTF_BASE, GPIO_PIN_2, 0X0 );
			GPIOPinWrite (GPIO_PORTF_BASE, GPIO_PIN_1, 0X0 );
				
				for(ui32Loop = 0; ui32Loop < 1000000; ui32Loop++)

        {
        }
			}
	
	void TurnOnLEDs2()
	{
		volatile uint32_t ui32Loop;
					//purple 	
			GPIOPinWrite (GPIO_PORTF_BASE, GPIO_PIN_2, 0XF );
			GPIOPinWrite (GPIO_PORTF_BASE, GPIO_PIN_1, 0XF );
				
				for(ui32Loop = 0; ui32Loop < 1000000; ui32Loop++)
				{
				}
			
			GPIOPinWrite (GPIO_PORTF_BASE, GPIO_PIN_2, 0X0 );
			GPIOPinWrite (GPIO_PORTF_BASE, GPIO_PIN_1, 0X0 );
				
				for(ui32Loop = 0; ui32Loop < 1000000; ui32Loop++)
				{
				}
			//yellow
			GPIOPinWrite (GPIO_PORTF_BASE, GPIO_PIN_3, 0XF );
			GPIOPinWrite (GPIO_PORTF_BASE, GPIO_PIN_1, 0XF );
				
				for(ui32Loop = 0; ui32Loop < 1000000; ui32Loop++)
        {
        }
				
      GPIOPinWrite (GPIO_PORTF_BASE, GPIO_PIN_3, 0X0 );
			GPIOPinWrite (GPIO_PORTF_BASE, GPIO_PIN_1, 0X0 );
				
				for(ui32Loop = 0; ui32Loop < 1000000; ui32Loop++)
				{
				}
			//cyan
			GPIOPinWrite (GPIO_PORTF_BASE, GPIO_PIN_3, 0XF );
			GPIOPinWrite (GPIO_PORTF_BASE, GPIO_PIN_2, 0XF );
				
				for(ui32Loop = 0; ui32Loop < 1000000; ui32Loop++)
				{
				}
	    GPIOPinWrite (GPIO_PORTF_BASE, GPIO_PIN_3, 0X0 );
			GPIOPinWrite (GPIO_PORTF_BASE, GPIO_PIN_2, 0X0 );

				for(ui32Loop = 0; ui32Loop < 1000000; ui32Loop++)
				{
				}
				
			//white	
			GPIOPinWrite (GPIO_PORTF_BASE, GPIO_PIN_3, 0XF );
			GPIOPinWrite (GPIO_PORTF_BASE, GPIO_PIN_2, 0XF );
			GPIOPinWrite (GPIO_PORTF_BASE, GPIO_PIN_1, 0XF );
				
				for(ui32Loop = 0; ui32Loop < 1000000; ui32Loop++)
				
				{
				}

	    GPIOPinWrite (GPIO_PORTF_BASE, GPIO_PIN_3, 0X0 );
			GPIOPinWrite (GPIO_PORTF_BASE, GPIO_PIN_2, 0X0 );
			GPIOPinWrite (GPIO_PORTF_BASE, GPIO_PIN_1, 0X0 );
				
				for(ui32Loop = 0; ui32Loop < 1000000; ui32Loop++)

        {
        }
			}
			