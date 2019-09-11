#pragma once
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
#include "PWM_helper.h"


extern uint32_t DutyValue;
extern uint32_t FSR1I2C;
void SetupADCPins(void);
void SetupADC(void);
void ADCReadString1(void);  
void ADCReadString2(void);  
void ADCReadString3(void);  
void ADCReadString4(void);  
void ReadDutyKnob(void);
void ReadFSR1(void);
void read_adc(void);
