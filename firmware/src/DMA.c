/*
--|----------------------------------------------------------------------------|
--| FILE DESCRIPTION:
--|   DMA.c provides the implementation for initializing the Direct Memory
--|   Access controller.
--|
--|   DMA is used to transfer the control reading signals from the ADC to the
--|   global storage variable control_reading[]. This allows the ADC to work
--|   completely in the background, we can access the control readings at any
--|   time via the symbol control_reading[index_of_desired_control_signal].
--|
--|----------------------------------------------------------------------------|
--| REFERENCES:
--|   STM32F334xx Reference Manual, page 170
--|
--|----------------------------------------------------------------------------|
*/

/*
--|----------------------------------------------------------------------------|
--| INCLUDE FILES
--|----------------------------------------------------------------------------|
*/

#include "global_data.h"
#include "stm32f3xx.h"

/*
--|----------------------------------------------------------------------------|
--| PRIVATE DEFINES
--|----------------------------------------------------------------------------|
*/

/* None */

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

/* None */

/*
--|----------------------------------------------------------------------------|
--| PRIVATE HELPER FUNCTION PROTOTYPES
--|----------------------------------------------------------------------------|
*/

/* None */

/*
--|----------------------------------------------------------------------------|
--| PUBLIC FUNCTION DEFINITIONS
--|----------------------------------------------------------------------------|
*/

void DMA_Init(void)
{
    // enable DMA clock access
    RCC->AHBENR |= RCC_AHBENR_DMA1EN;

    // do DMA init stuff here

    // set circular mode
    DMA1_Channel1->CCR |= DMA_CCR_CIRC;

    // data size = 32 bits
    DMA1_Channel1->CCR |= DMA_CCR_MSIZE_1;

    // peripheral size = 32 bits
    DMA1_Channel1->CCR |= DMA_CCR_PSIZE_1;

    // set DMA to increment the memory address
    DMA1_Channel1->CCR |= DMA_CCR_MINC;

    // DMA transfer length = 2
    DMA1_Channel1->CNDTR = NUM_CONTROL_INPUTS;

    // set peripheral address to ADC1 Data Register
    DMA1_Channel1->CPAR = (uint32_t)&(ADC1->DR);

    // set memory address to the global signal (note that control_reading is an array)
    DMA1_Channel1->CMAR = (uint32_t)control_reading;

    // enable DMA1 channel 1
    DMA1_Channel1->CCR |= DMA_CCR_EN;
}

/*
--|----------------------------------------------------------------------------|
--| PRIVATE HELPER FUNCTION DEFINITIONS
--|----------------------------------------------------------------------------|
*/

/* None */
