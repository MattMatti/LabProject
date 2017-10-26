#include "PWM_helper.h"

// this code initializes the pins as pwm and sets the clock cycle to 16 MHZ. It also makes a 50% duty cycle. It then enables the PWM generator 2.
// 

 void SetUpPWM200HZ()
{

    //Set the clock
   //SysCtlClockSet(SYSCTL_SYSDIV_1 | SYSCTL_USE_OSC |	SYSCTL_OSC_MAIN | SYSCTL_XTAL_16MHZ);

   //Configure PWM Clock to match system
   SysCtlPWMClockSet(SYSCTL_PWMDIV_1);
   
   // Enable the peripherals used by this program.
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOE);
    SysCtlPeripheralEnable(SYSCTL_PERIPH_PWM0);  //The Tiva Launchpad has two modules (0 and 1). 
    while(!SysCtlPeripheralReady(SYSCTL_PERIPH_PWM0))
		{
		}
    //Configure PF1 Pin as PWM
    GPIOPinConfigure(GPIO_PE5_M0PWM5); // pin1 port F is pwm5 of module 1 
	
    //GPIOPinTypePWM(GPIO_PORTF_BASE, GPIO_PIN_1 | GPIO_PIN_2 | GPIO_PIN_3);
     GPIOPinTypePWM(GPIO_PORTE_BASE, GPIO_PIN_5); //makes pin to PWM
    
	//Configure PWM Options
    //PWM_GEN_2 Covers M1PWM4 and M1PWM5
    //PWM_GEN_3 Covers M1PWM6 and M1PWM7 See page 207 4/11/13 DriverLib doc
   // PWMGenConfigure(PWM1_BASE, PWM_GEN_2, PWM_GEN_MODE_DOWN | PWM_GEN_MODE_NO_SYNC); 
    PWMGenConfigure(PWM0_BASE, PWM_GEN_2, PWM_GEN_MODE_DOWN | PWM_GEN_MODE_NO_SYNC); 

    //this Sets the Period (expressed in clock ticks)
    PWMGenPeriodSet(PWM0_BASE, PWM_GEN_2, 200);
    //PWMGenPeriodSet(PWM1_BASE, PWM_GEN_5, 200);

    // this is setting the PWM duty-50% (Period /2)
    //PWMPulseWidthSet(PWM1_BASE, PWM_OUT_0,100);
		PWMPulseWidthSet(PWM0_BASE, PWM_OUT_5,100);																									

    // Enable the PWM generator
    PWMGenEnable(PWM0_BASE, PWM_GEN_2);

    // Turn on the Output pins
    PWMOutputState(PWM0_BASE, PWM_OUT_5_BIT, true);
    


    }
 void SetUpPWM300HZ()
{

    //Set the clock
   //SysCtlClockSet(SYSCTL_SYSDIV_1 | SYSCTL_USE_OSC |	SYSCTL_OSC_MAIN | SYSCTL_XTAL_16MHZ);

   //Configure PWM Clock to match system
   SysCtlPWMClockSet(SYSCTL_PWMDIV_1);
   
   // Enable the peripherals used by this program.
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOE);
    SysCtlPeripheralEnable(SYSCTL_PERIPH_PWM0);  //The Tiva Launchpad has two modules (0 and 1). 
    while(!SysCtlPeripheralReady(SYSCTL_PERIPH_PWM0))
		{
		}
    //Configure PF1 Pin as PWM
    GPIOPinConfigure(GPIO_PE5_M0PWM5); // pin1 port F is pwm5 of module 1 
	
    //GPIOPinTypePWM(GPIO_PORTF_BASE, GPIO_PIN_1 | GPIO_PIN_2 | GPIO_PIN_3);
     GPIOPinTypePWM(GPIO_PORTE_BASE, GPIO_PIN_5); //makes pin to PWM
    
	//Configure PWM Options
    //PWM_GEN_2 Covers M1PWM4 and M1PWM5
    //PWM_GEN_3 Covers M1PWM6 and M1PWM7 See page 207 4/11/13 DriverLib doc
   // PWMGenConfigure(PWM1_BASE, PWM_GEN_2, PWM_GEN_MODE_DOWN | PWM_GEN_MODE_NO_SYNC); 
    PWMGenConfigure(PWM0_BASE, PWM_GEN_2, PWM_GEN_MODE_DOWN | PWM_GEN_MODE_NO_SYNC); 

    //this Sets the Period (expressed in clock ticks)
    PWMGenPeriodSet(PWM0_BASE, PWM_GEN_2, 200);
    //PWMGenPeriodSet(PWM1_BASE, PWM_GEN_5, 200);

    // this is setting the PWM duty-50% (Period /2)
    //PWMPulseWidthSet(PWM1_BASE, PWM_OUT_0,100);
		PWMPulseWidthSet(PWM0_BASE, PWM_OUT_5,100);																									

    // Enable the PWM generator
    PWMGenEnable(PWM0_BASE, PWM_GEN_2);

    // Turn on the Output pins
    PWMOutputState(PWM0_BASE, PWM_OUT_5_BIT, true);
    


    }
 void SetUpPWM400HZ()
{

    //Set the clock
   //SysCtlClockSet(SYSCTL_SYSDIV_1 | SYSCTL_USE_OSC |	SYSCTL_OSC_MAIN | SYSCTL_XTAL_16MHZ);

   //Configure PWM Clock to match system
   SysCtlPWMClockSet(SYSCTL_PWMDIV_1);
   
   // Enable the peripherals used by this program.
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOE);
    SysCtlPeripheralEnable(SYSCTL_PERIPH_PWM0);  //The Tiva Launchpad has two modules (0 and 1). 
    while(!SysCtlPeripheralReady(SYSCTL_PERIPH_PWM0))
		{
		}
    //Configure PF1 Pin as PWM
    GPIOPinConfigure(GPIO_PE5_M0PWM5); // pin1 port F is pwm5 of module 1 
	
    //GPIOPinTypePWM(GPIO_PORTF_BASE, GPIO_PIN_1 | GPIO_PIN_2 | GPIO_PIN_3);
     GPIOPinTypePWM(GPIO_PORTE_BASE, GPIO_PIN_5); //makes pin to PWM
    
	//Configure PWM Options
    //PWM_GEN_2 Covers M1PWM4 and M1PWM5
    //PWM_GEN_3 Covers M1PWM6 and M1PWM7 See page 207 4/11/13 DriverLib doc
   // PWMGenConfigure(PWM1_BASE, PWM_GEN_2, PWM_GEN_MODE_DOWN | PWM_GEN_MODE_NO_SYNC); 
    PWMGenConfigure(PWM0_BASE, PWM_GEN_2, PWM_GEN_MODE_DOWN | PWM_GEN_MODE_NO_SYNC); 

    //this Sets the Period (expressed in clock ticks)
    PWMGenPeriodSet(PWM0_BASE, PWM_GEN_2, 200);
    //PWMGenPeriodSet(PWM1_BASE, PWM_GEN_5, 200);

    // this is setting the PWM duty-50% (Period /2)
    //PWMPulseWidthSet(PWM1_BASE, PWM_OUT_0,100);
		PWMPulseWidthSet(PWM0_BASE, PWM_OUT_5,100);																									

    // Enable the PWM generator
    PWMGenEnable(PWM0_BASE, PWM_GEN_2);

    // Turn on the Output pins
    PWMOutputState(PWM0_BASE, PWM_OUT_5_BIT, true);
    


    }
 void SetUpPWM500HZ()
{

    //Set the clock
   //SysCtlClockSet(SYSCTL_SYSDIV_1 | SYSCTL_USE_OSC |	SYSCTL_OSC_MAIN | SYSCTL_XTAL_16MHZ);

   //Configure PWM Clock to match system
   SysCtlPWMClockSet(SYSCTL_PWMDIV_1);
   
   // Enable the peripherals used by this program.
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOE);
    SysCtlPeripheralEnable(SYSCTL_PERIPH_PWM0);  //The Tiva Launchpad has two modules (0 and 1). 
    while(!SysCtlPeripheralReady(SYSCTL_PERIPH_PWM0))
		{
		}
    //Configure PF1 Pin as PWM
    GPIOPinConfigure(GPIO_PE5_M0PWM5); // pin1 port F is pwm5 of module 1 
	
    //GPIOPinTypePWM(GPIO_PORTF_BASE, GPIO_PIN_1 | GPIO_PIN_2 | GPIO_PIN_3);
     GPIOPinTypePWM(GPIO_PORTE_BASE, GPIO_PIN_5); //makes pin to PWM
    
	//Configure PWM Options
    //PWM_GEN_2 Covers M1PWM4 and M1PWM5
    //PWM_GEN_3 Covers M1PWM6 and M1PWM7 See page 207 4/11/13 DriverLib doc
   // PWMGenConfigure(PWM1_BASE, PWM_GEN_2, PWM_GEN_MODE_DOWN | PWM_GEN_MODE_NO_SYNC); 
    PWMGenConfigure(PWM0_BASE, PWM_GEN_2, PWM_GEN_MODE_DOWN | PWM_GEN_MODE_NO_SYNC); 

    //this Sets the Period (expressed in clock ticks)
    PWMGenPeriodSet(PWM0_BASE, PWM_GEN_2, 200);
    //PWMGenPeriodSet(PWM1_BASE, PWM_GEN_5, 200);

    // this is setting the PWM duty-50% (Period /2)
    //PWMPulseWidthSet(PWM1_BASE, PWM_OUT_0,100);
		PWMPulseWidthSet(PWM0_BASE, PWM_OUT_5,100);																									

    // Enable the PWM generator
    PWMGenEnable(PWM0_BASE, PWM_GEN_2);

    // Turn on the Output pins
    PWMOutputState(PWM0_BASE, PWM_OUT_5_BIT, true);
    


    }
 void SetUpPWM600HZ()
{

    //Set the clock
   //SysCtlClockSet(SYSCTL_SYSDIV_1 | SYSCTL_USE_OSC |	SYSCTL_OSC_MAIN | SYSCTL_XTAL_16MHZ);

   //Configure PWM Clock to match system
   SysCtlPWMClockSet(SYSCTL_PWMDIV_1);
   
   // Enable the peripherals used by this program.
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOE);
    SysCtlPeripheralEnable(SYSCTL_PERIPH_PWM0);  //The Tiva Launchpad has two modules (0 and 1). 
    while(!SysCtlPeripheralReady(SYSCTL_PERIPH_PWM0))
		{
		}
    //Configure PF1 Pin as PWM
    GPIOPinConfigure(GPIO_PE5_M0PWM5); // pin1 port F is pwm5 of module 1 
	
    //GPIOPinTypePWM(GPIO_PORTF_BASE, GPIO_PIN_1 | GPIO_PIN_2 | GPIO_PIN_3);
     GPIOPinTypePWM(GPIO_PORTE_BASE, GPIO_PIN_5); //makes pin to PWM
    
	//Configure PWM Options
    //PWM_GEN_2 Covers M1PWM4 and M1PWM5
    //PWM_GEN_3 Covers M1PWM6 and M1PWM7 See page 207 4/11/13 DriverLib doc
   // PWMGenConfigure(PWM1_BASE, PWM_GEN_2, PWM_GEN_MODE_DOWN | PWM_GEN_MODE_NO_SYNC); 
    PWMGenConfigure(PWM0_BASE, PWM_GEN_2, PWM_GEN_MODE_DOWN | PWM_GEN_MODE_NO_SYNC); 

    //this Sets the Period (expressed in clock ticks)
    PWMGenPeriodSet(PWM0_BASE, PWM_GEN_2, 200);
    //PWMGenPeriodSet(PWM1_BASE, PWM_GEN_5, 200);

    // this is setting the PWM duty-50% (Period /2)
    //PWMPulseWidthSet(PWM1_BASE, PWM_OUT_0,100);
		PWMPulseWidthSet(PWM0_BASE, PWM_OUT_5,100);																									

    // Enable the PWM generator
    PWMGenEnable(PWM0_BASE, PWM_GEN_2);

    // Turn on the Output pins
    PWMOutputState(PWM0_BASE, PWM_OUT_5_BIT, true);
    


    }
 void SetUpPWM700HZ()
{

    //Set the clock
   //SysCtlClockSet(SYSCTL_SYSDIV_1 | SYSCTL_USE_OSC |	SYSCTL_OSC_MAIN | SYSCTL_XTAL_16MHZ);

   //Configure PWM Clock to match system
   SysCtlPWMClockSet(SYSCTL_PWMDIV_1);
   
   // Enable the peripherals used by this program.
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOE);
    SysCtlPeripheralEnable(SYSCTL_PERIPH_PWM0);  //The Tiva Launchpad has two modules (0 and 1). 
    while(!SysCtlPeripheralReady(SYSCTL_PERIPH_PWM0))
		{
		}
    //Configure PF1 Pin as PWM
    GPIOPinConfigure(GPIO_PE5_M0PWM5); // pin1 port F is pwm5 of module 1 
	
    //GPIOPinTypePWM(GPIO_PORTF_BASE, GPIO_PIN_1 | GPIO_PIN_2 | GPIO_PIN_3);
     GPIOPinTypePWM(GPIO_PORTE_BASE, GPIO_PIN_5); //makes pin to PWM
    
	//Configure PWM Options
    //PWM_GEN_2 Covers M1PWM4 and M1PWM5
    //PWM_GEN_3 Covers M1PWM6 and M1PWM7 See page 207 4/11/13 DriverLib doc
   // PWMGenConfigure(PWM1_BASE, PWM_GEN_2, PWM_GEN_MODE_DOWN | PWM_GEN_MODE_NO_SYNC); 
    PWMGenConfigure(PWM0_BASE, PWM_GEN_2, PWM_GEN_MODE_DOWN | PWM_GEN_MODE_NO_SYNC); 

    //this Sets the Period (expressed in clock ticks)
    PWMGenPeriodSet(PWM0_BASE, PWM_GEN_2, 200);
    //PWMGenPeriodSet(PWM1_BASE, PWM_GEN_5, 200);

    // this is setting the PWM duty-50% (Period /2)
    //PWMPulseWidthSet(PWM1_BASE, PWM_OUT_0,100);
		PWMPulseWidthSet(PWM0_BASE, PWM_OUT_5,100);																									

    // Enable the PWM generator
    PWMGenEnable(PWM0_BASE, PWM_GEN_2);

    // Turn on the Output pins
    PWMOutputState(PWM0_BASE, PWM_OUT_5_BIT, true);
    


    }
 void SetUpPWM800HZ()
{

    //Set the clock
   //SysCtlClockSet(SYSCTL_SYSDIV_1 | SYSCTL_USE_OSC |	SYSCTL_OSC_MAIN | SYSCTL_XTAL_16MHZ);

   //Configure PWM Clock to match system
   SysCtlPWMClockSet(SYSCTL_PWMDIV_1);
   
   // Enable the peripherals used by this program.
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOE);
    SysCtlPeripheralEnable(SYSCTL_PERIPH_PWM0);  //The Tiva Launchpad has two modules (0 and 1). 
    while(!SysCtlPeripheralReady(SYSCTL_PERIPH_PWM0))
		{
		}
    //Configure PF1 Pin as PWM
    GPIOPinConfigure(GPIO_PE5_M0PWM5); // pin1 port F is pwm5 of module 1 
	
    //GPIOPinTypePWM(GPIO_PORTF_BASE, GPIO_PIN_1 | GPIO_PIN_2 | GPIO_PIN_3);
     GPIOPinTypePWM(GPIO_PORTE_BASE, GPIO_PIN_5); //makes pin to PWM
    
	//Configure PWM Options
    //PWM_GEN_2 Covers M1PWM4 and M1PWM5
    //PWM_GEN_3 Covers M1PWM6 and M1PWM7 See page 207 4/11/13 DriverLib doc
   // PWMGenConfigure(PWM1_BASE, PWM_GEN_2, PWM_GEN_MODE_DOWN | PWM_GEN_MODE_NO_SYNC); 
    PWMGenConfigure(PWM0_BASE, PWM_GEN_2, PWM_GEN_MODE_DOWN | PWM_GEN_MODE_NO_SYNC); 

    //this Sets the Period (expressed in clock ticks)
    PWMGenPeriodSet(PWM0_BASE, PWM_GEN_2, 200);
    //PWMGenPeriodSet(PWM1_BASE, PWM_GEN_5, 200);

    // this is setting the PWM duty-50% (Period /2)
    //PWMPulseWidthSet(PWM1_BASE, PWM_OUT_0,100);
		PWMPulseWidthSet(PWM0_BASE, PWM_OUT_5,100);																									

    // Enable the PWM generator
    PWMGenEnable(PWM0_BASE, PWM_GEN_2);

    // Turn on the Output pins
    PWMOutputState(PWM0_BASE, PWM_OUT_5_BIT, true);
    


    }
 void SetUpPWM900HZ()
		{
			//Set the clock
   //SysCtlClockSet(SYSCTL_SYSDIV_1 | SYSCTL_USE_OSC |	SYSCTL_OSC_MAIN | SYSCTL_XTAL_16MHZ);

   //Configure PWM Clock to match system
   SysCtlPWMClockSet(SYSCTL_PWMDIV_1);
   
   // Enable the peripherals used by this program.
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOE);
    SysCtlPeripheralEnable(SYSCTL_PERIPH_PWM0);  //The Tiva Launchpad has two modules (0 and 1). 
    while(!SysCtlPeripheralReady(SYSCTL_PERIPH_PWM0))
		{
		}
    //Configure PF1 Pin as PWM
    GPIOPinConfigure(GPIO_PE5_M0PWM5); // pin1 port F is pwm5 of module 1 
	
    //GPIOPinTypePWM(GPIO_PORTF_BASE, GPIO_PIN_1 | GPIO_PIN_2 | GPIO_PIN_3);
     GPIOPinTypePWM(GPIO_PORTE_BASE, GPIO_PIN_5); //makes pin to PWM
    
	//Configure PWM Options
    //PWM_GEN_2 Covers M1PWM4 and M1PWM5
    //PWM_GEN_3 Covers M1PWM6 and M1PWM7 See page 207 4/11/13 DriverLib doc
   // PWMGenConfigure(PWM1_BASE, PWM_GEN_2, PWM_GEN_MODE_DOWN | PWM_GEN_MODE_NO_SYNC); 
    PWMGenConfigure(PWM0_BASE, PWM_GEN_2, PWM_GEN_MODE_DOWN | PWM_GEN_MODE_NO_SYNC); 

    //this Sets the Period (expressed in clock ticks)
    PWMGenPeriodSet(PWM0_BASE, PWM_GEN_2, 200);
    //PWMGenPeriodSet(PWM1_BASE, PWM_GEN_5, 200);

    // this is setting the PWM duty-50% (Period /2)
    //PWMPulseWidthSet(PWM1_BASE, PWM_OUT_0,100);
		PWMPulseWidthSet(PWM0_BASE, PWM_OUT_5,100);																									

    // Enable the PWM generator
    PWMGenEnable(PWM0_BASE, PWM_GEN_2);

    // Turn on the Output pins
    PWMOutputState(PWM0_BASE, PWM_OUT_5_BIT, true);
    


    }