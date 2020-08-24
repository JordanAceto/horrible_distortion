/*
--|----------------------------------------------------------------------------|
--| FILE DESCRIPTION:
--|   interrupts.h provides the interface for the interrupts used by the system.
--|   
--|   Two interrupt routines are used in the system: TIM3 update interrupts,
--|   and ADC2 end-of-conversion interrupts.
--|
--|   During the TIM3 UI the sample rate control signal is scaled and then used
--|   to set the sample rate of the audio input signal via TIM6 prescaler
--|   register, which controls the sample rate for ADC2.
--|
--|   During the ADC2 EOC interrupt the audio input signal and bit-depth
--|   control signals are scaled, and then the audio signal is processed by the
--|   bit crusher algorithm using the scaled bit-depth control signal. Then the
--|   crushed audio signal is written to the DAC.
--|
--|   The priority of the TIM3 update interrupt must be higher than the priority
--|   of the ADC EOC interrupt, because otherwise if the audio sample rate 
--|   becomes too fast it can block the TIM3 interrupt from firing, which locks
--|   the audio sample rate at the fast rate.
--|
--|----------------------------------------------------------------------------|
--| REFERENCES:
--|
--|----------------------------------------------------------------------------|
*/

#ifndef INTERRUPTS_H_INCLUDED
#define INTERRUPTS_H_INCLUDED

/*
--|----------------------------------------------------------------------------|
--| PUBLIC FUNCTION PROTOTYPES
--|----------------------------------------------------------------------------|
*/

/*------------------------------------------------------------------------------
Function Name:
    interrupts_Init

Function Description:
    Perform initialization of the interrupts used by the system.

    TIM3 update interrupts are enabled and ADC2 end-of-conversion interrupts
    are enabled.

    The TIM3 interrupt must have a higher priority than the ADC2 interrupt.

Parameters:
    None

Returns:
    None

Assumptions/Limitations:
    Assumed that this will be called as part of system initialization.
------------------------------------------------------------------------------*/
void interrupts_Init(void);

/*------------------------------------------------------------------------------
Function Name:
    TIM3_IRQHandler

Function Description:
    IRQ handler for the TIM3 interrupt.

    Scales the sample-rate control signal and sets the sample rate for the 
    audio signal convered by ADC2.

Parameters:
    None

Returns:
    None

Assumptions/Limitations:
    None
------------------------------------------------------------------------------*/
void TIM3_IRQHandler(void);

/*------------------------------------------------------------------------------
Function Name:
    ADC1_2_IRQHandler

Function Description:
    IRQ handler for the ADC interrupt.

    Scales the audio input signal and the bit-depth control signal. Processes
    the audio signal with the bit crushing algorithm using the bit-depth
    control signal. Writes the processed audio signal to the DAC.

Parameters:
    None

Returns:
    None

Assumptions/Limitations:
    None
------------------------------------------------------------------------------*/
void ADC1_2_IRQHandler(void);

#endif
