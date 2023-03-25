#ifndef __TIMER_H__
#define __TIMER_H__

#include "../Main/main.h"

#define TMR_TICK_MS				(10)   // HCF(P1, P2, ..., PN)

void TMR_Init(void);
void TMR_Start(void);
void TMR_Stop(void);
void SysTick_Handler(void);
void TIM2_Init();

#endif // __TIMER_H__
