# STM32F334K6 bitcrusher firmware

This project uses the CMSIS header library.

Prerequisites for building and flashing the project:
- You need the arm-none-eabi toolchain.
- You must be able to run makefiles with the `make` command.
- You need an st-link programmer or equivalent device which can burn code to stm32 microcontrollers.
- You need a 4-pin cable to go from the st-link and the SWD header on the main bitcrusher pcb.
- You need to install the st-link software on your computer, see here: https://github.com/stlink-org/stlink

To build the project:
- `make` will compile and link the project.
- The resulting output files will be placed in the `./bin/` directory.

To flash the project:
- Connect the st-link device to your computer with a USB cord.
- Connect the st-link to the main bitcrusher pcb with a 4-pin cable.
- Apply power to the bitcrusher.
- `make write` will flash the binary to the stm32f334 on the main bitcrusher pcb.
