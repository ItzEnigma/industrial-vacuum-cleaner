#include "../Main/main.h"
#include "../Modules/Timer.h"
#include "../Modules/SW.h"
#include "../Modules/Motor.h"
#include "../Modules/Display.h"
#include "../Modules/Led.h"
#include "stm32f4xx_ll_tim.h"

// For debugging only (For logic analyzer)
volatile uint32_t tick = 0;
volatile uint32_t firing_tick = 0;

void TMR_Init(void)
{
   // System clock frequency = 16MHz
   // Tick Period = 1ms
   SysTick_Config(12*TMR_TICK_MS*1000);
}

/* Not working on simulation */
void TIM2_Init(){  
  
   // RCC->APB1ENR |= (1<<0); /* Enable TIM2 CLK */
		
		RCC->APB1LPENR |=(1<<0);
	
		//RCC->APB2ENR |= (1<<16);		/* TIM2 */
	
		TIM2->CR1 &= (1<<8);		/* Clock Division = 0 */
		TIM2->CR1 &= (1<<4);		/* DIR = upcounter */
		TIM2->CR1 |= (1<<0);            /* Enable TIM2 */
    TIM2->CR1 |= (1<<7);
	
		TIM2->PSC = 16 - 1;     /* Divide by 16000 */
		TIM2->ARR = 0x0FFFFF - 1;     /* Timer will reset after 10000 counts */
	
		TIM2->CR1 |= (1<<3);
	
	
    //TIM2->SMCR |= (1 << 14);
    
    //RCC->AHB1ENR |= 0x00000008;
    //GPIOD->MODER &= ~0x55000000;
    //GPIOD->MODER |= 0x55000000;
    //
    //
    //RCC->APB1ENR |= (1<<0); /* Enable TIM2 CLK */
  //  TIM2->PSC = 8399;               // Prescaler value, 8400 - 1, 84 MhZ / 8400 = 10000 Hz
  //  TIM2->EGR = TIM_EGR_UG;         // Update prescaler
  //  TIM2->ARR = 9999;               // Period, 10000-1, 1 second period
  //  TIM2->DIER = TIM_DIER_UIE;      // Enable interrupts for this timer
  //  TIM2->CR1 = TIM_CR1_CEN;        // Enable this timer
    NVIC_EnableIRQ(TIM2_IRQn);
    
    //TIM2->DIER = (1<<0);    /* Enable Timer interrupt */
    //NVIC->IP[TIM2_IRQn] =  (2 << 4);     /* Set priority to 2 */
  //NVIC->ISER[TIM2_IRQn >> 5] |= (1 << (TIM2_IRQn % 32)); /* Enable interrupt */
    //TIM2->SR &= ~(1<<0);        /* Clear interrupt flag*/
  //TIM2->EGR |= (1<<0);        
}
void TIM2_Start()
{
	TIM2->CR1 |= (1<<0);            /* Enable TIM2 */
}

void TMR_Start(void)
{
   SysTick->CTRL |= (0x03);
}

void TMR_Stop(void)
{
   SysTick->CTRL &= ~(0x03);
}

void SysTick_Handler(void)
{
   // For debugging only (For logic analyzer)
   tick ^= 1;
	 //TIM2_Start();
	 SW_Update();
	 VC_Update();
   Motor_Update();
   // Do nothing
   // It is made only to wake the cpu up
}

