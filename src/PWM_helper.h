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
#include "pwm.h"
#include "gpio.h"
#include "pin_map.h"

void SetUpPWM0HZ(void);
void SetUpPWM200HZ(void);
void SetUpPWM300HZ(void);
void SetUpPWM400HZ(void);
void SetUpPWM500HZ(void);
void SetUpPWM600HZ(void);
void SetUpPWM700HZ(void);
void SetUpPWM800HZ(void);
void SetUpPWM900HZ(void);
void SetupPWM(void);
