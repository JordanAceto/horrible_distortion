/*
--|----------------------------------------------------------------------------|
--| FILE DESCRIPTION:
--|   ADC2.h provides the interface for initializing ADC2.
--|   
--|   ADC2 channel 2 automatically reads the audio input signal on pin PA5
--|   at a frequency defined by TIM6.
--|
--|   The frequency of TIM6 is dynamically modulated to achieve special sample
--|   rate reduction aliasing effects of the ADC2 reading.
--|   
--|----------------------------------------------------------------------------|
--| REFERENCES:
--|   STM32F334xx Reference Manual, page 104 (RCC)
--|   STM32F334xx Reference Manual, page 211 (ADC)
--|
--|----------------------------------------------------------------------------|
*/

#ifndef ADC2_H_INCLUDED
#define ADC2_H_INCLUDED

/*
--|----------------------------------------------------------------------------|
--| PUBLIC FUNCTION PROTOTYPES
--|----------------------------------------------------------------------------|
*/

/*------------------------------------------------------------------------------
Function Name:
    ADC2_Init

Function Description:
    Perform initialization of ADC2.

    ADC2 is configured to automatically sample the audio input signal at a
    period defined by TIM6. The sampled audio will be continuously available
    in the ADC2 Data Register.

Parameters:
    None

Returns:
    None

Assumptions/Limitations:
    Assumed that this will be called before using ADC2.
------------------------------------------------------------------------------*/
void ADC2_Init(void);

#endif
