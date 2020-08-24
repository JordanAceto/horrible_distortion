/*
--|----------------------------------------------------------------------------|
--| FILE DESCRIPTION:
--|   LED_indicator.c provides the implementation for using the RED/GREEN LED
--|   signal indicator.
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

#include "global_data.h"
#include "stm32f3xx.h"

/*
--|----------------------------------------------------------------------------|
--| PRIVATE DEFINES
--|----------------------------------------------------------------------------|
*/

// signal level boundaries were derived empirically, adjust to taste

/*
--| NAME: HEALTHY_SIGNAL_LOW_BOUND
--| DESCRIPTION: the lower bound for signals in the healthy range
--| TYPE: uint
*/
#define HEALTHY_SIGNAL_LOW_BOUND (0x8FFu)

/*
--| NAME: HEALTHY_SIGNAL_HIGH_BOUND
--| DESCRIPTION: the upper bound for signals in the healthy range
--| TYPE: uint
*/
#define HEALTHY_SIGNAL_HIGH_BOUND (0xD54u)

/*
--| NAME: DANGER_ZONE_LOW_BOUND
--| DESCRIPTION: the lower bound for signals in the danger zone
--| TYPE: uint
*/
#define DANGER_ZONE_LOW_BOUND (0xF10u)

/*
--|----------------------------------------------------------------------------|
--| PRIVATE VARIABLES
--|----------------------------------------------------------------------------|
*/

/*
--| NAME: peak
--| DESCRIPTION: peak follower for the audio input signal
--| TYPE: uint16_t
*/
static uint16_t peak;

/*
--|----------------------------------------------------------------------------|
--| PUBLIC FUNCTION DEFINITIONS
--|----------------------------------------------------------------------------|
*/

void LED_indicator_show_signal_strength(void)
{
    // update the peak signal to follow the audio input signal
    if (peak <= ADC2->DR)
    {
        peak = ADC2->DR;
    }

    if (peak < HEALTHY_SIGNAL_LOW_BOUND)
    {
        // signal level is very low, both LEDs off
        GPIOA->BSRR = (GPIO_BSRR_BR_8 | GPIO_BSRR_BR_9); 
    }
    else if (peak < HEALTHY_SIGNAL_HIGH_BOUND)
    {
        // signal level is healthy, green LED on, red LED off
        GPIOA->BSRR = (GPIO_BSRR_BS_8 | GPIO_BSRR_BR_9);
    }
    else if (peak < DANGER_ZONE_LOW_BOUND)
    {
        // signal level is approaching clipping, both LEDs on for orange-ish color
        GPIOA->BSRR = (GPIO_BSRR_BS_8 | GPIO_BSRR_BS_9);
    }
    else
    {
        // signal level is clipping, green LED off, red LED on
        GPIOA->BSRR = (GPIO_BSRR_BR_8 | GPIO_BSRR_BS_9);
    }

    // allow the peak to decay
    peak--;
}