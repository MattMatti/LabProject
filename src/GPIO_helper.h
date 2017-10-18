#include <stdbool.h>
#include <stdint.h>
//#include "sysctl.h"
#include "hw_memmap.h"
#include "adc.h"
#include "uart.h"
#include "tm4c123gh6pm.h"
#include "hw_gpio.h"
#include "hw_types.h"
#include "gpio.h"

//#include "project.h"

void UpdateMYButtons(void);
//1 = pushed down
//0 = not pushed

 struct MyButtons
{
	uint8_t SW1;
 	uint8_t SW2;
	
};

  extern struct MyButtons MyButtons;
  void GPIOSetup(void);
  void TurnOnLEDs(void);
  void TurnOnLEDs2(void);