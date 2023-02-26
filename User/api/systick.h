#ifndef _SYSTICK_H
#define _SYSTICK_H

#include "stm32f4xx.h"
#include "core_cm4.h"
#include "misc.h"

void SysTick_Delay(uint32_t ms);
void SysTick_Init(void);
void TimingDelay_Decrement(void);


#endif
