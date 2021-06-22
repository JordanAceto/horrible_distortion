/*
--|----------------------------------------------------------------------------|
--| FILE DESCRIPTION:
--|   LED_indicator.h provides the interface for using the RED/GREEN LED
--|   signal indicator.
--|   
--|----------------------------------------------------------------------------|
--| REFERENCES:
--|   None
--|
--|----------------------------------------------------------------------------|
*/

#ifndef LED_INDICATOR_H_INCLUDED
#define LED_INDICATOR_H_INCLUDED

/*
--|----------------------------------------------------------------------------|
--| INCLUDE FILES
--|----------------------------------------------------------------------------|
*/

#include <stdint.h>

/*
--|----------------------------------------------------------------------------|
--| PUBLIC FUNCTION PROTOTYPES
--|----------------------------------------------------------------------------|
*/

/*------------------------------------------------------------------------------
Function Name:
    LED_indicator_show_signal_strength

Function Description:
    Show the signal strength of the input signal with the RED/GREEN LED.

    Weak signals will cause both LEDs to turn off.

    Healthy level signals will cause the GREEN LED to turn on.

    Signals approaching clipping but still safe will cause both LEDs to turn on.

    Signals that cause clipping will cause the RED LED to turn on.

Parameters:
    val (uint16_t): the signal value to monitor.

Returns:
    None

Assumptions/Limitations:
    Assumed that this will be called only after all initialization is complete.
------------------------------------------------------------------------------*/
void LED_indicator_show_signal_strength(uint16_t val);

#endif
