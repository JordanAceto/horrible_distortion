/*
--|----------------------------------------------------------------------------|
--| FILE DESCRIPTION:
--|   ADC1.c provides the implementation for initializing ADC1.
--|   
--|   ADC1 reads the control signals for bit-depth and sample rate.
--|   The bit-depth control signal is read with ADC1 channel 1, on pin PA0.
--|   The sample-rate control signal is read with ADC1 channel 2, on pin PA1.
--|
--|   The control signals are both delivered to the global storage signal
--|   control_reading[] via DMA.
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

void ADC1_Init(void)
{
    // enable ADC 1 and 2 (you can only enable them both at once)
    RCC->AHBENR |= RCC_AHBENR_ADC12EN;

    // PLL clock divided by 2
    RCC->CFGR2 |= RCC_CFGR2_ADCPRE12_4 | RCC_CFGR2_ADCPRE12_0;

    // enable GPIO port A
    RCC->AHBENR |= RCC_AHBENR_GPIOAEN;

    // first conversion is channel 1, the resolution CV parameter
    ADC1->SQR1 |= ADC_SQR1_SQ1_0;

    // second conversion is channel 2, the sample-rate CV parameter
    ADC1->SQR1 |= ADC_SQR1_SQ2_1;

    // regular channel sequence length = 2
    ADC1->SQR1 |= ADC_SQR1_L_0;

    // 19.5 ADC clock cycles per acquisition for both conversions
    ADC1->SMPR1 |= ADC_SMPR1_SMP1_2 | ADC_SMPR1_SMP2_2;

    // external trigger on rising edge
    ADC1->CFGR |= ADC_CFGR_EXTEN_0;

    // select TIM3 TRGO as trigger source
    ADC1->CFGR |= ADC_CFGR_EXTSEL_2;

    // allow overwritting with the last conversion on an overrun
    ADC1->CFGR |= ADC_CFGR_OVRMOD;

    // enable DMA circular mode
    ADC1->CFGR |= ADC_CFGR_DMACFG;

    // enable DMA access
    ADC1->CFGR |= ADC_CFGR_DMAEN;

    // set calibration to single ended
    ADC1->CR &= ~ADC_CR_ADCALDIF;

    // start the calibration
    ADC1->CR |= ADC_CR_ADCAL;

    while (ADC1->CR & ADC_CR_ADCAL)
    {
        // wait for the calibration to complete
    }

    // enable ADC1
    ADC1->CR |= ADC_CR_ADEN;

    while (!(ADC1->ISR & ADC_ISR_ADRDY))
    {
        // wait until the ADC is ready
    }
    
    // start the ADC
    ADC1->CR |= ADC_CR_ADSTART;
}

/*
--|----------------------------------------------------------------------------|
--| PRIVATE HELPER FUNCTION DEFINITIONS
--|----------------------------------------------------------------------------|
*/

/* None */
