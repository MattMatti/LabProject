#include <stdlib.h>
#include <stdint.h>
#include "tm4c123gh6pm.h"
#include "systick.h"
#include <stdbool.h>

struct SysTickTimer
{
	uint32_t mSTimer;
	uint64_t uSTimer;
};

void SysTick_Setup(void);
void SysTickWait(unsigned long);
void SysTickWait10ms(unsigned long);
