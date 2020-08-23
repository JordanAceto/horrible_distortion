/*
--|----------------------------------------------------------------------------|
--| FILE DESCRIPTION:
--|   GPIO.c provides the implementation for initializing the GPIO pins.
--|   
--|   
--|  
--|----------------------------------------------------------------------------|
--| REFERENCES:
--|   STM32F334xx Reference Manual, page 104 (RCC)
--|   STM32F334xx Reference Manual, page 139 (GPIO)
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

void GPIO_Init(void)
{
    // enable GPIO port A
    RCC->AHBENR |= RCC_AHBENR_GPIOAEN;

    // set PA0 to analog mode, PA0 is connected to the resolution_CV_in node
    GPIOA->MODER |= GPIO_MODER_MODER0_0 | GPIO_MODER_MODER0_1;

    // set PA1 to analog mode, PA1 is connected to the sample_rate_CV_in node
    GPIOA->MODER |= GPIO_MODER_MODER1_0 | GPIO_MODER_MODER1_1;

    // set PA4 to analog mode, PA4 is connected to the DAC audio input signal
    GPIOA->MODER |= GPIO_MODER_MODER4_0 | GPIO_MODER_MODER4_1;

    // set PA5 to analog mode, PA5 is connected to the audio input signal
    GPIOA->MODER |= GPIO_MODER_MODER5_0 | GPIO_MODER_MODER5_1;

    // set PA8 to digital output, PA8 is connected to the GREEN LED
    GPIOA->MODER |= GPIO_MODER_MODER8_0;

    // set PA9 to digital output, PA9 is connected to the RED LED
    GPIOA->MODER |= GPIO_MODER_MODER9_0;

    // turn the LEDs off
    GPIOA->BRR |= GPIO_BRR_BR_8 | GPIO_BRR_BR_9;
}

/*
--|----------------------------------------------------------------------------|
--| PRIVATE HELPER FUNCTION DEFINITIONS
--|----------------------------------------------------------------------------|
*/

/* None */
