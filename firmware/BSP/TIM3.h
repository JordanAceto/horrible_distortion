/*
--|----------------------------------------------------------------------------|
--| FILE DESCRIPTION:
--|   TIM3.h provides the interface for initializing TIM3.
--|   
--|   TIM3 sets the sample time for reading the analog control signals for
--|   bit-resolution and audio-sample-rate.
--|
--|----------------------------------------------------------------------------|
--| REFERENCES:
--|   STM32F334xx Reference Manual, page 478 (General Purpose Timers)
--|
--|----------------------------------------------------------------------------|
*/

#ifndef TIM3_H_INCLUDED
#define TIM3_H_INCLUDED

/*
--|----------------------------------------------------------------------------|
--| PUBLIC FUNCTION PROTOTYPES
--|----------------------------------------------------------------------------|
*/

/*------------------------------------------------------------------------------
Function Name:
    TIM3_Init

Function Description:
    Perform initialization of TIM3.

    TIM3 is configured to provide the trigger for performing ADC1 conversions.

Parameters:
    None

Returns:
    None

Assumptions/Limitations:
    Assumed that this will be called before using TIM3.
------------------------------------------------------------------------------*/
void TIM3_Init(void);

#endif
