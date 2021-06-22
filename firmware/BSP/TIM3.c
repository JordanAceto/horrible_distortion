/*
--|----------------------------------------------------------------------------|
--| FILE DESCRIPTION:
--|   TIM3.c provides the implementation for initializing TIM3.
--|   
--|   TIM3 sets the sample time for reading the analog control signals for
--|   bit-resolution and audio-sample-rate.
--|
--|
--|----------------------------------------------------------------------------|
--| REFERENCES:
--|   STM32F334xx Reference Manual, page 478 (General Purpose Timers)
--|
--|----------------------------------------------------------------------------|
*/

/*
--|----------------------------------------------------------------------------|
--| INCLUDE FILES
--|----------------------------------------------------------------------------|
*/

#include "stm32f3xx.h"

/*
--|----------------------------------------------------------------------------|
--| PUBLIC FUNCTION DEFINITIONS
--|----------------------------------------------------------------------------|
*/

void TIM3_Init(void)
{
    // enable clock control for timer 3
    RCC->APB1ENR |= RCC_APB1ENR_TIM3EN;

    // set master mode selection to update TRGO
    TIM3->CR2 |= TIM_CR2_MMS_1;

    // control signal sample rate = 1kHz
    TIM3->PSC = 36u - 1u;
    TIM3->ARR = 1000u - 1u;

    // enable TIM3 Update Interrupts
    TIM3->DIER |= TIM_DIER_UIE;

    // enable the timer
    TIM3->CR1 |= TIM_CR1_CEN;
}
