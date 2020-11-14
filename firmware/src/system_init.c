/*
--|----------------------------------------------------------------------------|
--| FILE DESCRIPTION:
--|   system_init.c provides the implementation for system initialization.
--|
--|   The SystemInit function is called from the assembly startup routine prior
--|   to branching to the main application function.
--|
--|   In the SystemInit function the various system clock and harware peripheral
--|   init functions are called to initialize the system.
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

#include "ADC1.h"
#include "ADC2.h"
#include "DAC1.h"
#include "DMA.h"
#include "GPIO.h"
#include "interrupts.h"
#include "RCC.h"
#include "stm32f3xx.h"
#include "TIM3.h"
#include "TIM6.h"

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
--| PUBLIC FUNCTION DEFINITIONS
--|----------------------------------------------------------------------------|
*/

void SystemInit(void)
{
    __disable_irq();

    RCC_Init();
    GPIO_Init();
    ADC1_Init();
    ADC2_Init();
    DAC1_Init();
    DMA_Init();
    TIM3_Init();
    TIM6_Init();
    interrupts_Init();

    __enable_irq();
}
