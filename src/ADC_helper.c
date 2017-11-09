//Matthew Matti
#include "ADC_helper.h"

uint32_t ADC_Values[13];
//uint32_t ADC_ValuesString2;
//uint32_t ADC_ValuesString3;
//uint32_t ADC_ValuesString4;


//set up for 1 soft pot "string1" SET UP ADC PINS ANDSETUP ADC FOR EVERY STRING...
void SetupADCPins()
{
	GPIOPinTypeADC(GPIO_PORTE_BASE,GPIO_PIN_1);  
}

void SetupADC()
{

	SetupADCPins(); //setup the GPIO
	
	//
	// Enable the ADC0 module.
	//
	SysCtlPeripheralEnable(SYSCTL_PERIPH_ADC0); //module 1/2.. module 2/2 not used
	//
	// Wait for the ADC0 module to be ready.
	//
	while(!SysCtlPeripheralReady(SYSCTL_PERIPH_ADC0)) 
	{
	}
	
	ADCReferenceSet(ADC0_BASE, ADC_REF_INT); //for reference so a 3 V supply must be given to the AVREF pin
	//but for now we are using the interior voltage
	// Enable the first sample sequencer to capture the value of channel 0 when
	// the processor trigger occurs.
	//
	ADCSequenceDisable(ADC0_BASE,0); 
	ADCSequenceConfigure(ADC0_BASE, 0, ADC_TRIGGER_PROCESSOR, 0); 
	ADCSequenceStepConfigure(ADC0_BASE, 0, 0, ADC_CTL_CH2 | ADC_CTL_END);
//  ADCSequenceStepConfigure(ADC0_BASE, 0, 1, ADC_CTL_CH1 );	
//  ADCSequenceStepConfigure(ADC0_BASE, 0, 2, ADC_CTL_CH2 );	
//	ADCSequenceStepConfigure(ADC0_BASE, 0, 3, ADC_CTL_CH4 );	
//	ADCSequenceStepConfigure(ADC0_BASE, 0, 4, ADC_CTL_CH5 );	
//	ADCSequenceStepConfigure(ADC0_BASE, 0, 5, ADC_CTL_CH6 );	
//	ADCSequenceStepConfigure(ADC0_BASE, 0, 6, ADC_CTL_CH7 	
	
	
	//ADCSequenceStepConfigure(ADC0_BASE, 0, 0,	ADC_CTL_IE | ADC_CTL_END | ADC_CTL_CH1 );
	
	 __nop();
	__nop();
	__nop();
	ADCSequenceEnable(ADC0_BASE, 0); //enables the sequence 0
  __nop();
	__nop();
	__nop();
		
}

void ADCReadString1()
{
	uint32_t string1;
	volatile uint32_t ui32Loop;
	
	ADCProcessorTrigger(ADC0_BASE, 0); // Trigger the sample sequence above (sequence 0)

	//
	// Wait until the sample sequence has completed.
	//
	while(ADCBusy(ADC0_BASE));
	//while(!ADCIntStatus(ADC0_BASE, 0, false))
	
	//
	// Read the value from the ADC.
	//
   ADCSequenceDataGet(ADC0_BASE, 0, &string1);
	//ADCSequenceDataGet(ADC0_BASE, 0, &ADC_Values);// reads number of channels read
//   printf("This is the value of string1 %d\n\r", string1);
			//printf("This is the value of string1 %d\n\r", string1);
  if ((string1 > 0x000) && (string1 < 0x200)) // less than or equal to this voltage range
	{
		SetUpPWM0HZ();
	}
  else
	{
		         	
	}
	
	if ((string1 > 0x200) && (string1 < 0x2EE)) // less than or equal to this voltage range
	{
		SetUpPWM82HZ();
		GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_3, 0xF);         	
	}
  else
	{
		GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_3, 0x0);         	
	}

	if ((string1 > 0x2EE) && (string1 < 0x3DC)) // less than or equal to this voltage range
	{
		SetUpPWM87HZ();
		GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_2, 0xF);         	
	}
  else
	{

		GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_2, 0x0);         	
	}
	 	
	if ((string1 > 0x3DC) && (string1 < 0x4CA)) // less than or equal to this voltage range
	{
		SetUpPWM92HZ();
		GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_1, 0xF);         	
	}
  else
	{
		GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_1, 0x0);         	
	}
	if ((string1 > 0x4CA) && (string1 < 0x5B8)) // less than or equal to this voltage range
	{
		SetUpPWM98HZ();
		GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_1, 0xF);         	
	}
  else
	{
		GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_1, 0x0);         	
	}
	if ((string1 > 0x5B8) && (string1 < 0x6A6)) // less than or equal to this voltage range
	{
		SetUpPWM104HZ();
		GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_1, 0xF);         	
	}
  else
	{
		GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_1, 0x0);         	
	}
	if ((string1 > 0x6A6) && (string1 < 0x794)) // less than or equal to this voltage range
	{
		SetUpPWM110HZ();
		GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_1, 0xF);         	
	}
  else
	{
		GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_1, 0x0);         	
	}
	if ((string1 > 0x794) && (string1 < 0x882)) // less than or equal to this voltage range
	{
		SetUpPWM117HZ();
		GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_1, 0xF);         	
	}
  else
	{
		GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_1, 0x0);         	
	}
	if ((string1 > 0x882) && (string1 < 0x970)) // less than or equal to this voltage range
	{
		SetUpPWM123HZ();
		GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_1, 0xF);         	
	}
  else
	{
		GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_1, 0x0);         	
	}
	if ((string1 > 0x970) && (string1 < 0xA5E)) // less than or equal to this voltage range
	{
		SetUpPWM131HZ();
		GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_1, 0xF);         	
	}
  else
	{
		GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_1, 0x0);         	
	}
	if ((string1 > 0xA5E) && (string1 < 0xB4C)) // less than or equal to this voltage range
	{
		SetUpPWM139HZ();
		GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_1, 0xF);         	
	}
  else
	{
		GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_1, 0x0);         	
	}
	if ((string1 > 0xB4C) && (string1 < 0xC3A)) // less than or equal to this voltage range
	{
		SetUpPWM147HZ();
		GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_1, 0xF);         	
	}
  else
	{
		GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_1, 0x0);         	
	}
	if ((string1 > 0xC3A) && (string1 < 0xD28)) // less than or equal to this voltage range
	{
		SetUpPWM156HZ();
		GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_1, 0xF);         	
	}
  else
	{
		GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_1, 0x0);         	
	}
	if ((string1 > 0xD28) && (string1 < 0xE16)) // less than or equal to this voltage range
	{
		SetUpPWM165HZ();
		GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_1, 0xF);         	
	}
  else
	{
		GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_1, 0x0);         	
	}
	if ((string1 > 0xE16) && (string1 < 0xF04)) // less than or equal to this voltage range
	{
		SetUpPWM175HZ();
		GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_1, 0xF);         	
	}
  else
	{
		GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_1, 0x0);         	
	}
	if ((string1 > 0xF04) && (string1 < 0xFFF)) // less than or equal to this voltage range
	{
		SetUpPWM185HZ();
		GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_1, 0xF);         	
	}
  else
	{
		GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_1, 0x0);         	
	}
}

// void ADCReadString2()
//{
//	uint32_t string2;
//	//
//	//
//	ADCProcessorTrigger(ADC0_BASE, 0); // Trigger the sample sequence above (sequence 0)

//	//
//	// Wait until the sample sequence has completed.
//	//
//	while(ADCBusy(ADC0_BASE)){};
//	//while(!ADCIntStatus(ADC0_BASE, 0, false))
//	{
//	}
//	//
//	// Read the value from the ADC.
//	//
//	
//	string2 = ADCSequenceDataGet(ADC0_BASE, 0, &ADC_ValuesString2);
//	
//		if (string2 >0x555 && string2 < 0xFFF) // less than or equal to this voltage range
//	      {
//	         SetUpPWM200HZ(); 	
//				}
//	

//	}

//void ADCReadString3()
//{
//	uint32_t string3;
//	//
//	//
//	ADCProcessorTrigger(ADC0_BASE, 0); // Trigger the sample sequence above (sequence 0)

//	//
//	// Wait until the sample sequence has completed.
//	//
//	while(ADCBusy(ADC0_BASE)){};
//	//while(!ADCIntStatus(ADC0_BASE, 0, false))
//	{
//	}
//	//
//	// Read the value from the ADC.
//	//
//	
//	string3 = ADCSequenceDataGet(ADC0_BASE, 0, &ADC_Values);
//	
//		if (string3 >0x555 && string3 < 0xFFF) // less than or equal to this voltage range
//	      {
//	         SetUpPWM200HZ(); 	
//				}
//	

//	}
//void ADCReadString4()
//{
//	uint32_t string4;
//	//
//	//
//	ADCProcessorTrigger(ADC0_BASE, 0); // Trigger the sample sequence above (sequence 0)

//	//
//	// Wait until the sample sequence has completed.
//	//
//	while(ADCBusy(ADC0_BASE)){};
//	//while(!ADCIntStatus(ADC0_BASE, 0, false))
//	{
//	}
//	//
//	// Read the value from the ADC.
//	//
//	
//	string4 = ADCSequenceDataGet(ADC0_BASE, 0, &ADC_Values);
//	
//		if (string4 >0x555 && string4 < 0xFFF) // less than or equal to this voltage range
//	      {
//	         SetUpPWM200HZ(); 	
//				}
	

	// }
