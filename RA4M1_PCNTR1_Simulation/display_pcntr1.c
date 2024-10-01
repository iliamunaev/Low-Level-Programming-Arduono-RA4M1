#include "pcntr1.h"

// Display PCNTR1 values
int display_PCNTR1(void)
{
    for(int i = 0; i < 10; i++) 
    {
        printf("PDR[%i]: ", i);
        for(int j = 0; j < 16; j++)
        {
            printf("%i", PDR[i]);
        }
        printf(" PODR[%i]: ", i);
        for(int j = 0; j < 16; j++)
        {
            printf("%i", PODR[i]);
        }
        printf("\n");
    }
    printf("---RCNTR1 setup/reset successfully---\n");
    return 0;
}