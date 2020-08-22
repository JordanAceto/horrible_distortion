#include "stm32f334x8.h"
#include "SysTick.h"

int main(void)
{
    // enable GPIO port A
    RCC->AHBENR |= RCC_AHBENR_GPIOAEN;

    // set port A pin 8 to output
    GPIOA->MODER |= GPIO_MODER_MODER8_0;

    // set port A pin 9 to output
    GPIOA->MODER |= GPIO_MODER_MODER9_0;

    SysTick_Init();

    while(1)
    {
        // blink the LED on PA8
        GPIOA->BSRR = GPIO_BSRR_BS_8;

        SysTick_Delay_mSec(1000);

        GPIOA->BSRR = GPIO_BSRR_BR_8;
        
        SysTick_Delay_mSec(1000);
    }
}
