//Matthew Matti & Lakeysha Green
// I tried to initialize everything and set up the ADC pins and then try to correlate it to the photoresistor but I didn't get the chance and 
// sort of didn't know how.. I will try this weekend. sorry yo
#include "ADC_helper.h"

uint32_t ADC_Values;
uint32_t ADC_ValuesString2;
uint32_t ADC_ValuesString3;
uint32_t ADC_ValuesString4;


//set up for 1 soft pot "string1" SET UP ADC PINS ANDSETUP ADC FOR EVERY STRING...
void SetupADCPins1()
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
	ADCSequenceStepConfigure(ADC0_BASE, 0, 0, ADC_CTL_CH0 | ADC_CTL_END);
//  ADCSequenceStepConfigure(ADC0_BASE, 0, 1, ADC_CTL_CH1 );	
//  ADCSequenceStepConfigure(ADC0_BASE, 0, 2, ADC_CTL_CH2 );	
//	ADCSequenceStepConfigure(ADC0_BASE, 0, 3, ADC_CTL_CH4 );	
//	ADCSequenceStepConfigure(ADC0_BASE, 0, 4, ADC_CTL_CH5 );	
//	ADCSequenceStepConfigure(ADC0_BASE, 0, 5, ADC_CTL_CH6 );	
//	ADCSequenceStepConfigure(ADC0_BASE, 0, 6, ADC_CTL_CH7 	
	
	
	//ADCSequenceStepConfigure(ADC0_BASE, 0, 0,	ADC_CTL_IE | ADC_CTL_END | ADC_CTL_CH1 );
	
	
	ADCSequenceEnable(ADC0_BASE, 0); //enables the sequence 0

		
}

void ADCReadString1()
{
	uint32_t string1;
	uint32_t string2;
	uint32_t string3;
	uint32_t string4;
	//
	//
	ADCProcessorTrigger(ADC0_BASE, 0); // Trigger the sample sequence above (sequence 0)

	//
	// Wait until the sample sequence has completed.
	//
	while(ADCBusy(ADC0_BASE)){};
	//while(!ADCIntStatus(ADC0_BASE, 0, false))
	{
	}
	//
	// Read the value from the ADC.
	//
	
	string1 = ADCSequenceDataGet(ADC0_BASE, 0, &ADC_Values);
	
		if (string1 >0x555 && string1 < 0xFFF) // less than or equal to this voltage range
	      {
	         SetUpPWM200HZ(); 	
				}
	

	}
	
void ADCReadString2()
{
	uint32_t string2;
	//
	//
	ADCProcessorTrigger(ADC0_BASE, 0); // Trigger the sample sequence above (sequence 0)

	//
	// Wait until the sample sequence has completed.
	//
	while(ADCBusy(ADC0_BASE)){};
	//while(!ADCIntStatus(ADC0_BASE, 0, false))
	{
	}
	//
	// Read the value from the ADC.
	//
	
	string2 = ADCSequenceDataGet(ADC0_BASE, 0, &ADC_ValuesString2);
	
		if (string2 >0x555 && string2 < 0xFFF) // less than or equal to this voltage range
	      {
	         SetUpPWM200HZ(); 	
				}
	

	}

void ADCReadString3()
{
	uint32_t string3;
	//
	//
	ADCProcessorTrigger(ADC0_BASE, 0); // Trigger the sample sequence above (sequence 0)

	//
	// Wait until the sample sequence has completed.
	//
	while(ADCBusy(ADC0_BASE)){};
	//while(!ADCIntStatus(ADC0_BASE, 0, false))
	{
	}
	//
	// Read the value from the ADC.
	//
	
	string3 = ADCSequenceDataGet(ADC0_BASE, 0, &ADC_Values);
	
		if (string3 >0x555 && string3 < 0xFFF) // less than or equal to this voltage range
	      {
	         SetUpPWM200HZ(); 	
				}
	

	}
void ADCReadString4()
{
	uint32_t string4;
	//
	//
	ADCProcessorTrigger(ADC0_BASE, 0); // Trigger the sample sequence above (sequence 0)

	//
	// Wait until the sample sequence has completed.
	//
	while(ADCBusy(ADC0_BASE)){};
	//while(!ADCIntStatus(ADC0_BASE, 0, false))
	{
	}
	//
	// Read the value from the ADC.
	//
	
	string4 = ADCSequenceDataGet(ADC0_BASE, 0, &ADC_Values);
	
		if (string4 >0x555 && string4 < 0xFFF) // less than or equal to this voltage range
	      {
	         SetUpPWM200HZ(); 	
				}
	

	}
