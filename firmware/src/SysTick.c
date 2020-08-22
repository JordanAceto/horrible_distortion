/*
--|----------------------------------------------------------------------------|
--| FILE DESCRIPTION:
--|   SysTick.c provides the implementation for SysTick related functions,
--|   and implements the SysTick_Handler interrupt routine.
--|   
--|----------------------------------------------------------------------------|
--| REFERENCES:
--|   
--|
--|----------------------------------------------------------------------------|
*/

/*
--|----------------------------------------------------------------------------|
--| INCLUDE FILES
--|----------------------------------------------------------------------------|
*/

#include "SysTick.h"
#include "stm32f334x8.h"

/*
--|----------------------------------------------------------------------------|
--| PRIVATE DEFINES
--|----------------------------------------------------------------------------|
*/

/* None */

/*
--|----------------------------------------------------------------------------|
--| PRIVATE TYPES
--|----------------------------------------------------------------------------|
*/

/* None */

/*
--|----------------------------------------------------------------------------|
--| PRIVATE CONSTANTS
--|----------------------------------------------------------------------------|
*/

/* None */

/*
--|----------------------------------------------------------------------------|
--| PRIVATE VARIABLES
--|----------------------------------------------------------------------------|
*/

/*
--| NAME: mSec_since_reset 
--| DESCRIPTION: the number of milliseconds since the last power on/reset.
--| TYPE: uint32_t
*/
static volatile uint32_t mSec_since_reset = 0u;

/*
--|----------------------------------------------------------------------------|
--| PRIVATE HELPER FUNCTION PROTOTYPES
--|----------------------------------------------------------------------------|
*/

/*------------------------------------------------------------------------------
Function Name:
    Systick_Handler

Function Description:
    Interrupt routine for periodic Systick interrupts. Simply increments the
    mSec_since_reset variable.

Parameters:
    None

Returns:
    None

Assumptions/Limitations:
    None
------------------------------------------------------------------------------*/
void SysTick_Handler(void);

/*
--|----------------------------------------------------------------------------|
--| PUBLIC FUNCTION DEFINITIONS
--|----------------------------------------------------------------------------|
*/

void SysTick_Delay_mSec(uint32_t mSec)
{
    const uint32_t start_time = SysTick_Get_mSec();

    while ((SysTick_Get_mSec() - start_time) <= mSec)
    {
        // wait
    }
}

uint32_t SysTick_Get_mSec(void)
{
    return mSec_since_reset;
}

void SysTick_Start_Timeout_Timer(SysTick_Timeout_Timer_t * p_timer)
{
    p_timer->timeout_start_mSec = SysTick_Get_mSec();
}

bool SysTick_Poll_One_Shot_Timer(SysTick_Timeout_Timer_t * p_timer)
{
    return (SysTick_Get_mSec() - p_timer->timeout_start_mSec) >= p_timer->timeout_period_mSec;
}

bool SysTick_Poll_Periodic_Timer(SysTick_Timeout_Timer_t * p_timer)
{
    bool timeout_occured = SysTick_Poll_One_Shot_Timer(p_timer);

    if (timeout_occured) 
    {
        // reset the timer
        p_timer->timeout_start_mSec = SysTick_Get_mSec();
    }

    return timeout_occured;
}

/*
--|----------------------------------------------------------------------------|
--| PRIVATE HELPER FUNCTION DEFINITIONS
--|----------------------------------------------------------------------------|
*/

void SysTick_Handler(void)
{
    mSec_since_reset++;
}
