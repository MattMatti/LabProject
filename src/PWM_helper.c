#include "PWM_helper.h"

// this code initializes the pins as pwm and sets the clock cycle to 16 MHZ. It also makes a 50% duty cycle. It then enables the PWM generator 2.
// 

 void SetupPWM()
 { 
	 //Set the clock
   //SysCtlClockSet(SYSCTL_SYSDIV_1 | SYSCTL_USE_OSC |	SYSCTL_OSC_MAIN | SYSCTL_XTAL_16MHZ);

   //Configure PWM Clock to match system
   SysCtlPWMClockSet(SYSCTL_PWMDIV_64);
   
   // Enable the peripherals used by this program.
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOE);
    SysCtlPeripheralEnable(SYSCTL_PERIPH_PWM0);  //The Tiva Launchpad has two modules (0 and 1). 
    while(!SysCtlPeripheralReady(SYSCTL_PERIPH_PWM0))
		{
		}
    //Configure PF1 Pin as PWM
    GPIOPinConfigure(GPIO_PE5_M0PWM5); // pin1 port E is pwm5 of module 0 
	
    //GPIOPinTypePWM(GPIO_PORTF_BASE, GPIO_PIN_1 | GPIO_PIN_2 | GPIO_PIN_3);
     GPIOPinTypePWM(GPIO_PORTE_BASE, GPIO_PIN_5); //makes pin to PWM
    
	//Configure PWM Options
    //PWM_GEN_2 Covers M1PWM4 and M1PWM5
    //PWM_GEN_3 Covers M1PWM6 and M1PWM7 See page 207 4/11/13 DriverLib doc
   // PWMGenConfigure(PWM1_BASE, PWM_GEN_2, PWM_GEN_MODE_DOWN | PWM_GEN_MODE_NO_SYNC); 
    PWMGenConfigure(PWM0_BASE, PWM_GEN_2, PWM_GEN_MODE_DOWN | PWM_GEN_MODE_NO_SYNC); 	

    // Enable the PWM generator
    PWMGenEnable(PWM0_BASE, PWM_GEN_2);

    // Turn on the Output pins
    PWMOutputState(PWM0_BASE, PWM_OUT_5_BIT, true);
 }
 void SetUpPWM0HZ()
{
    //this Sets the Period (expressed in clock ticks)
    PWMGenPeriodSet(PWM0_BASE, PWM_GEN_2, 250000);
    

    // this is setting the PWM duty-50% (Period /2)
    //PWMPulseWidthSet(PWM1_BASE, PWM_OUT_0,100);
		PWMPulseWidthSet(PWM0_BASE, PWM_OUT_5,125000);																									

}
void SetUpPWM82HZ()
{
    //this Sets the Period (expressed in clock ticks 250,000 Hz / Freq = period)
    PWMGenPeriodSet(PWM0_BASE, PWM_GEN_2, 3048);
    
    // this is setting the PWM duty-50% (Period /2)
		PWMPulseWidthSet(PWM0_BASE, PWM_OUT_5, 1524);																									

}
void SetUpPWM87HZ()
{
    //this Sets the Period (expressed in clock ticks 250,000 Hz / Freq = period)
    PWMGenPeriodSet(PWM0_BASE, PWM_GEN_2, 2874);
    
    // this is setting the PWM duty-50% (Period /2)
		PWMPulseWidthSet(PWM0_BASE, PWM_OUT_5, 1437);																									

}
void SetUpPWM92HZ()
{
    //this Sets the Period (expressed in clock ticks 250,000 Hz / Freq = period)
    PWMGenPeriodSet(PWM0_BASE, PWM_GEN_2, 2718);
    
    // this is setting the PWM duty-50% (Period /2)
		PWMPulseWidthSet(PWM0_BASE, PWM_OUT_5, 1359);																									

}
 void SetUpPWM98HZ()
{
    //this Sets the Period (expressed in clock ticks)
    PWMGenPeriodSet(PWM0_BASE, PWM_GEN_2, 2552);
    

    // this is setting the PWM duty-50% (Period /2)
		PWMPulseWidthSet(PWM0_BASE, PWM_OUT_5,1276);																									

} 
 void SetUpPWM104HZ()
{
    //this Sets the Period (expressed in clock ticks)
    PWMGenPeriodSet(PWM0_BASE, PWM_GEN_2, 2404);
    

    // this is setting the PWM duty-50% (Period /2)
		PWMPulseWidthSet(PWM0_BASE, PWM_OUT_5,1202);																									

}
void SetUpPWM110HZ()
{
    //this Sets the Period (expressed in clock ticks)
    PWMGenPeriodSet(PWM0_BASE, PWM_GEN_2, 2272);
    

    // this is setting the PWM duty-50% (Period /2)
		PWMPulseWidthSet(PWM0_BASE, PWM_OUT_5,1136);																									

}
void SetUpPWM117HZ()
{
    //this Sets the Period (expressed in clock ticks)
    PWMGenPeriodSet(PWM0_BASE, PWM_GEN_2, 2136);
    

    // this is setting the PWM duty-50% (Period /2)
		PWMPulseWidthSet(PWM0_BASE, PWM_OUT_5, 1068);																									

}
void SetUpPWM123HZ()
{
    //this Sets the Period (expressed in clock ticks)
    PWMGenPeriodSet(PWM0_BASE, PWM_GEN_2, 2032);
    

    // this is setting the PWM duty-50% (Period /2)
		PWMPulseWidthSet(PWM0_BASE, PWM_OUT_5,1016);																									

}
void SetUpPWM131HZ()
{
    //this Sets the Period (expressed in clock ticks)
    PWMGenPeriodSet(PWM0_BASE, PWM_GEN_2, 1908);
    

    // this is setting the PWM duty-50% (Period /2)
		PWMPulseWidthSet(PWM0_BASE, PWM_OUT_5, 954);																									

}
void SetUpPWM139HZ()
{
    //this Sets the Period (expressed in clock ticks)
    PWMGenPeriodSet(PWM0_BASE, PWM_GEN_2, 1798);
    

    // this is setting the PWM duty-50% (Period /2)
		PWMPulseWidthSet(PWM0_BASE, PWM_OUT_5,899);																									

}
void SetUpPWM147HZ()
{
    //this Sets the Period (expressed in clock ticks)
    PWMGenPeriodSet(PWM0_BASE, PWM_GEN_2, 1700);
    

    // this is setting the PWM duty-50% (Period /2)
		PWMPulseWidthSet(PWM0_BASE, PWM_OUT_5,850);																									

}
void SetUpPWM156HZ()
{
    //this Sets the Period (expressed in clock ticks)
    PWMGenPeriodSet(PWM0_BASE, PWM_GEN_2, 1602);
    

    // this is setting the PWM duty-50% (Period /2)
		PWMPulseWidthSet(PWM0_BASE, PWM_OUT_5,801);																									

}
void SetUpPWM165HZ()
{
    //this Sets the Period (expressed in clock ticks)
    PWMGenPeriodSet(PWM0_BASE, PWM_GEN_2, 1516);
    

    // this is setting the PWM duty-50% (Period /2)
		PWMPulseWidthSet(PWM0_BASE, PWM_OUT_5,758);																									

}
void SetUpPWM175HZ()
{
    //this Sets the Period (expressed in clock ticks)
    PWMGenPeriodSet(PWM0_BASE, PWM_GEN_2, 1428);
    

    // this is setting the PWM duty-50% (Period /2)
		PWMPulseWidthSet(PWM0_BASE, PWM_OUT_5,714);																									

}
void SetUpPWM185HZ()
{
    //this Sets the Period (expressed in clock ticks)
    PWMGenPeriodSet(PWM0_BASE, PWM_GEN_2, 1352);
    

    // this is setting the PWM duty-50% (Period /2)
		PWMPulseWidthSet(PWM0_BASE, PWM_OUT_5,676);																									

}
void SetUpPWM196HZ()
{
    //this Sets the Period (expressed in clock ticks)
    PWMGenPeriodSet(PWM0_BASE, PWM_GEN_2, 1276);
    

    // this is setting the PWM duty-50% (Period /2)
		PWMPulseWidthSet(PWM0_BASE, PWM_OUT_5,638);																									

}
void SetUpPWM208HZ()
{
    //this Sets the Period (expressed in clock ticks)
    PWMGenPeriodSet(PWM0_BASE, PWM_GEN_2, 1202);
    

    // this is setting the PWM duty-50% (Period /2)
    //PWMPulseWidthSet(PWM1_BASE, PWM_OUT_0,100);
		PWMPulseWidthSet(PWM0_BASE, PWM_OUT_5,601);																									

}
 void SetUpPWM300HZ()
{
    //this Sets the Period (expressed in clock ticks)
    PWMGenPeriodSet(PWM0_BASE, PWM_GEN_2, 834);
   

    // this is setting the PWM duty-50% (Period /2)
    //PWMPulseWidthSet(PWM1_BASE, PWM_OUT_0,100);
		PWMPulseWidthSet(PWM0_BASE, PWM_OUT_5,417);																								  

    }
 void SetUpPWM400HZ()
{
    //this Sets the Period (expressed in clock ticks)
    PWMGenPeriodSet(PWM0_BASE, PWM_GEN_2, 626);
    
    // this is setting the PWM duty-50% (Period /2)
		PWMPulseWidthSet(PWM0_BASE, PWM_OUT_5, 313);																									

}

 void SetUpPWM500HZ()
{
    //this Sets the Period (expressed in clock ticks)
    PWMGenPeriodSet(PWM0_BASE, PWM_GEN_2, 626);
    
    // this is setting the PWM duty-50% (Period /2)
		PWMPulseWidthSet(PWM0_BASE, PWM_OUT_5, 313);																									

}
