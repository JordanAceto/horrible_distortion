/*
--|----------------------------------------------------------------------------|
--| FILE DESCRIPTION:
--|   system_stm32f3xx.c provides the implementation for system initialization.
--|   
--|   The clock is setup to use the external 8MHz oscillator which is multiplied
--|   by the PLL to 72MHz. The APB1 bus is divided to 36MHz. Two FLASH wait
--|   states are enabled, for speeds greater than 48MHz. 
--|
--|   The SysTick timer is set up to count in milliseconds.
--|
--|    The GREEN and RED LEDs on PA8 and PA9 are set to outputs, and written
--|    low to start.
--|
--|----------------------------------------------------------------------------|
--| REFERENCES:
--|   None
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
--| PRIVATE DEFINES
--|----------------------------------------------------------------------------|
*/

/*
--| NAME: HSE_VALUE
--| DESCRIPTION: Default value of the External oscillator in Hz
--| TYPE: uint32_t
*/
#define HSE_VALUE ((uint32_t)8E6)

/*
--| NAME: HSE_VALUE
--| DESCRIPTION: Default value of the Internal RC oscillator in Hz
--| TYPE: uint32_t
*/
#define HSI_VALUE ((uint32_t)8E6)

/*
--|----------------------------------------------------------------------------|
--| PRIVATE TYPES
--|----------------------------------------------------------------------------|
*/

/* None */

/*
--|----------------------------------------------------------------------------|
--| PRIVATE CONSTANTS
--|----------------------------------------------------------------------------|
*/

/* None */

/*
--|----------------------------------------------------------------------------|
--| PRIVATE VARIABLES
--|----------------------------------------------------------------------------|
*/

/* None */

/*
--|----------------------------------------------------------------------------|
--| PUBLIC VARIABLES
--|----------------------------------------------------------------------------|
*/

/*
--| NAME: SystemCoreClock
--| DESCRIPTION: System Core Clock frequency in Hz
--| TYPE: uint32_t
*/
uint32_t SystemCoreClock = 72E6;

/*
--|----------------------------------------------------------------------------|
--| PRIVATE HELPER FUNCTION PROTOTYPES
--|----------------------------------------------------------------------------|
*/

/*------------------------------------------------------------------------------
Function Name:
    RCC_Init

Function Description:
    Perform initialization of the Reset and Clock Control registers.

Parameters:
    None

Returns:
    None

Assumptions/Limitations:
    Assumed that this will be called before branching to the main application.
------------------------------------------------------------------------------*/
void RCC_Init(void);

/*------------------------------------------------------------------------------
Function Name:
    SysTick_Init

Function Description:
    Perform initialization of the SysTick timer such that the SysTick counts
    in milliseconds.

Parameters:
    None

Returns:
    None

Assumptions/Limitations:
    Assumed that this will be called before branching to the main application.
------------------------------------------------------------------------------*/
void SysTick_Init(void);

/*------------------------------------------------------------------------------
Function Name:
    GPIO_Init

Function Description:
    Perform initialization of the GPIO pins

Parameters:
    None

Returns:
    None

Assumptions/Limitations:
    Assumed that this will be called before branching to the main application.
------------------------------------------------------------------------------*/
void GPIO_Init(void);

/*
--|----------------------------------------------------------------------------|
--| PUBLIC FUNCTION DEFINITIONS
--|----------------------------------------------------------------------------|
*/

void SystemInit(void)
{
    // set two flash wait states for 48MHz < SYSCLK <= 72MHz
    FLASH->ACR |= FLASH_ACR_LATENCY_2;

    RCC_Init();
    SysTick_Init();
    GPIO_Init();
}

/*
--|----------------------------------------------------------------------------|
--| PRIVATE HELPER FUNCTION DEFINITIONS
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

    // select the PLL as the system clock
    RCC->CFGR |= RCC_CFGR_SW_PLL;

    while (!(RCC->CFGR & RCC_CFGR_SWS_PLL))
    {
        // wait for the PLL to be ready
    }
}

void SysTick_Init(void)
{
    // set the load register such that the systick timer rolls over every 1mSec
    SysTick->LOAD = (SystemCoreClock / 1000u) - 1u; 
    
    // clear the current value
    SysTick->VAL = 0u;
    
    // set the clocksource to undivided processor clock (AHB)
    SysTick->CTRL |= SysTick_CTRL_CLKSOURCE_Msk;

    // enable exception requests so that the SysTick_Handler will be called at 1kHz
    SysTick->CTRL |= SysTick_CTRL_TICKINT_Msk;

    // enable the SysTick timer
    SysTick->CTRL |= SysTick_CTRL_ENABLE_Msk;
}

void GPIO_Init(void)
{
    // enable GPIO port A
    RCC->AHBENR |= RCC_AHBENR_GPIOAEN;

    // set the GREEN LED on port A pin 8 to output
    GPIOA->MODER |= GPIO_MODER_MODER8_0;

    // set RED LED on port A pin 9 to output
    GPIOA->MODER |= GPIO_MODER_MODER9_0;

    // turn the LEDs off
    GPIOA->BRR |= GPIO_BRR_BR_8 | GPIO_BRR_BR_9;
}
