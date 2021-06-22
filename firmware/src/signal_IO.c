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

/*
--|----------------------------------------------------------------------------|
--| INCLUDE FILES
--|----------------------------------------------------------------------------|
*/

#include "ADC2.h"
#include "DAC1.h"
#include "LED_indicator.h"
#include "signal_IO.h"
#include "TIM6.h"

/*
--|----------------------------------------------------------------------------|
--| PRIVATE DEFINES
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
--| PRIVATE VARIABLES
--|----------------------------------------------------------------------------|
*/

/*
--| NAME: control_reading
--| DESCRIPTION: the digitized control signal readings, filled via DMA
--| TYPE: uint32_t
*/
uint32_t control_reading[NUM_CONTROL_INPUTS];

/*
--|----------------------------------------------------------------------------|
--| PRIVATE FUNCTION PROTOTYPES
--|----------------------------------------------------------------------------|
*/

/*------------------------------------------------------------------------------
Function Name:
    invert_and_scale_ui12_to_ui16

Function Description:
    Take a 12 bit signal, invert it, and scale it up to cover a 16 bit range.

Parameters:
    val_ui12 (uint16_t): the 12 bit value to invert and scale up.

Returns:
    uint16_t: the original value, inverted and scaled up to cover 16 bits.

Assumptions/Limitations:
    None
------------------------------------------------------------------------------*/
uint16_t invert_and_scale_ui12_to_ui16(uint16_t val_ui12);

/*
--|----------------------------------------------------------------------------|
--| PUBLIC FUNCTION DEFINITIONS
--|----------------------------------------------------------------------------|
*/

uint16_t get_control_input_signal(Control_Input_Enum_t signal_type)
{
    return invert_and_scale_ui12_to_ui16(control_reading[signal_type]);
}

uint16_t get_audio_input_signal(void)
{
    return invert_and_scale_ui12_to_ui16(ADC2_get_ui12());
}

void write_audio_output_signal(uint16_t val)
{
    // scale from 16 bits down to 12 bits for the DAC
    DAC1_write_ui12(val >> 4u);
}

void set_audio_sample_rate(uint16_t val)
{
    TIM6_set_prescaler(val);
}

/*
--|----------------------------------------------------------------------------|
--| PRIVATE FUNCTION DEFINITIONS
--|----------------------------------------------------------------------------|
*/

uint16_t invert_and_scale_ui12_to_ui16(uint16_t val_ui12)
{
    return (UI12_MAX - val_ui12) << 4u;
}
