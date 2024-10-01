/*
 * Simulates 10 Port Direction (PDR) and Output Data (PODR) registers, 
 * each 16 bits wide. 
 * setup_PCNTR1(): Initializes PDR and PODR to zero.
 * reset_PCNTR1(): Resets PDR and PODR using setup_PCNTR1().
 * Test prints out the register values after setup and reset.
 */
#include "pcntr1.h"

// Define the PDR and PODR arrays
unsigned short PDR[10];
unsigned short PODR[10];

// Setup the Port Control Register 1, assign values to 0
int setup_PCNTR1(void)
{
    int i = 0;

    while(i <= 9)
    {
        PDR[i] = 0;
        PODR[i] = 0;
        i++;
    }
    return 0;
}

// Reset the Port Control Register 1, assign values to 0
int reset_PCNTR1(void)
{
    return setup_PCNTR1();
}
//* test
int display_PCNTR1(void);

int main(void)
{
    // Setup and reset the PCNTR1
    setup_PCNTR1();   // Initial setup
    display_PCNTR1();
    reset_PCNTR1();   // Reset the registers
    display_PCNTR1();

    return 0;
}
//*/