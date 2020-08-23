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
--| PUBLIC DEFINES
--|----------------------------------------------------------------------------|
*/

/*
--| NAME: UI12_MAX
--| DESCRIPTION: max value of unsigned 12 bit signal
--| TYPE: uint
*/
#define UI12_MAX (0x0FFFu)

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
--| PUBLIC CONSTANTS
--|----------------------------------------------------------------------------|
*/

/* None */

/*
--|----------------------------------------------------------------------------|
--| PUBLIC VARIABLES
--|----------------------------------------------------------------------------|
*/

/*
--| NAME: audio_signal_reading
--| DESCRIPTION: the digitized audio signal reading
--| TYPE: uint32_t
*/
uint32_t audio_signal_reading;

/*
--| NAME: control_reading
--| DESCRIPTION: the digitized control signal readings
--| TYPE: uint32_t
*/
uint32_t control_reading[NUM_CONTROL_INPUTS];

/*
--|----------------------------------------------------------------------------|
--| PUBLIC FUNCTION PROTOTYPES
--|----------------------------------------------------------------------------|
*/

/* None */

#endif
