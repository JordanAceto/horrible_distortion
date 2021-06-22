/*
--|----------------------------------------------------------------------------|
--| FILE DESCRIPTION:
--|   DAC1.c provides the implementation for initializing DAC1.
--|   
--|   DAC1 outputs the procesed audio signal on channel 1.
--|  
--|----------------------------------------------------------------------------|
--| REFERENCES:
--|   STM32F334xx Reference Manual, page 104 (RCC)
--|   STM32F334xx Reference Manual, page 317 (DAC)
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

void DAC1_Init(void)
{
    // enable DAC1 clock control
    RCC->APB1ENR |= RCC_APB1ENR_DAC1EN;

    // enable triggers for DAC1
    DAC1->CR |= DAC_CR_TEN1;

    // set DAC1 to use software triggers
    DAC1->CR |= DAC_CR_TSEL1_0 | DAC_CR_TSEL1_1 | DAC_CR_TSEL1_2;

    // enable DAC1
    DAC1->CR |= DAC_CR_EN1;
}

void DAC1_write_ui12(uint16_t val)
{
    DAC1->DHR12R1 = val;
    DAC1->SWTRIGR |= DAC_SWTRIGR_SWTRIG1;
}