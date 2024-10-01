#ifndef PCNTR1_H
#define PCNTR1_H

#include <stdio.h>

// Simulate Port Direction Register for 10 ports * 16 bits
extern unsigned short PDR[10];
// Simulate Port Output Data Register for 10 ports * 16 bits
extern unsigned short PODR[10];

// Function declarations
int setup_PCNTR1(void);
int reset_PCNTR1(void);
int display_PCNTR1(void);

#endif // PCNTR1_H
