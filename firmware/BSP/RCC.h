/*
--|----------------------------------------------------------------------------|
--| FILE DESCRIPTION:
--|   RCC.h provides the interface for initializing the Reset and Clock
--|   Control registers.
--|
--|   The system clock is initialized to use the external 8MHz oscillator which
--|   is multiplied by the PLL to 72MHz. The APB1 bus is divided to 36MHz.
--|   Two FLASH wait states are enabled, because the clock speed is greater
--|   than 48MHz.
--|
--|----------------------------------------------------------------------------|
--| REFERENCES:
--|   STM32F334xx Reference Manual, page 104 (RCC)
--|   STM32F334xx Reference Manual, page 54 (FLASH)
--|   STM32F334x6 datasheet, page 18 (clock tree)
--|
--|----------------------------------------------------------------------------|
*/

#ifndef RCC_H_INCLUDED
#define RCC_H_INCLUDED

/*
--|----------------------------------------------------------------------------|
--| PUBLIC FUNCTION PROTOTYPES
--|----------------------------------------------------------------------------|
*/

/*------------------------------------------------------------------------------
Function Name:
    RCC_Init

Function Description:
    Perform initialization of the Reset and Clock Control registers. Sets the 
    system clock to use the external 8MHz crystal oscillator, multiplied by
    the PLL to reach a final clock frequency of 72MHz.

    Since the final clock frequency is greater than 48MHz, two wait states
    are added to the FLASH controller.

Parameters:
    None

Returns:
    None

Assumptions/Limitations:
    Assumed that this will be called before branching to the main application.
------------------------------------------------------------------------------*/
void RCC_Init(void);

#endif
