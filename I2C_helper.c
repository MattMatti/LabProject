#include "I2C_helper.h"

void I2C_Setup(void)
{
	SysCtlPeripheralEnable(SYSCTL_PERIPH_I2C0); // Enables I2C Module 0 

	SysCtlPeripheralReset(SYSCTL_PERIPH_I2C0); // resets module 0
	SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOB); // enables port B

	GPIOPinConfigure(GPIO_PB2_I2C0SCL); //configures port B pin2 to module clock
	GPIOPinConfigure(GPIO_PB3_I2C0SDA); // configures port B pin 3 to module data
	
	GPIOPinTypeI2CSCL(GPIO_PORTB_BASE, GPIO_PIN_2); //Sets pin type as I2C clock
	GPIOPinTypeI2C(GPIO_PORTB_BASE, GPIO_PIN_3); //Sets Pin Type as I2C as Data

	I2CMasterInitExpClk(I2C0_BASE, SysCtlClockGet(), false); //data rate is set to 100 kbps	
}


