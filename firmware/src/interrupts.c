/*
--|----------------------------------------------------------------------------|
--| FILE DESCRIPTION:
--|   interrupts.h provides the implementation for the interrupts used by the 
--|   system.
--|   
--|   Two interrupt routines are used in the system: TIM3 update interrupts,
--|   and ADC2 end-of-conversion interrupts.
--|
--|   During the TIM3 UI the sample rate control signal is scaled and then used
--|   to set the sample rate of the audio input signal via TIM6 prescaler
--|   register, which controls the sample rate for ADC2.
--|
--|   During the ADC2 EOC interrupt the audio input signal and bit-depth
--|   control signals are scaled, and then the audio signal is processed by the
--|   bit crusher algorithm using the scaled bit-depth control signal. Then the
--|   crushed audio signal is written to the DAC.
--|
--|   The priority of the TIM3 update interrupt must be higher than the priority
--|   of the ADC EOC interrupt, because otherwise if the audio sample rate 
--|   becomes too fast it can block the TIM3 interrupt from firing, which locks
--|   the audio sample rate at the fast rate.
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

#include "bit_crusher.h"
#include "global_data.h"
#include "stm32f3xx.h"

/*
--|----------------------------------------------------------------------------|
--| PRIVATE DEFINES
--|----------------------------------------------------------------------------|
*/

// note that for interrupts, higher numbers mean lower priority

/*
--| NAME: TIM3_IRQ_PRIORITY
--| DESCRIPTION: the priority of the TIM3 interrupt, must be higher than ADC2
--| TYPE: uint
*/
#define TIM3_IRQ_PRIORITY (0)

/*
--| NAME: ADC2_IRQ_PRIORITY
--| DESCRIPTION: the priority of the ADC2 interrupt, must be lower than TIM3
--| TYPE: uint
*/
#define ADC2_IRQ_PRIORITY (1)

/*
--| NAME: UI12_MAX
--| DESCRIPTION: max value of unsigned 12 bit signal
--| TYPE: uint
*/
#define UI12_MAX (0x0FFFu)

/*
--|----------------------------------------------------------------------------|
--| PUBLIC FUNCTION DEFINITIONS
--|----------------------------------------------------------------------------|
*/

void interrupts_Init(void)
{
    // enable the TIM3 IRQ
    NVIC_SetPriority(TIM3_IRQn, TIM3_IRQ_PRIORITY);
    NVIC_EnableIRQ(TIM3_IRQn);

    // enable the ADC IRQ, note that only ADC2 is configured to generate interrupts
    NVIC_SetPriority(ADC1_2_IRQn, ADC2_IRQ_PRIORITY);
    NVIC_EnableIRQ(ADC1_2_IRQn);
}

void TIM3_IRQHandler(void)
{
    // invert and scale the sample-rate control signal to take up 16 bits, and ensure that it is never zero (avoids divide by zero)
    const uint32_t scaled_sample_rate_control_signal = ((UI12_MAX - control_reading[CONTROL_INPUT_SAMPLE_RATE]) << 4) + 1;

    // set the audio sample rate by changing TIM6's prescaler register
    TIM6->PSC = scaled_sample_rate_control_signal;

    // clear the Update Interrupt flag
    TIM3->SR &= ~TIM_SR_UIF;
}

void ADC1_2_IRQHandler(void)
{
    // invert and scale the audio input signal to take up 16 bits (inversion keeps the audio in phase with the input)
    const uint32_t scaled_input_signal = (UI12_MAX - ADC2->DR) << 4u;

    // invert and scale the bit-depth control signal to take up 16 bits
    const uint32_t scaled_bit_control_signal = (UI12_MAX - control_reading[CONTROL_INPUT_BIT_DEPTH]) << 4u;

    // process the input signal using the bit-depth control signal and scale it back down to 12 bits
    const uint32_t crushed_val = crush(scaled_input_signal, scaled_bit_control_signal) >> 4u;

    // update the DAC
    DAC1->DHR12R1 = crushed_val;
    DAC1->SWTRIGR |= DAC_SWTRIGR_SWTRIG1;

    // clear the ADC2 End Of Conversion flag
    ADC2->ISR &= ~ADC_ISR_EOC;
}
