/*
--|----------------------------------------------------------------------------|
--| FILE DESCRIPTION:
--|   RCC.c provides the implementation for initializing RCC.
--|  
--|----------------------------------------------------------------------------|
--| REFERENCES:
--|   STM32F334xx Reference Manual, page 104
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

void RCC_Init(void)
{
    // enable the external high speed clock
    RCC->CR |= RCC_CR_HSEON;

    while (!(RCC->CR & RCC_CR_HSERDY))
    {
        // wait for the external clock to be ready
    }

    // set the PLL multiplier to multiply the input clock by 9
    RCC->CFGR |= RCC_CFGR_PLLMUL_0 | RCC_CFGR_PLLMUL_1 | RCC_CFGR_PLLMUL_2;

    // set the PLL clock source to HSE
    RCC->CFGR |= RCC_CFGR_PLLSRC;

    // turn on the PLL
    RCC->CR |= RCC_CR_PLLON;

    while (!(RCC->CR & RCC_CR_PLLRDY))
    {
        // wait for the PLL to lock
    }

    // set the clock dividers
    RCC->CFGR |= RCC_CFGR_HPRE_DIV1;  // AHB set to 72MHz

    RCC->CFGR |= RCC_CFGR_PPRE1_DIV2; // APB1 set to 36MHz

    RCC->CFGR |= RCC_CFGR_PPRE2_DIV1; // APB2 set to 72MHz

    // set two flash wait states for 48MHz < SYSCLK <= 72MHz
    FLASH->ACR |= FLASH_ACR_LATENCY_2;

    // select the PLL as the system clock
    RCC->CFGR |= RCC_CFGR_SW_PLL;

    while (!(RCC->CFGR & RCC_CFGR_SWS_PLL))
    {
        // wait for the PLL to be ready
    }
}
