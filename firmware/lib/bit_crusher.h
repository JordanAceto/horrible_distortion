/*
--|----------------------------------------------------------------------------|
--| FILE DESCRIPTION:
--|   bit_crusher.h provides an interface for creating bit-crusher effects.
--|
--|----------------------------------------------------------------------------|
--| REFERENCES:
--|   None.
--|
--|----------------------------------------------------------------------------|
*/

#ifndef BIT_CRUSHER_H_INCLUDED
#define BIT_CRUSHER_H_INCLUDED

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
    crush

Function Description:
    Apply bit-crushing to a single sample of the given input.

Parameters:
    signal_input: unsigned 16-bit signal input
    
    control_input: unsigned 16-bit control input. Higher values are 
                   "more crushed", ie have fewer bits of resolution.

Returns:
    uint16_t: the processed input signal after going through the bit crusher
              algorithm.

Assumptions/Limitations:
    None
------------------------------------------------------------------------------*/
uint16_t crush(uint16_t signal_input, uint16_t control_input);

#endif
