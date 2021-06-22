/*
--|----------------------------------------------------------------------------|
--| FILE DESCRIPTION:
--|   DAC1.h provides the interface for initializing DAC1.
--|   
--|   DAC1 outputs the procesed audio signal on channel 1.
--|  
--|----------------------------------------------------------------------------|
--| REFERENCES:
--|   STM32F334xx Reference Manual, page 104 (RCC)
--|   STM32F334xx Reference Manual, page 317 (DAC)
--|
--|----------------------------------------------------------------------------|
*/

#ifndef DAC1_H_INCLUDED
#define DAC1_H_INCLUDED

/*
--|----------------------------------------------------------------------------|
--| PUBLIC FUNCTION PROTOTYPES
--|----------------------------------------------------------------------------|
*/

/*------------------------------------------------------------------------------
Function Name:
    DAC1_Init

Function Description:
    Perform initialization of the DAC. DAC1 channel 1 outputs the processed
    audio signal.

Parameters:
    None

Returns:
    None

Assumptions/Limitations:
    Assumed that this will be called before using DAC1.
------------------------------------------------------------------------------*/
void DAC1_Init(void);

/*------------------------------------------------------------------------------
Function Name:
    DAC1_write_ui12

Function Description:
    Write the given right-aligned 12 bit signal to the DAC.

Parameters:
    val (uint16_t): the value to write, only the lower 12 bits are written.

Returns:
    None

Assumptions/Limitations:
    Assumed that DAC1 has been initialized.
------------------------------------------------------------------------------*/
void DAC1_write_ui12(uint16_t val);

#endif
