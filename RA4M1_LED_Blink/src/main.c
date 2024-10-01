#define PDR (*(volatile unsigned int *)0x40040022)
#define PODR (*(volatile unsigned int *)0x40040020)

void im_delay(volatile unsigned int ms)
{    
    volatile unsigned int count;
    while (ms--)
    {
        for(count = 0; count < 1000; count++);
    }
}

int main(void)
{
    // Set Pin 102 as output
    PDR |= (1 << 2);

    while (1)
    {
        // Set Pin 102 to high
        PODR |= (1 << 2);   // Set bit 2 high
        im_delay(500);            // Delay 500ms
        
        // Set Pin 102 to low
        PODR &= ~(1 << 2);  // Clear bit 2 (set low)
        im_delay(500);            // Delay 500ms
    }
    return 0;
}