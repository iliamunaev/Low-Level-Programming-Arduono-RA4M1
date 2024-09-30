#define PORT1_PDR (*(volatile unsigned int *)0x40040022)
#define PORT1_PODR (*(volatile unsigned int *)0x40040020)

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
    // Set Pin 1_2 as output
    PORT1_PDR |= (1 << 2);

    while (1)
    {
        // Set Pin 1_2 to high
        PORT1_PODR |= (1 << 2);   // Set bit 2 high
        im_delay(500);            // Delay 500ms
        
        // Set Pin 1_2 to low
        PORT1_PODR &= ~(1 << 2);  // Clear bit 2 (set low)
        im_delay(500);            // Delay 500ms
    }
    return 0;
}
