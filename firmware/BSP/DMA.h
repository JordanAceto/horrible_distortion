/*
--|----------------------------------------------------------------------------|
--| FILE DESCRIPTION:
--|   DMA.h provides the interface for initializing the Direct Memory Access
--|   controller.
--|
--|   DMA is used to transfer the control reading signals from the ADC to the
--|   global storage variable control_reading[]. This allows the ADC to work
--|   completely in the background, we can access the control readings at any
--|   time via the symbol control_reading[index_of_desired_control_signal].
--|
--|----------------------------------------------------------------------------|
--| REFERENCES:
--|   STM32F334xx Reference Manual, page 170
--|
--|----------------------------------------------------------------------------|
*/

#ifndef DMA_H_INCLUDED
#define DMA_H_INCLUDED

/*
--|----------------------------------------------------------------------------|
--| PUBLIC FUNCTION PROTOTYPES
--|----------------------------------------------------------------------------|
*/

/*------------------------------------------------------------------------------
Function Name:
    DMA_Init

Function Description:
    Perform initialization of DMA.

    The DMA controller is configured to take the two control signal readings
    from ADC1 and deliver them to the global siganl control_reading[].

Parameters:
    None

Returns:
    None

Assumptions/Limitations:
    Assumed that this will be called before using DMA.
------------------------------------------------------------------------------*/
void DMA_Init(void);

#endif
