/*
--|----------------------------------------------------------------------------|
--| FILE DESCRIPTION:
--|   ADC2.c provides the implementation for initializing ADC2.
--|   
--|   ADC2 channel 2 reads the audio input signal on pin PA5.
--|  
--|----------------------------------------------------------------------------|
--| REFERENCES:
--|   STM32F334xx Reference Manual, page 104 (RCC)
--|   STM32F334xx Reference Manual, page 211 (ADC)
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

void ADC2_Init(void)
{
    // enable ADC 1 and 2 (you can only enable them both at once)
    RCC->AHBENR |= RCC_AHBENR_ADC12EN;

    // use PLL clock divided by 2
    RCC->CFGR2 |= RCC_CFGR2_ADCPRE12_4 | RCC_CFGR2_ADCPRE12_0;

    // enable GPIO port A
    RCC->AHBENR |= RCC_AHBENR_GPIOAEN;

    // first and only conversion is channel 2, the audio input
    ADC2->SQR1 |= ADC_SQR1_SQ1_1;

    // external trigger on rising edge
    ADC2->CFGR |= ADC_CFGR_EXTEN_0;

    // set external trigger source to TIM6 TRGO
    ADC2->CFGR |= ADC_CFGR_EXTSEL_0 | ADC_CFGR_EXTSEL_2 | ADC_CFGR_EXTSEL_3;

    // enable discontinuous mode
    ADC2->CFGR |= ADC_CFGR_DISCEN;

    // allow overwritting with the last conversion on an overrun
    ADC2->CFGR |= ADC_CFGR_OVRMOD;

    // 19.5 ADC clock cycles per acquisition
    ADC2->SMPR1 |= ADC_SMPR1_SMP1_2;

    // set calibration to single ended
    ADC2->CR &= ~ADC_CR_ADCALDIF;

    // start the calibration
    ADC2->CR |= ADC_CR_ADCAL;

    while (ADC2->CR & ADC_CR_ADCAL)
    {
        // wait for the calibration to complete
    }

    // enable ADC2
    ADC2->CR |= ADC_CR_ADEN;

    while (!(ADC2->ISR & ADC_ISR_ADRDY))
    {
        // wait until the ADC is ready
    }

    // start the ADC
    ADC2->CR |= ADC_CR_ADSTART;
}

/*
--|----------------------------------------------------------------------------|
--| PRIVATE HELPER FUNCTION DEFINITIONS
--|----------------------------------------------------------------------------|
*/

/* None */
