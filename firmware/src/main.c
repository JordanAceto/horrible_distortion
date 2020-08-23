/*
--|----------------------------------------------------------------------------|
--| FILE DESCRIPTION:
--|   main.c provides the main application entry point implementation.
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

#include "main.h"

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
--| PRIVATE HELPER FUNCTION PROTOTYPES
--|----------------------------------------------------------------------------|
*/

/* None */

/*
--|----------------------------------------------------------------------------|
--| PUBLIC FUNCTION DEFINITIONS
--|----------------------------------------------------------------------------|
*/

int main(void)
{

    uint32_t delay_time_mSec = 1000;

    uint32_t bit_resolution_reading;
    uint32_t sample_rate_reading;

    // blink the LED on PA8
    GPIOA->BSRR = GPIO_BSRR_BS_8;

    SysTick_Delay_mSec(delay_time_mSec);

    GPIOA->BSRR = GPIO_BSRR_BR_8;
    
    SysTick_Delay_mSec(delay_time_mSec);

    while(1)
    {

        // start a conversion
        ADC1->CR |= ADC_CR_ADSTART;

        while (!(ADC1->ISR & ADC_ISR_EOC))
        {
            // wait for conversion to complete
        }

        bit_resolution_reading = ADC1->DR;

        // start a conversion
        ADC1->CR |= ADC_CR_ADSTART;

        while (!(ADC1->ISR & ADC_ISR_EOC))
        {
            // wait for conversion to complete
        }

        sample_rate_reading = ADC1->DR;

        while (!(ADC1->ISR & ADC_ISR_EOS))
        {
            // wait for the end of the regular sequence
        }

        // clear the EOS flag
        ADC1->ISR |= ADC_ISR_EOS;

        // turn the green LED on when the bits pot is turned up more than 1/2 way
        if (bit_resolution_reading < 2000)
        {
            GPIOA->BSRR = GPIO_BSRR_BS_8;
        }
        else
        {
            GPIOA->BSRR = GPIO_BSRR_BR_8;
        }

        // turn the red LED on when the sample rate pot is turned up more than 1/2 way
        if (sample_rate_reading < 2000)
        {
            GPIOA->BSRR = GPIO_BSRR_BS_9;
        }
        else
        {
            GPIOA->BSRR = GPIO_BSRR_BR_9;
        }  

        // write the resolution pot to the DAC as a test
        DAC1->DHR12R1 = bit_resolution_reading;

        DAC1->SWTRIGR |= DAC_SWTRIGR_SWTRIG1;

        // short delay
        SysTick_Delay_mSec(10);
    }
}

/*
--|----------------------------------------------------------------------------|
--| PRIVATE HELPER FUNCTION DEFINITIONS
--|----------------------------------------------------------------------------|
*/

/* None */
