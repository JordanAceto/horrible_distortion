/*
--|----------------------------------------------------------------------------|
--| FILE DESCRIPTION:
--|   main.c provides the main application entry point implementation.
--|
--|   The main.c function is simply an empty while true loop. The processing
--|   happens automatically: Analog To Digital converters are automatically
--|   triggered by timers. Global data is filled via the Direct-Memory-Access
--|   (DMA) controller. Further signal processign takes place in 
--|   Interrupt-Service-Routines (ISRs).
--|
--|----------------------------------------------------------------------------|
--| REFERENCES:
--|   None
--|
--|----------------------------------------------------------------------------|
*/

/*
--|----------------------------------------------------------------------------|
--| PUBLIC FUNCTION DEFINITIONS
--|----------------------------------------------------------------------------|
*/

int main(void)
{

    while(1)
    {
        // nothing to see here
    }

    // never reached
    return 0;
}
