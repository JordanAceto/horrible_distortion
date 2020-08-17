stm32 based bitcrusher as a going away present for Ken

![](./main_pcb/pics/pcb_rear.png?raw=true "pcb rear") 

pcbs are layed out and ordered, waiting on arrival.
parts are ordered, waiting on arrival.

Algorithm idea: 
    Use ADC/DMA to read the signal input, and a different ADC/DMA to read the two control inputs.
    Lets call the timer for the signal DMA tim_s and the timer for the control tim_c.
    Set up interrupts to fire for both ADCs.
    When the control ADC interrupt fires, write the scaled sample rate control signal to tim_s PSC register.
    When the signal ADC interrupt fires, update the DAC.
    This is a really simple way to control the sample rate, may need some clever scaling to sound good, experiment.
    The above is started in my local CubeIDE projects, seems promising. I have tested it with an stm32F405, and started porting it to an f334.

## License:
- ### hardware: CC by 4.0
- ### software: MIT license
- ### by: Jordan Aceto

## Status of the project:

revision | schematic | pcb layout | firmware | built and tested | notes
---------|-----------|------------|----------|------------------|---------------
0        | &#9745;   | &#9745;    | &#9745;  | &#9745;          | needs compander


revision | schematic | pcb layout | firmware | built and tested | notes
---------|-----------|------------|----------|------------------|---------------
1        | &#9744;   | &#9744;    | &#9744;  | &#9744;          | 