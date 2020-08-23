/*
--|----------------------------------------------------------------------------|
--| FILE DESCRIPTION:
--|   GPIO.h provides the interface for initializing the GPIO pins.
--|   
--|   PA0 is an analog input mapped to the bit-resolution CV signal.
--|   PA1 is an analog input mapped to the sample-rate CV signal.
--|   PA4 is the DAC output which outputs the processed audio signal.
--|   PA5 is an analog input mapped to the audio input signal.
--|   PA8 is a discrete output mapped to the GREEN LED.
--|   PA9 is a discrete output mapped to the RED LED.
--| 
--|----------------------------------------------------------------------------|
--| REFERENCES:
--|   STM32F334xx Reference Manual, page 104 (RCC)
--|   STM32F334xx Reference Manual, page 139 (GPIO)
--|
--|----------------------------------------------------------------------------|
*/

#ifndef GPIO_H_INCLUDED
#define GPIO_H_INCLUDED

/*
--|----------------------------------------------------------------------------|
--| INCLUDE FILES
--|----------------------------------------------------------------------------|
*/

/* None */

/*
--|----------------------------------------------------------------------------|
--| PUBLIC DEFINES
--|----------------------------------------------------------------------------|
*/

/* None */

/*
--|----------------------------------------------------------------------------|
--| PUBLIC TYPES
--|----------------------------------------------------------------------------|
*/

/* None */

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

/* None */

/*
--|----------------------------------------------------------------------------|
--| PUBLIC FUNCTION PROTOTYPES
--|----------------------------------------------------------------------------|
*/

/*------------------------------------------------------------------------------
Function Name:
    GPIO_Init

Function Description:
    Perform initialization of the GPIO pins. Sets up the control signal ADC 
    inputs, the audio ADC input, the audio DAC output, and the red and green 
    LEDs as outputs.

Parameters:
    None

Returns:
    None

Assumptions/Limitations:
    Assumed that this will be called before using any of the GPIO pins.
------------------------------------------------------------------------------*/
void GPIO_Init(void);

#endif
