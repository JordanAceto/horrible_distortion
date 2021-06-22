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
#define HEALTHY_SIGNAL_LOW_BOUND (0x8FF0u)

/*
--| NAME: HEALTHY_SIGNAL_HIGH_BOUND
--| DESCRIPTION: the upper bound for signals in the healthy range
--| TYPE: uint
*/
#define HEALTHY_SIGNAL_HIGH_BOUND (0xD540u)

/*
--| NAME: DANGER_ZONE_LOW_BOUND
--| DESCRIPTION: the lower bound for signals in the danger zone
--| TYPE: uint
*/
#define DANGER_ZONE_LOW_BOUND (0xF100u)

/*
--|----------------------------------------------------------------------------|
--| PRIVATE TYPES
--|----------------------------------------------------------------------------|
*/

/*
--| NAME: LED_Color_t
--| DESCRIPTION: Enumeration of the colors that that bi-color indicator light can take
*/
typedef enum LED_Color_Type
{
    LED_COLOR_OFF    = (GPIO_BSRR_BR_8 | GPIO_BSRR_BR_9),
    LED_COLOR_GREEN  = (GPIO_BSRR_BS_8 | GPIO_BSRR_BR_9),
    LED_COLOR_ORANGE = (GPIO_BSRR_BS_8 | GPIO_BSRR_BS_9),
    LED_COLOR_RED    = (GPIO_BSRR_BR_8 | GPIO_BSRR_BS_9)
} LED_Color_t;

/*
--|----------------------------------------------------------------------------|
--| PRIVATE VARIABLES
--|----------------------------------------------------------------------------|
*/

/*
--| NAME: peak
--| DESCRIPTION: peak follower for the audio input signal
--| TYPE: int
*/
static int peak;

/*
--|----------------------------------------------------------------------------|
--| PRIVATE HELPER FUNCTION PROTOTYPES
--|----------------------------------------------------------------------------|
*/

/*------------------------------------------------------------------------------
Function Name:
    LED_indicator_set_color

Function Description:
    Set the color of the bi-color indicator LED.

Parameters:
    color (LED_Color_t): the color to use.

Returns:
    None

Assumptions/Limitations:
    Assumed that GPIO initialization is complete and that color is a valid
    LED_Color_t enumeration.
------------------------------------------------------------------------------*/
void LED_indicator_set_color(LED_Color_t color);

/*
--|----------------------------------------------------------------------------|
--| PUBLIC FUNCTION DEFINITIONS
--|----------------------------------------------------------------------------|
*/

void LED_indicator_show_signal_strength(uint16_t val)
{
    // update the peak signal to follow the audio input signal
    if (peak < val)
    {
        peak = val;
    }

    if (peak < HEALTHY_SIGNAL_LOW_BOUND)
    {
        LED_indicator_set_color(LED_COLOR_OFF);
    }
    else if (peak < HEALTHY_SIGNAL_HIGH_BOUND)
    {
        LED_indicator_set_color(LED_COLOR_GREEN);
    }
    else if (peak < DANGER_ZONE_LOW_BOUND)
    {
        LED_indicator_set_color(LED_COLOR_ORANGE);
    }
    else // the signal is in the danger zone
    {
        LED_indicator_set_color(LED_COLOR_RED);
    }

    // allow the peak to decay and clamp at zero
    peak--;

    if (peak < 0)
    {
        peak = 0;
    }
}

/*
--|----------------------------------------------------------------------------|
--| PRIVATE HELPER FUNCTION DEFINITIONS
--|----------------------------------------------------------------------------|
*/

void LED_indicator_set_color(LED_Color_t color)
{
    GPIOA->BSRR = color;
}
