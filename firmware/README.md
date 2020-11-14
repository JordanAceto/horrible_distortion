# STM32F334K6 bitcrusher firmware

## Brief overview of the algorithm:

ADC1 reads the control signals for bit-depth and sample rate automatically at a sample rate set by timer 3.
The control parameters are saved in a global signal via the DMA controller.

The audio signal is read by ADC2, triggered by timer 6, at a variable sample rate set by the sample-rate control signal.

The digitized audio signal is then processed by the bit crusher algorithm and output via DAC1.

A simple bicolor LED indicator is attached to two GPIO pins and acts as a basic signal strength and clipping indicator.

All signal processing happens in two interrupt routines. The slower control signals are processed in the TIM3 IRQ handler which is set to trigger on TIM3 Updates. 
The variable rate audio processing happens in the ADC1_2 IRQ handler which is configured to trigger on ADC2 End Of Conversions.

--- 

## This project uses the CMSIS header library supplied by ST.

---

## Prerequisites for building and flashing the project:
- You need the arm-none-eabi toolchain.
- You must be able to run makefiles with the `make` command.
- You need an st-link programmer or equivalent device which can burn code to stm32 microcontrollers.
- You need a 4-pin cable to go from the st-link and the SWD header on the main bitcrusher pcb.
- You need to install the st-link software on your computer, see here: https://github.com/stlink-org/stlink

## To build the project:
- `make` will compile and link the project.
- The resulting output files will be placed in the `./bin/` directory.

## To flash the project:
- Connect the st-link device to your computer with a USB cord.
- Connect the st-link to the main bitcrusher pcb SWD header with a 4-pin cable.
- Apply power to the bitcrusher.
- `make write` will flash the binary to the stm32f334 on the main bitcrusher pcb.
