/* 
 * LED Blinl Bare Metal Programming
 *
 * The bare-metal code for toggling Pin 2 of Port 1 on a Renesas
 * microcontroller using memory-mapped registers.
 * It sets the pin as an output and alternately turns the LED on and off.
 * Created: 17.10.2024
 * By: Ilia Munaev, ilyamunaev@gmail.com
 */

#define PORT1_PDR (*(volatile uint16_t *)0x40040022)  // PDR address for setting the direction
#define PORT1_PODR (*(volatile uint16_t *)0x40040020) // PODR address for setting the output state

void delay(volatile uint32_t count)  // Simple delay function
{
    while(count--);
}

int main(void)
{
  PORT1_PDR |= (1 << 2);   // Set Pin 2 of Port 1 as an output

  while(1)
  {
    PORT1_PODR ^= (1 << 2);  // Toggle Pin 2 of Port 1
    delay(100000);
  }
  return 0;
}