/*
--|----------------------------------------------------------------------------|
--| FILE DESCRIPTION:
--|   TIM6.h provides the interface for initializing TIM6.
--|   
--|   TIM6 sets the sample time for reading the analog input signal with ADC2
--|   and then processing the signal before writing the bit-crushed signal
--|   to the DAC.
--|
--|   The PSC register of TIM6 is dynamically modulated by the sample-rate 
--|   control signal. Since TIM6 sets the sample time for the analog signal, 
--|   this allows for a dynamically modulated sample rate for creating special
--|   effects.
--|
--|----------------------------------------------------------------------------|
--| REFERENCES:
--|   STM32F334xx Reference Manual, page 806 (Basic Timers)
--|
--|----------------------------------------------------------------------------|
*/

#ifndef TIM6_H_INCLUDED
#define TIM6_H_INCLUDED

/*
--|----------------------------------------------------------------------------|
--| INCLUDE FILES
--|----------------------------------------------------------------------------|
*/

/* None */

/*
--|----------------------------------------------------------------------------|
--| PUBLIC DEFINES
--|----------------------------------------------------------------------------|
*/

/* None */

/*
--|----------------------------------------------------------------------------|
--| PUBLIC TYPES
--|----------------------------------------------------------------------------|
*/

/* None */

/*
--|----------------------------------------------------------------------------|
--| PUBLIC CONSTANTS
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
--| PUBLIC FUNCTION PROTOTYPES
--|----------------------------------------------------------------------------|
*/

/*------------------------------------------------------------------------------
Function Name:
    TIM6_Init

Function Description:
    Perform initialization of TIM6.

    TIM6 is configured to provide the trigger for peforming ADC2 conversions.

Parameters:
    None

Returns:
    None

Assumptions/Limitations:
    Assumed that this will be called before using TIM6.
------------------------------------------------------------------------------*/
void TIM6_Init(void);

#endif
