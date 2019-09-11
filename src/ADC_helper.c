//Matthew Matti
#include "ADC_helper.h"
uint32_t ADC_Values[8];
uint32_t ADCBuffer[13];

float one = 1.1000;
float two = 1.2000;
float three = 1.3000;
float four = 1.4000;
float five = 1.5000;
float six = 1.60000;
float seven = 1.7000;
float eight = 1.8000;
float nine = 1.9000;


//struct ADC_strings myguitarproject;

//uint32_t ADC_ValuesString2;
//uint32_t ADC_ValuesString3;
//uint32_t ADC_ValuesString4;


//set up for 1 soft pot "string1" SET UP ADC PINS ANDSETUP ADC FOR EVERY STRING...
void SetupADCPins()
{
	GPIOPinTypeADC(GPIO_PORTE_BASE,GPIO_PIN_1); 
  GPIOPinTypeADC(GPIO_PORTE_BASE,GPIO_PIN_2);	
  GPIOPinTypeADC(GPIO_PORTE_BASE,GPIO_PIN_4);	
	GPIOPinTypeADC(GPIO_PORTD_BASE,GPIO_PIN_3);	
	
 
}

void SetupADC()
{

	SetupADCPins(); //setup the GPIO
	
	
	// Enable the ADC0 module.
	SysCtlPeripheralEnable(SYSCTL_PERIPH_ADC0); //module 1/2.. module 2/2 not used
	
	// Wait for the ADC0 module to be ready.
	while(!SysCtlPeripheralReady(SYSCTL_PERIPH_ADC0)) 
	{
	}	
	ADCReferenceSet(ADC0_BASE, ADC_REF_INT); //for reference so a 3 V supply must be given to the AVREF pin
	//but for now we are using the interior voltage
	
	
	ADCSequenceDisable(ADC0_BASE,0); // Enable the first sample sequencer to capture the value of channel 0 when
	                                 // the processor trigger occurs.
	ADCSequenceConfigure(ADC0_BASE, 0, ADC_TRIGGER_PROCESSOR, 0); 
	ADCSequenceStepConfigure(ADC0_BASE, 0, 0, ADC_CTL_CH9); //duty cycle pot
  ADCSequenceStepConfigure(ADC0_BASE, 0, 1, ADC_CTL_CH1);	//FSR1
  ADCSequenceStepConfigure(ADC0_BASE, 0, 2, ADC_CTL_CH2); // string 1
	ADCSequenceStepConfigure(ADC0_BASE, 0, 3, ADC_CTL_CH4 | ADC_CTL_END ); //string 2
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

void ReadDutyKnob()	
{ 
	//uint32_t DutyCycle; 
	uint32_t DutyValue;
	

	 
	
  //How_many = (ADCSequenceDataGet(ADC0_BASE, 0, &ADC_Values[0]));
  //if (How_many == 3)
	//{ 
		DutyValue = ADC_Values[0];
//	}
	if ((DutyValue > 0x000) && (DutyValue < 0x100))
	{
		(DutyCycle = 0.20);
	}
	if ((DutyValue > 0x100) && (DutyValue < 0x200))
	{
		(DutyCycle = 0.40);
	}
	if ((DutyValue > 0x000) && (DutyValue < 0x222))
	{
		(DutyCycle = 0.60);
	}
	if ((DutyValue > 0x000) && (DutyValue < 0x222))
	{
		(DutyCycle = 0.80);
	}
	if ((DutyValue > 0x000) && (DutyValue < 0x222))
	{
		(DutyCycle = 2);
	}
	
	if ((DutyValue > 0x222) && (DutyValue < 0x444))
	{
		(DutyCycle = 4);
	}

	if ((DutyValue > 0x444) && (DutyValue < 0x666))
	{
		(DutyCycle = 6);
	}
  
	if ((DutyValue > 0x666) && (DutyValue < 0x888))
	{
		(DutyCycle = 8);
	}
	
	if ((DutyValue > 0x888) && (DutyValue < 0xFFF))
	{
		(DutyCycle = 10);
	}

}
void ReadFSR1()
{
	uint32_t FSR1;
	uint32_t FSRI2C;

	
	//ADCProcessorTrigger(ADC0_BASE, 0); // Trigger the sample sequence above (sequence 0)

	// Wait until the sample sequence has completed.
	//while(ADCBusy(ADC0_BASE));
	//while(!ADCIntStatus(ADC0_BASE, 0, false))
	
	// Read the value from the ADC.

		FSR1 = ADC_Values[1];

	
	if (FSR1 > 0x700)
	{
	FSR1 = FSRI2C;	
	}
	else 
	{
   __nop();
	}
}

void read_adc()
{
	uint32_t How_many1;

	ADCProcessorTrigger(ADC0_BASE, 0); // Trigger the sample sequence above (sequence 0)

	while(ADCBusy(ADC0_BASE));

  How_many1 = (ADCSequenceDataGet(ADC0_BASE, 0, &ADC_Values[0]));
	if (How_many1 == 4)
	{
		ADCBuffer[0]=ADC_Values[0]; //duty cycle
		ADCBuffer[1]=ADC_Values[1]; //fsr1
		ADCBuffer[2]=ADC_Values[2]; //string 1
		ADCBuffer[3]=ADC_Values[3]; //string 2
	}
}

void ADCReadString1()
{
	uint32_t string1;
	//uint32_t How_many1;
	
	//ADCProcessorTrigger(ADC0_BASE, 0); // Trigger the sample sequence above (sequence 0)

	// Wait until the sample sequence has completed.
	//while(ADCBusy(ADC0_BASE));
	//while(!ADCIntStatus(ADC0_BASE, 0, false))
	
	// Read the value from the ADC.
  //How_many1 = (ADCSequenceDataGet(ADC0_BASE, 0, &ADC_Values[0]));
  //printf("This is the value of string1 %d\n\r", string1);
	//printf("This is the value of string1 %d\n\r", string1);
	//if (How_many1 == 3)
	//{
	string1 = ADC_Values[2];
	
		//this Sets the Period (expressed in clock ticks 250,000 Hz / Freq = period)
//	PWMGenPeriodSet(PWM0_BASE, PWM_GEN_2, 4095 - ADC_Values[2]);
    
   // this is setting the PWM duty-50% (Period /2)
//	PWMPulseWidthSet(PWM0_BASE, PWM_OUT_5, ADC_Values[2]%10);
	
	//}
  if ((string1 > 0x000) && (string1 < 0x200)) // less than or equal to this voltage range
	{
		SetUpPWM0HZ();
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
		GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_3, 0xF);         	
	}
  else
	{
		GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_3, 0x0);         	
	}
	if ((string1 > 0x5B8) && (string1 < 0x6A6)) // less than or equal to this voltage range
	{
		SetUpPWM104HZ();
		GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_2, 0xF);         	
	}
  else
	{
		GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_2, 0x0);         	
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
		GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_2, 0xF);         	
	}
  else
	{
		GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_2, 0x0);         	
	}
	if ((string1 > 0x882) && (string1 < 0x970)) // less than or equal to this voltage range
	{
		SetUpPWM123HZ();
		GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_3, 0xF);         	
	}
  else
	{
		GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_3, 0x0);         	
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
		GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_2, 0xF);         	
	}
  else
	{
		GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_2, 0x0);         	
	}
	if ((string1 > 0xB4C) && (string1 < 0xC3A)) // less than or equal to this voltage range
	{
		SetUpPWM147HZ();
		GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_3, 0xF);         	
	}
  else
	{
		GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_3, 0x0);         	
	}
	if ((string1 > 0xC3A) && (string1 < 0xD28)) // less than or equal to this voltage range
	{
		SetUpPWM156HZ();
		GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_2, 0xF);         	
	}
  else
	{
		GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_2, 0x0);         	
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
		GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_2, 0xF);         	
	}
  else
	{
		GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_2, 0x0);         	
	}
	if ((string1 > 0xF04) && (string1 < 0xFFF)) // less than or equal to this voltage range
	{
		SetUpPWM185HZ();
		GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_3, 0xF);         	
	}
  else
	{
		GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_3, 0x0);         	
	}
}



void ADCReadString2()
{
uint32_t string2;
	//uint32_t How_many1;
	
	//ADCProcessorTrigger(ADC0_BASE, 0); // Trigger the sample sequence above (sequence 0)

	// Wait until the sample sequence has completed.
	//while(ADCBusy(ADC0_BASE));
	//while(!ADCIntStatus(ADC0_BASE, 0, false))
	
	// Read the value from the ADC.
  //How_many1 = (ADCSequenceDataGet(ADC0_BASE, 0, &ADC_Values[0]));
  //printf("This is the value of string1 %d\n\r", string1);
	//printf("This is the value of string1 %d\n\r", string1);
	//if (How_many1 == 3)
	//{
	string2 = ADC_Values[3];
	
		//this Sets the Period (expressed in clock ticks 250,000 Hz / Freq = period)
//	PWMGenPeriodSet(PWM0_BASE, PWM_GEN_2, 4095 - ADC_Values[2]);
    
   // this is setting the PWM duty-50% (Period /2)
//	PWMPulseWidthSet(PWM0_BASE, PWM_OUT_5, ADC_Values[2]%10);
	
	//}
  if ((string2 > 0x000) && (string2 < 0x200)) // less than or equal to this voltage range
	{
		
		SetUpPWM0HZ();
	}
	
	if ((string2 > 0x200) && (string2 < 0x2EE)) // less than or equal to this voltage range
	{
		SetUpPWM82HZ();
		GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_3, 0xF);         	
	}
  else
	{
		GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_3, 0x0);         	
	}

	if ((string2 > 0x2EE) && (string2 < 0x3DC)) // less than or equal to this voltage range
	{
		SetUpPWM87HZ();
		GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_2, 0xF);         	
	}
  else
	{
		GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_2, 0x0);         	
	}
	 	
	if ((string2 > 0x3DC) && (string2 < 0x4CA)) // less than or equal to this voltage range
	{
		SetUpPWM92HZ();
		GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_1, 0xF);         	
	}
  else
	{
		GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_1, 0x0);         	
	}
	if ((string2 > 0x4CA) && (string2 < 0x5B8)) // less than or equal to this voltage range
	{
		SetUpPWM98HZ();
		GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_3, 0xF);         	
	}
  else
	{
		GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_3, 0x0);         	
	}
	if ((string2 > 0x5B8) && (string2 < 0x6A6)) // less than or equal to this voltage range
	{
		SetUpPWM104HZ();
		GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_2, 0xF);         	
	}
  else
	{
		GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_2, 0x0);         	
	}
	if ((string2 > 0x6A6) && (string2 < 0x794)) // less than or equal to this voltage range
	{
		SetUpPWM110HZ();
		GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_1, 0xF);         	
	}
  else
	{
		GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_1, 0x0);         	
	}
	if ((string2 > 0x794) && (string2 < 0x882)) // less than or equal to this voltage range
	{
		SetUpPWM117HZ();
		GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_2, 0xF);         	
	}
  else
	{
		GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_2, 0x0);         	
	}
	if ((string2 > 0x882) && (string2 < 0x970)) // less than or equal to this voltage range
	{
		SetUpPWM123HZ();
		GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_3, 0xF);         	
	}
  else
	{
		GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_3, 0x0);         	
	}
	if ((string2 > 0x970) && (string2 < 0xA5E)) // less than or equal to this voltage range
	{
		SetUpPWM131HZ();
		GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_1, 0xF);         	
	}
  else
	{
		GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_1, 0x0);         	
	}
	if ((string2 > 0xA5E) && (string2 < 0xB4C)) // less than or equal to this voltage range
	{
		SetUpPWM139HZ();
		GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_2, 0xF);         	
	}
  else
	{
		GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_2, 0x0);         	
	}
	if ((string2 > 0xB4C) && (string2 < 0xC3A)) // less than or equal to this voltage range
	{
		SetUpPWM147HZ();
		GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_3, 0xF);         	
	}
  else
	{
		GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_3, 0x0);         	
	}
	if ((string2 > 0xC3A) && (string2 < 0xD28)) // less than or equal to this voltage range
	{
		SetUpPWM156HZ();
		GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_2, 0xF);         	
	}
  else
	{
		GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_2, 0x0);         	
	}
	if ((string2 > 0xD28) && (string2 < 0xE16)) // less than or equal to this voltage range
	{
		SetUpPWM165HZ();
		GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_1, 0xF);         	
	}
  else
	{
		GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_1, 0x0);         	
	}
	if ((string2 > 0xE16) && (string2 < 0xF04)) // less than or equal to this voltage range
	{
		SetUpPWM175HZ();
		GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_2, 0xF);         	
	}
  else
	{
		GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_2, 0x0);         	
	}
	if ((string2 > 0xF04) && (string2 < 0xFFF)) // less than or equal to this voltage range
	{
		SetUpPWM185HZ();
		GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_3, 0xF);         	
	}
  else
	{
		GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_3, 0x0);         	
	}
}
// void ADCReadString3()
// void ADCReadString4()
// void ReadFSR1()
// void ReadFSR2)
// void ReadFSR3()
// void ReadFSR4()
