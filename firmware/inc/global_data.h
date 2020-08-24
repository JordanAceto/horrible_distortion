/*
--|----------------------------------------------------------------------------|
--| FILE DESCRIPTION:
--|   global_data.h provides access to the global data used by the system.
--|   
--|  
--|----------------------------------------------------------------------------|
--| REFERENCES:
--|   None
--|
--|----------------------------------------------------------------------------|
*/

#ifndef GLOBAL_DATA_H_INCLUDED
#define GLOBAL_DATA_H_INCLUDED

/*
--|----------------------------------------------------------------------------|
--| INCLUDE FILES
--|----------------------------------------------------------------------------|
*/

#include <stdint.h>

/*
--|----------------------------------------------------------------------------|
--| PUBLIC TYPES
--|----------------------------------------------------------------------------|
*/

/*
--| NAME: Control_Input_enum
--| DESCRIPTION: named enumeration of control input signals
*/
typedef enum Control_Input_Enumeration
{
	CONTROL_INPUT_BIT_DEPTH = 0,
	CONTROL_INPUT_SAMPLE_RATE,
	NUM_CONTROL_INPUTS
} Control_Input_enum;

/*
--|----------------------------------------------------------------------------|
--| PUBLIC VARIABLES
--|----------------------------------------------------------------------------|
*/

/*
--| NAME: control_reading
--| DESCRIPTION: the digitized control signal readings, filled via DMA
--| TYPE: uint32_t
*/
uint32_t control_reading[NUM_CONTROL_INPUTS];

#endif
