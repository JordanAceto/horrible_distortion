/*
--|----------------------------------------------------------------------------|
--| FILE DESCRIPTION:
--|   interrupts.h provides the implementation for the interrupts used by the 
--|   system.
--|   
--|  
--|----------------------------------------------------------------------------|
--| REFERENCES:
--|
--|----------------------------------------------------------------------------|
*/

/*
--|----------------------------------------------------------------------------|
--| INCLUDE FILES
--|----------------------------------------------------------------------------|
*/

#include "interrupts.h"
#include "stm32f3xx.h"

/*
--|----------------------------------------------------------------------------|
--| PRIVATE DEFINES
--|----------------------------------------------------------------------------|
*/

// note that for interrupts, higher numbers mean lower priority and vice versa

/*
--| NAME: TIM3_IRQ_PRIORITY
--| DESCRIPTION: the priority of the TIM3 interrupt, must be higher than TIM6
--| TYPE: uint
*/
#define TIM3_IRQ_PRIORITY (0u)

/*
--| NAME: TIM6_IRQ_PRIORITY
--| DESCRIPTION: the priority of the TIM6 interrupt
--| TYPE: uint
*/
#define TIM6_IRQ_PRIORITY (1u)

/*
--|----------------------------------------------------------------------------|
--| PRIVATE VARIABLES
--|----------------------------------------------------------------------------|
*/

/*
--| NAME: flags
--| DESCRIPTION: the interrupt flags used by the system
--| TYPE: bool
*/
static volatile bool flags[NUM_INTERRUPT_FLAG_TYPES];

/*
--|----------------------------------------------------------------------------|
--| PRIVATE HELPER FUNCTION PROTOTYPES
--|----------------------------------------------------------------------------|
*/

/*------------------------------------------------------------------------------
Function Name:
    interrupt_set_flag

Function Description:
    Set the specified interrupt flag.

Parameters:
    flag: the flag to set

Returns:
    None

Assumptions/Limitations:
    Assumed that the flag is a member of the Interrupt_Flag_t enumeration.
------------------------------------------------------------------------------*/
void interrupt_set_flag(Interrupt_Flag_t flag);

/*------------------------------------------------------------------------------
Function Name:
    interrupt_clear_flag

Function Description:
    Clear the specified interrupt flag.

Parameters:
    flag: the flag to clear

Returns:
    None

Assumptions/Limitations:
    Assumed that the flag is a member of the Interrupt_Flag_t enumeration.
------------------------------------------------------------------------------*/
void interrupt_clear_flag(Interrupt_Flag_t flag);

/*
--|----------------------------------------------------------------------------|
--| PUBLIC FUNCTION DEFINITIONS
--|----------------------------------------------------------------------------|
*/

void interrupts_Init(void)
{
    NVIC_SetPriority(TIM3_IRQn, TIM3_IRQ_PRIORITY);
    NVIC_EnableIRQ(TIM3_IRQn);

    NVIC_SetPriority(TIM6_DAC1_IRQn, TIM6_IRQ_PRIORITY);
    NVIC_EnableIRQ(TIM6_DAC1_IRQn);
}

bool interrupt_get_flag(Interrupt_Flag_t flag)
{
    const bool retval = flags[flag];
    interrupt_clear_flag(flag);
    return retval;
}

/*
--|----------------------------------------------------------------------------|
--| PRIVATE HELPER FUNCTION DEFINITIONS
--|----------------------------------------------------------------------------|
*/

void interrupt_set_flag(Interrupt_Flag_t flag)
{
    flags[flag] = true;
}

void interrupt_clear_flag(Interrupt_Flag_t flag)
{
    flags[flag] = false;
}

void TIM3_IRQHandler(void)
{
    interrupt_set_flag(INTERRUPT_FLAG_TIM3);

    // clear the Update Interrupt flag in the status register
    TIM3->SR &= ~TIM_SR_UIF;
}

void TIM6_DAC1_IRQHandler(void)
{
    interrupt_set_flag(INTERRUPT_FLAG_TIM6);

    // clear the Update Interrupt flag in the status register
    TIM6->SR &= ~TIM_SR_UIF;
}
