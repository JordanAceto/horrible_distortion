/*
--|----------------------------------------------------------------------------|
--| FILE DESCRIPTION:
--|   bit_crusher.c provides the implementation for the bit-crushing algorithm.
--|
--|----------------------------------------------------------------------------|
--| REFERENCES:
--|   None.
--|
--|----------------------------------------------------------------------------|
*/

/*
--|----------------------------------------------------------------------------|
--| INCLUDE FILES
--|----------------------------------------------------------------------------|
*/

#include "bit_crusher.h"

/*
--|----------------------------------------------------------------------------|
--| PRIVATE DEFINES
--|----------------------------------------------------------------------------|
*/

/*
--| NAME: TOTAL_RESOLUTION_IN_BITS
--| DESCRIPTION: the number of total bits that the bit crusher can process
--| TYPE: uint
*/
#define TOTAL_RESOLUTION_IN_BITS (16u)

/*
--| NAME: CUTOFF_INDEX_RESOLUTION_IN_BITS
--| DESCRIPTION: the number of index bits for the cutoff portion of the control signal
--| TYPE: uint
*/
#define CUTOFF_INDEX_RESOLUTION_IN_BITS (4u)

/*
--| NAME: FRACTIONAL_RESOLUTION_IN_BITS
--| DESCRIPTION: the number of fractional bits in the control signal
--| TYPE: uint
*/
#define FRACTIONAL_RESOLUTION_IN_BITS (TOTAL_RESOLUTION_IN_BITS - CUTOFF_INDEX_RESOLUTION_IN_BITS)

/*
--| NAME: FRACTIONAL_BIT_MASK
--| DESCRIPTION: mask for extracting the fractional control bits
--| TYPE: uint
*/
#define FRACTIONAL_BIT_MASK ((1u << FRACTIONAL_RESOLUTION_IN_BITS) - 1u)

/*
--|----------------------------------------------------------------------------|
--| PUBLIC FUNCTION DEFINITIONS
--|----------------------------------------------------------------------------|
*/

uint16_t crush(uint16_t signal_input, uint16_t control_input)
{
	// take the upper four bits of the control as the cutoff position
	const uint16_t cutoff_position = 1u << (control_input >> FRACTIONAL_RESOLUTION_IN_BITS);

	// invert the lower 12 bits of the control signal, this is used to attenuate the bit right at the cutoff
	const uint16_t fractional_control_signal = FRACTIONAL_BIT_MASK - (control_input & FRACTIONAL_BIT_MASK);

	// keep everything above the cutoff (aka throw away everything at the cutoff and lower)
	uint16_t retval = signal_input & ~(cutoff_position | (cutoff_position - 1u));

    // TODO: finalize and tidy up the code below
	if (cutoff_position == (1u << 15u))
	{
		// do weird offset stuff at the last cutoff position, work in progress here
		signal_input += (fractional_control_signal << 4u);
		retval = (signal_input & cutoff_position);
	}
	else // this is the normal path
	{
		// and add in the attenuated contribution of the bit right at the cutoff
		retval += ((signal_input & cutoff_position) * fractional_control_signal) >> FRACTIONAL_RESOLUTION_IN_BITS;
	}

	return retval;
}
