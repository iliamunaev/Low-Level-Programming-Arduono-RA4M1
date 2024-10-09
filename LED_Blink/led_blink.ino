/*
 * Arduino Program to Blink an LED Connected to Pin P102 Using Direct Register Access
 *
 * This script toggles an LED connected to pin P102 by directly manipulating the microcontroller's registers.
 * It sets the pin as an output and alternately turns the LED on and off every second.
 *
 * Note:
 * The code uses specific memory addresses for PORT1_PDR and PORT1_PODR.
 * Ensure that your microcontroller supports these addresses and that direct register access is appropriate.
 */
#include <Arduino.h>

#define PORT1_PDR (*(volatile uint16_t *)0x40040022)  // PDR address for setting the direction
#define PORT1_PODR (*(volatile uint16_t *)0x40040020) // PODR address for setting the output state

void setup() {
  Serial.begin(115200);
  // Set P102 as output (bit 2 of PORT1)
  PORT1_PDR |= (1 << 2);
}

void loop() {
  // Turn on LED at P102 (bit 2)
  PORT1_PODR |= (1 << 2);
  delay(1000);  // Wait for 1 second

  // Turn off LED at P102 (bit 2)
  PORT1_PODR &= ~(1 << 2);
  delay(1000);  // Wait for 1 second
}
