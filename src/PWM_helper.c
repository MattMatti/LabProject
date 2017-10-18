#include "PWM_helper.h"

// this code initializes the pins as pwm and sets the clock cycle to 16 MHZ. It also makes a 50% duty cycle. It then enables the PWM generator 2 and 3.
// I didn't have the chance to try and implement it into the main code.
void delayMS(int ms) 
	{
    SysCtlDelay( (SysCtlClockGet()/(3*1000))*ms );
}

 void SetUpPWM200HZ()
{
	unsigned long ulPeriod;
    //Set the clock
   SysCtlClockSet(SYSCTL_SYSDIV_1 | SYSCTL_USE_OSC |	SYSCTL_OSC_MAIN | SYSCTL_XTAL_16MHZ);

   //Configure PWM Clock to match system
   SysCtlPWMClockSet(SYSCTL_PWMDIV_1);

   // Enable the peripherals used by this program.
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOE);
    SysCtlPeripheralEnable(SYSCTL_PERIPH_PWM0);  //The Tiva Launchpad has two modules (0 and 1). 
    ulPeriod = SysCtlClockGet() / 200; //PWM frequency 200HZ

    //Configure PF1,PF2,PF3 Pins as PWM
    GPIOPinConfigure(GPIO_PE5_M0PWM5); // pin1 port F is pwm5 of module 1 
    //GPIOPinConfigure(GPIO_PF2_M1PWM6);
    //GPIOPinConfigure(GPIO_PF3_M1PWM7);
    //GPIOPinTypePWM(GPIO_PORTF_BASE, GPIO_PIN_1 | GPIO_PIN_2 | GPIO_PIN_3);
     GPIOPinTypePWM(GPIO_PORTE_BASE, GPIO_PIN_1);
    
	//Configure PWM Options
    //PWM_GEN_2 Covers M1PWM4 and M1PWM5
    //PWM_GEN_3 Covers M1PWM6 and M1PWM7 See page 207 4/11/13 DriverLib doc
    PWMGenConfigure(PWM1_BASE, PWM_GEN_2, PWM_GEN_MODE_DOWN | PWM_GEN_MODE_NO_SYNC); 
    PWMGenConfigure(PWM1_BASE, PWM_GEN_3, PWM_GEN_MODE_DOWN | PWM_GEN_MODE_NO_SYNC); 

    //this Sets the Period (expressed in clock ticks)
    PWMGenPeriodSet(PWM1_BASE, PWM_GEN_2, ulPeriod);
    PWMGenPeriodSet(PWM1_BASE, PWM_GEN_3, ulPeriod);

    // this is setting the PWM duty-50% (Period /2)
    PWMPulseWidthSet(PWM1_BASE, PWM_OUT_5,ulPeriod);
																											//PWMPulseWidthSet(PWM1_BASE, PWM_OUT_6,100);
																											//PWMPulseWidthSet(PWM1_BASE, PWM_OUT_7,100);

    // Enable the PWM generator
    PWMGenEnable(PWM1_BASE, PWM_GEN_2);
    PWMGenEnable(PWM1_BASE, PWM_GEN_3);

    // Turn on the Output pins
    PWMOutputState(PWM1_BASE, PWM_OUT_5_BIT, true);
    
		//PWMOutputState(PWM1_BASE, PWM_OUT_5_BIT | PWM_OUT_6_BIT | PWM_OUT_7_BIT, true);

    //Fade
//    bool fadeUp = true;
//    unsigned long increment = 10;
//    unsigned long pwmNow = 100;
//    while(1)
//    {
//        delayMS(20);
//        if (fadeUp) {
//            pwmNow += increment;
//            if (pwmNow >= 320) { fadeUp = false; }
//        }
//        else {
//            pwmNow -= increment;
//            if (pwmNow <= 10) { fadeUp = true; }
//        }
//        PWMPulseWidthSet(PWM1_BASE, PWM_OUT_5,pwmNow);
        //PWMPulseWidthSet(PWM1_BASE, PWM_OUT_6,pwmNow);
        //PWMPulseWidthSet(PWM1_BASE, PWM_OUT_7,pwmNow);
    }