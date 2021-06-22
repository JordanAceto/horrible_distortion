/*
--|----------------------------------------------------------------------------|
--| FILE DESCRIPTION:
--|   signal_IO.h acts as an interface between the low level ADC, DAC, and DMA 
--|   peripherals and the application layer.
--|   
--|----------------------------------------------------------------------------|
--| REFERENCES:
--|   None
--|
--|----------------------------------------------------------------------------|
*/

#ifndef SIGNAL_IO_H_INCLUDED
#define SIGNAL_IO_H_INCLUDED

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
--| NAME: Control_Input_Enum_t
--| DESCRIPTION: named enumeration of control input signals
*/
typedef enum Control_Input_Enumeration_Type
{
    CONTROL_INPUT_BIT_DEPTH = 0,
    CONTROL_INPUT_SAMPLE_RATE,
    NUM_CONTROL_INPUTS
} Control_Input_Enum_t;

/*
--|----------------------------------------------------------------------------|
--| PUBLIC FUNCTION PROTOTYPES
--|----------------------------------------------------------------------------|
*/

/*------------------------------------------------------------------------------
Function Name:
    get_control_input_signal

Function Description:
    Get the current value of the given control signal.

Parameters:
    signal_type (Control_Input_enum): the signal to get.

Returns:
    uint16_t: the current value of the given control signal.

Assumptions/Limitations:
    Assumes that the given signal type is a valid Control_Input_Enum_t
------------------------------------------------------------------------------*/
uint16_t get_control_input_signal(Control_Input_Enum_t signal_type);

/*------------------------------------------------------------------------------
Function Name:
    get_audio_input_signal

Function Description:
    Get the current value of the audio input signal.

Parameters:
    None

Returns:
    uint16_t: the current value of the audio input signal.

Assumptions/Limitations:
    None
------------------------------------------------------------------------------*/
uint16_t get_audio_input_signal(void);

/*------------------------------------------------------------------------------
Function Name:
    write_audio_output_signal

Function Description:
    Write the given audio signal value to the system output.

Parameters:
    val (uint16_t): the audio signal value to write.

Returns:
    None

Assumptions/Limitations:
    None
------------------------------------------------------------------------------*/
void write_audio_output_signal(uint16_t val);

/*------------------------------------------------------------------------------
Function Name:
    set_audio_sample_rate

Function Description:
    Set the audio sample rate to the given value (the value is just an arbitrary
    linear signal for now, there should be a more sophisticated mapping in the
    future).

Parameters:
    val (uint16_t): the sample rate signal to use.

Returns:
    None

Assumptions/Limitations:
    None
------------------------------------------------------------------------------*/
void set_audio_sample_rate(uint16_t val);

#endif
