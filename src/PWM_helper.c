#include "PWM_helper.h"
#include "ADC_helper.h"

// this code initializes the pins as pwm and sets the clock cycle to 16 MHZ. It also makes a 50% duty cycle. It then enables the PWM generator 2.
// 
#define Note_E2 3048
#define Note_F2 2874
#define Note_Gb2 2718
#define Note_G2 2552
#define Note_Ab2 2404
#define Note_A2 2272
#define Note_Bb2 2136
#define Note_B2 2032
#define Note_C3 1908
#define Note_Db3 1798
#define Note_D3 1700
#define Note_Eb3 1602
#define Note_E3 1516
#define Note_F3 1428
#define Note_Gb3 1352
#define Note_G3 1276
#define Note_Ab3 1202
#define Note_A3 1136
#define Note_Bb3 1072
#define Note_B3 1012
#define Note_C4 956
#define Note_Db4 902
#define Note_D4 852
#define Note_Eb4 804
#define Note_E4 758
#define Note_F4 716
#define Note_Gb4 676
#define Note_G4 638
#define Note_Ab4 602
#define Note_A4 568
#define Note_Bb4 536
#define Note_B4 506
#define Note_C5 478
#define Note_Db5 450 //450.966
#define Note_D5 426
#define Note_Eb5 402
#define Note_E5 378
#define Note_F5 358
#define Note_Gb5 338
#define Note_G5 318


double DutyCycle;



 void SetupPWM()
 { 
	 //Set the clock
   //SysCtlClockSet(SYSCTL_SYSDIV_1 | SYSCTL_USE_OSC |	SYSCTL_OSC_MAIN | SYSCTL_XTAL_16MHZ);

   //Configure PWM Clock to match system
   SysCtlPWMClockSet(SYSCTL_PWMDIV_64);
   
   // Enable the peripherals used by this program.
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOB);
		SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOC);
    SysCtlPeripheralEnable(SYSCTL_PERIPH_PWM0);  //The Tiva Launchpad has two modules (0 and 1). 
    while(!SysCtlPeripheralReady(SYSCTL_PERIPH_PWM0))
		{
		}
    //configures pins as pwm signals
    GPIOPinConfigure(GPIO_PB6_M0PWM0); // PWM SIGNAL 1 
		GPIOPinConfigure(GPIO_PB7_M0PWM1); // SIGNAL 2
		GPIOPinConfigure(GPIO_PC4_M0PWM6); //SIGNAL 3
		GPIOPinConfigure(GPIO_PC5_M0PWM7); //SIGNAL 4
    
		//makes pin to pwm
    GPIOPinTypePWM(GPIO_PORTB_BASE, GPIO_PIN_6); 
    GPIOPinTypePWM(GPIO_PORTB_BASE, GPIO_PIN_7);
		GPIOPinTypePWM(GPIO_PORTC_BASE, GPIO_PIN_4);
		GPIOPinTypePWM(GPIO_PORTC_BASE, GPIO_PIN_5);
	  
		// Configure the pwm generators down counter no sync
    PWMGenConfigure(PWM0_BASE, PWM_GEN_0, PWM_GEN_MODE_DOWN | PWM_GEN_MODE_NO_SYNC); 	
    PWMGenConfigure(PWM0_BASE, PWM_GEN_3, PWM_GEN_MODE_DOWN | PWM_GEN_MODE_NO_SYNC); 	

    // Enable the PWM generator
    PWMGenEnable(PWM0_BASE, PWM_GEN_0); // enables generator for signals 1 and 2
		PWMGenEnable(PWM0_BASE, PWM_GEN_3); // Enables generator for signals 3 and 4 

    // Turn on the Output pins
    PWMOutputState(PWM0_BASE, PWM_OUT_0_BIT, true); //SIGNAL 1 OUTPUT
		PWMOutputState(PWM0_BASE, PWM_OUT_1_BIT, true); //SIGNAL 2 OUTPUT
		PWMOutputState(PWM0_BASE, PWM_OUT_6_BIT, true); //SIGNAL 3 OUTPUT
		PWMOutputState(PWM0_BASE, PWM_OUT_7_BIT, true); //SIGNAL 4 OUTPUT
 }
 void SetUpPWM0HZ()
{
    //this Sets the Period (expressed in clock ticks)
    PWMGenPeriodSet(PWM0_BASE, PWM_GEN_0, 250000);
    

    // this is setting the PWM duty-50% (Period /2)
    //PWMPulseWidthSet(PWM1_BASE, PWM_OUT_0,100);
		PWMPulseWidthSet(PWM0_BASE, PWM_OUT_0,125000);																									

}
void SetUpPWM82HZ()
{
    //this Sets the Period (expressed in clock ticks 250,000 Hz / Freq = period)
    PWMGenPeriodSet(PWM0_BASE, PWM_GEN_0, Note_E2);
    
    // this is setting the PWM duty-50% (Period /2)
		PWMPulseWidthSet(PWM0_BASE, PWM_OUT_0, Note_E2/DutyCycle);																									

}
void SetUpPWM87HZ()
{
    //this Sets the Period (expressed in clock ticks 250,000 Hz / Freq = period)
    PWMGenPeriodSet(PWM0_BASE, PWM_GEN_2, Note_F2);
    
    // this is setting the PWM duty-50% (Period /2)
		PWMPulseWidthSet(PWM0_BASE, PWM_OUT_5, Note_F2/DutyCycle);																									

}
void SetUpPWM92HZ()
{
    //this Sets the Period (expressed in clock ticks 250,000 Hz / Freq = period)
    PWMGenPeriodSet(PWM0_BASE, PWM_GEN_2, Note_Gb2);
    
    // this is setting the PWM duty-50% (Period /2)
		PWMPulseWidthSet(PWM0_BASE, PWM_OUT_5, Note_Gb2/DutyCycle);																									

}
 void SetUpPWM98HZ()
{
    //this Sets the Period (expressed in clock ticks)
    PWMGenPeriodSet(PWM0_BASE, PWM_GEN_2, Note_G2);
    

    // this is setting the PWM duty-50% (Period /2)
		PWMPulseWidthSet(PWM0_BASE, PWM_OUT_5, Note_G2/DutyCycle);																									

} 
 void SetUpPWM104HZ()
{
    //this Sets the Period (expressed in clock ticks)
    PWMGenPeriodSet(PWM0_BASE, PWM_GEN_2, Note_Ab2);
    

    // this is setting the PWM duty-50% (Period /2)
		PWMPulseWidthSet(PWM0_BASE, PWM_OUT_5,Note_Ab2/DutyCycle);																									

}
void SetUpPWM110HZ()
{
    //this Sets the Period (expressed in clock ticks)
    PWMGenPeriodSet(PWM0_BASE, PWM_GEN_2, Note_A2);
    

    // this is setting the PWM duty-50% (Period /2)
		PWMPulseWidthSet(PWM0_BASE, PWM_OUT_5,Note_A2/DutyCycle);																									

}
void SetUpPWM117HZ()
{
    //this Sets the Period (expressed in clock ticks)
    PWMGenPeriodSet(PWM0_BASE, PWM_GEN_0, Note_Bb2);
    

    // this is setting the PWM duty-50% (Period /2)
		PWMPulseWidthSet(PWM0_BASE, PWM_OUT_0, Note_Bb3/DutyCycle);																									

}
void SetUpPWM123HZ()
{
    //this Sets the Period (expressed in clock ticks)
    PWMGenPeriodSet(PWM0_BASE, PWM_GEN_2, Note_B2);
    

    // this is setting the PWM duty-50% (Period /2)
		PWMPulseWidthSet(PWM0_BASE, PWM_OUT_5, Note_B2/DutyCycle);																									

}
void SetUpPWM131HZ()
{
    //this Sets the Period (expressed in clock ticks)
    PWMGenPeriodSet(PWM0_BASE, PWM_GEN_2, Note_C3);
    

    // this is setting the PWM duty-50% (Period /2)
		PWMPulseWidthSet(PWM0_BASE, PWM_OUT_5, Note_C3/DutyCycle);																									

}
void SetUpPWM139HZ()
{
    //this Sets the Period (expressed in clock ticks)
    PWMGenPeriodSet(PWM0_BASE, PWM_GEN_2, Note_Db3);
    

    // this is setting the PWM duty-50% (Period /2)
		PWMPulseWidthSet(PWM0_BASE, PWM_OUT_5,Note_Db3/DutyCycle);																									

}
void SetUpPWM147HZ()
{
    //this Sets the Period (expressed in clock ticks)
    PWMGenPeriodSet(PWM0_BASE, PWM_GEN_2, Note_D3);
    

    // this is setting the PWM duty-50% (Period /2)
		PWMPulseWidthSet(PWM0_BASE, PWM_OUT_5,Note_D3/DutyCycle);																									

}
void SetUpPWM156HZ()
{
    //this Sets the Period (expressed in clock ticks)
    PWMGenPeriodSet(PWM0_BASE, PWM_GEN_2, Note_Eb3);
    

    // this is setting the PWM duty-50% (Period /2)
		PWMPulseWidthSet(PWM0_BASE, PWM_OUT_5,Note_Eb3/DutyCycle);																									

}
void SetUpPWM165HZ()
{
    //this Sets the Period (expressed in clock ticks)
    PWMGenPeriodSet(PWM0_BASE, PWM_GEN_2, Note_E3);
    

    // this is setting the PWM duty-50% (Period /2)
		PWMPulseWidthSet(PWM0_BASE, PWM_OUT_5,Note_E3/DutyCycle);																									

}
void SetUpPWM175HZ()
{
    //this Sets the Period (expressed in clock ticks)
    PWMGenPeriodSet(PWM0_BASE, PWM_GEN_2, Note_F3);
    

    // this is setting the PWM duty-50% (Period /2)
		PWMPulseWidthSet(PWM0_BASE, PWM_OUT_5,Note_F3/DutyCycle);																									

}
void SetUpPWM185HZ()
{
    //this Sets the Period (expressed in clock ticks)
    PWMGenPeriodSet(PWM0_BASE, PWM_GEN_2, Note_Gb3);
    

    // this is setting the PWM duty-50% (Period /2)
		PWMPulseWidthSet(PWM0_BASE, PWM_OUT_5,Note_Gb3/DutyCycle);																									

}
void SetUpPWM196HZ()
{
    //this Sets the Period (expressed in clock ticks)
    PWMGenPeriodSet(PWM0_BASE, PWM_GEN_2, Note_G3);
    

    // this is setting the PWM duty-50% (Period /2)
		PWMPulseWidthSet(PWM0_BASE, PWM_OUT_5,Note_G3/DutyCycle);																									

}
void SetUpPWM208HZ()
{
    //this Sets the Period (expressed in clock ticks)
    PWMGenPeriodSet(PWM0_BASE, PWM_GEN_2, Note_Ab3);
    

    // this is setting the PWM duty-50% (Period /2)
    //PWMPulseWidthSet(PWM1_BASE, PWM_OUT_0,100);
		PWMPulseWidthSet(PWM0_BASE, PWM_OUT_5, Note_Ab3/DutyCycle);																									

}
 void SetUpPWM220HZ()
{
    //this Sets the Period (expressed in clock ticks)
    PWMGenPeriodSet(PWM0_BASE, PWM_GEN_2, Note_A3);
   

    // this is setting the PWM duty-50% (Period /2)
    //PWMPulseWidthSet(PWM1_BASE, PWM_OUT_0,100);
		PWMPulseWidthSet(PWM0_BASE, PWM_OUT_5, Note_A3/DutyCycle);																								  

    }
 void SetUpPWM233HZ()
{
    //this Sets the Period (expressed in clock ticks)
    PWMGenPeriodSet(PWM0_BASE, PWM_GEN_2, Note_Bb3);
    
    // this is setting the PWM duty-50% (Period /2)
		PWMPulseWidthSet(PWM0_BASE, PWM_OUT_5, Note_Bb3/DutyCycle);																									

}

 void SetUpPWM247HZ()
{
	
    //this Sets the Period (expressed in clock ticks)
    PWMGenPeriodSet(PWM0_BASE, PWM_GEN_2, Note_B3);
    
    // this is setting the PWM duty-50% (Period /2)
		PWMPulseWidthSet(PWM0_BASE, PWM_OUT_5, Note_B3/DutyCycle);																									

}
void SetUpPWM261HZ()
{
    //this Sets the Period (expressed in clock ticks)
    PWMGenPeriodSet(PWM0_BASE, PWM_GEN_2, Note_C4);
    

    // this is setting the PWM duty-50% (Period /2)
		PWMPulseWidthSet(PWM0_BASE, PWM_OUT_5,Note_C4/DutyCycle);																									

}
void SetUpPWM277HZ()
{
    //this Sets the Period (expressed in clock ticks)
    PWMGenPeriodSet(PWM0_BASE, PWM_GEN_2, Note_Db4);
    

    // this is setting the PWM duty-50% (Period /2)
		PWMPulseWidthSet(PWM0_BASE, PWM_OUT_5, Note_Db4/DutyCycle);																									

}
void SetUpPWM294HZ()
{
    //this Sets the Period (expressed in clock ticks)
    PWMGenPeriodSet(PWM0_BASE, PWM_GEN_2, Note_D4);
    

    // this is setting the PWM duty-50% (Period /2)
		PWMPulseWidthSet(PWM0_BASE, PWM_OUT_5,Note_D4/DutyCycle);																									

}
void SetUpPWM311HZ()
{
    //this Sets the Period (expressed in clock ticks)
    PWMGenPeriodSet(PWM0_BASE, PWM_GEN_2, Note_Eb4);
    

    // this is setting the PWM duty-50% (Period /2)
		PWMPulseWidthSet(PWM0_BASE, PWM_OUT_5,Note_Eb4/DutyCycle);																									

}
void SetUpPWM330HZ()
{
    //this Sets the Period (expressed in clock ticks)
    PWMGenPeriodSet(PWM0_BASE, PWM_GEN_2, Note_E4);
    

    // this is setting the PWM duty-50% (Period /2)
		PWMPulseWidthSet(PWM0_BASE, PWM_OUT_5,Note_E4/DutyCycle);																									

}
void SetUpPWM349HZ()
{
    //this Sets the Period (expressed in clock ticks)
    PWMGenPeriodSet(PWM0_BASE, PWM_GEN_2, Note_F4);
    

    // this is setting the PWM duty-50% (Period /2)
		PWMPulseWidthSet(PWM0_BASE, PWM_OUT_5,Note_F4/DutyCycle);																									

}
void SetUpPWM369HZ()
{
    //this Sets the Period (expressed in clock ticks)
    PWMGenPeriodSet(PWM0_BASE, PWM_GEN_2, Note_Gb4);
    

    // this is setting the PWM duty-50% (Period /2)
		PWMPulseWidthSet(PWM0_BASE, PWM_OUT_5,Note_Gb4/DutyCycle);																									

}
void SetUpPWM392HZ()
{
    //this Sets the Period (expressed in clock ticks)
    PWMGenPeriodSet(PWM0_BASE, PWM_GEN_2, Note_G4);
    

    // this is setting the PWM duty-50% (Period /2)
		PWMPulseWidthSet(PWM0_BASE, PWM_OUT_5,Note_G4/DutyCycle);																									

}
void SetUpPWM415HZ()
{
    //this Sets the Period (expressed in clock ticks)
    PWMGenPeriodSet(PWM0_BASE, PWM_GEN_2, Note_Ab4);
    

    // this is setting the PWM duty-50% (Period /2)
		PWMPulseWidthSet(PWM0_BASE, PWM_OUT_5,Note_Ab4/DutyCycle);																									

}
void SetUpPWM440HZ()
{
    //this Sets the Period (expressed in clock ticks)
    PWMGenPeriodSet(PWM0_BASE, PWM_GEN_2, Note_A4);
    

    // this is setting the PWM duty-50% (Period /2)
		PWMPulseWidthSet(PWM0_BASE, PWM_OUT_5,Note_A4/DutyCycle);																									

}
void SetUpPWM466HZ()
{
    //this Sets the Period (expressed in clock ticks)
    PWMGenPeriodSet(PWM0_BASE, PWM_GEN_2, Note_B4);
    

    // this is setting the PWM duty-50% (Period /2)
		PWMPulseWidthSet(PWM0_BASE, PWM_OUT_5,Note_B4/DutyCycle);																									

}
void SetUpPWM493HZ()
{
    //this Sets the Period (expressed in clock ticks)
    PWMGenPeriodSet(PWM0_BASE, PWM_GEN_2, Note_Bb4);
    

    // this is setting the PWM duty-50% (Period /2)
		PWMPulseWidthSet(PWM0_BASE, PWM_OUT_5,Note_Bb4/DutyCycle);																									

}
void SetUpPWM523HZ()
{
    //this Sets the Period (expressed in clock ticks)
    PWMGenPeriodSet(PWM0_BASE, PWM_GEN_2, Note_C5);
    

    // this is setting the PWM duty-50% (Period /2)
		PWMPulseWidthSet(PWM0_BASE, PWM_OUT_5,Note_C5/DutyCycle);																									

}
void SetUpPWM554HZ()
{
    //this Sets the Period (expressed in clock ticks)
    PWMGenPeriodSet(PWM0_BASE, PWM_GEN_2, Note_Db5);
    

    // this is setting the PWM duty-50% (Period /2)
		PWMPulseWidthSet(PWM0_BASE, PWM_OUT_5,Note_Db5/DutyCycle);																									

}
void SetUpPWM587HZ()
{
    //this Sets the Period (expressed in clock ticks)
    PWMGenPeriodSet(PWM0_BASE, PWM_GEN_2, Note_D5);
    

    // this is setting the PWM duty-50% (Period /2)
		PWMPulseWidthSet(PWM0_BASE, PWM_OUT_5,Note_D5/DutyCycle);																									

}
void SetUpPWM622HZ()
{
    //this Sets the Period (expressed in clock ticks)
    PWMGenPeriodSet(PWM0_BASE, PWM_GEN_2, Note_Eb5);
    

    // this is setting the PWM duty-50% (Period /2)
		PWMPulseWidthSet(PWM0_BASE, PWM_OUT_5,Note_Eb5/DutyCycle);																									

}
void SetUpPWM659HZ()
{
    //this Sets the Period (expressed in clock ticks)
    PWMGenPeriodSet(PWM0_BASE, PWM_GEN_2, Note_E5);
    

    // this is setting the PWM duty-50% (Period /2)
		PWMPulseWidthSet(PWM0_BASE, PWM_OUT_5,Note_E5/DutyCycle);																									

}
void SetUpPWM698HZ()
{
    //this Sets the Period (expressed in clock ticks)
    PWMGenPeriodSet(PWM0_BASE, PWM_GEN_2, Note_Gb5);
    

    // this is setting the PWM duty-50% (Period /2)
		PWMPulseWidthSet(PWM0_BASE, PWM_OUT_5,Note_Gb5/DutyCycle);																									

}
void SetUpPWM740HZ()
{
    //this Sets the Period (expressed in clock ticks)
    PWMGenPeriodSet(PWM0_BASE, PWM_GEN_2, Note_Eb3);
    

    // this is setting the PWM duty-50% (Period /2)
		PWMPulseWidthSet(PWM0_BASE, PWM_OUT_5,Note_Eb3/DutyCycle);																									

}
void SetUpPWM784HZ()
{
    //this Sets the Period (expressed in clock ticks)
    PWMGenPeriodSet(PWM0_BASE, PWM_GEN_2, Note_G5);
    

    // this is setting the PWM duty-50% (Period /2)
		PWMPulseWidthSet(PWM0_BASE, PWM_OUT_5,Note_G5/DutyCycle);																									

}
