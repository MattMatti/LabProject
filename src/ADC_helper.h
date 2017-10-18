#include <stdbool.h>
#include <stdint.h>
#include "sysctl.h"
#include "hw_memmap.h"
#include "adc.h"
#include "uart.h"
#include "tm4c123gh6pm.h"
#include "hw_gpio.h"
#include "hw_types.h"
#include "gpio.h"

extern uint32_t ADC_Values[2];

extern uint32_t string1;
	
//struct ADC_Strings_FSRs
//{
//	uint32_t String1;
//	uint32_t String2;
//	uint32_t String3;
//	uint32_t String4;
//	uint32_t FSR1;
//	uint32_t FSR2;
//	uint32_t FSR3;
//	uint32_t FSR4;
//};
	

void SetupADCPins(void);
void SetupADC(void);
void ADCReadChan(void);  

//extern struct ADC_Strings_FSRs StringAndFSR_values;