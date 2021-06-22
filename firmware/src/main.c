/*
--|----------------------------------------------------------------------------|
--| FILE DESCRIPTION:
--|   main.c provides the main application entry point implementation.
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

#include "bit_crusher.h"
#include "interrupts.h"
#include "LED_indicator.h"
#include "signal_IO.h"

/*
--|----------------------------------------------------------------------------|
--| PRIVATE FUNCTION PROTOTYPES
--|----------------------------------------------------------------------------|
*/

/*------------------------------------------------------------------------------
Function Name:
    main

Function Description:
    The main application.

Parameters:
    None

Returns:
    None

Assumptions/Limitations:
    Assumed that main will be called from the assembly startup routine after all
    system initialization is complete. Do not manually call this function.

    This function enters an infinite loop
    that is not expected to terminate.
------------------------------------------------------------------------------*/
int main(void);

/*
--|----------------------------------------------------------------------------|
--| PRIVATE FUNCTION DEFINITIONS
--|----------------------------------------------------------------------------|
*/

int main(void)
{
    while(1)
    {
        // read and scale the control signals and update the clipping LED periodically
        if (interrupt_get_flag(INTERRUPT_FLAG_TIM3))
        {
            set_audio_sample_rate(get_control_input_signal(CONTROL_INPUT_SAMPLE_RATE));

            LED_indicator_show_signal_strength(get_audio_input_signal());
        }

        // do the bit-crushing routine and update the output when the audio input signal is ready
        if (interrupt_get_flag(INTERRUPT_FLAG_TIM6))
        {
            write_audio_output_signal(
                crush(
                    get_audio_input_signal(),
                    get_control_input_signal(CONTROL_INPUT_BIT_DEPTH)
                )
            );
        }
    }

    // never reached
    return 0;
}
