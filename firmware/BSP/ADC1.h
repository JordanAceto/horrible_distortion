/*
--|----------------------------------------------------------------------------|
--| FILE DESCRIPTION:
--|   ADC1.h provides the interface for initializing ADC1.
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

#ifndef ADC1_H_INCLUDED
#define ADC1_H_INCLUDED

/*
--|----------------------------------------------------------------------------|
--| PUBLIC FUNCTION PROTOTYPES
--|----------------------------------------------------------------------------|
*/

/*------------------------------------------------------------------------------
Function Name:
    ADC1_Init

Function Description:
    Perform initialization of ADC1.

    ADC1 is configured to automatically scan the control signals for bit-depth
    and sample-rate at a period defined by TIM3. The readings are automatically 
    delivered to the global signal control_reading[] via the DMA controller.

Parameters:
    None

Returns:
    None

Assumptions/Limitations:
    Assumed that this will be called before using ADC1.
------------------------------------------------------------------------------*/
void ADC1_Init(void);

#endif
