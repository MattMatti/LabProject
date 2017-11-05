#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include "sysctl.h"
#include "hw_memmap.h"
#include "gpio.h"
#include "uart.h"
#include "../inc/tm4c123gh6pm.h"
#include "pin_map.h"


void UART_setup(void);		//sets up Uart for my configuration using library

void PutInUartVariable(void); 

//redirect for printf.
int fputc(int ch, FILE *f);

//redirect input from serial port

int fgetc(FILE *f);

