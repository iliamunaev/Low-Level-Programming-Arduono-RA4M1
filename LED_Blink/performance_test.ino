/*
 * Arduino Program to Compare Execution Time of digitalWrite() vs Direct Register Access
 *
 * This script measures and compares the execution time of turning on an LED using:
 * 1. The standard digitalWrite() function.
 * 2. Direct manipulation of the microcontroller's registers.
 *
 * It prints the execution time of each method to the Serial Monitor every 2 seconds.
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
  unsigned long startTime, endTime, elapsedTime;

  // Measure the time for digitalWrite()
  startTime = micros();
  digitalWrite(LED_BUILTIN, HIGH);
  endTime = micros();
  elapsedTime = endTime - startTime;

  Serial.print("digitalWrite() execution time: ");
  Serial.print(elapsedTime);
  Serial.println(" microseconds");

  delay(1000);

  // Measure the time our custom code
  startTime = micros();
  PORT1_PODR |= (1 << 2); // Turn on LED
  endTime = micros();
  elapsedTime = endTime - startTime;

  Serial.print("Custom code execution time: ");
  Serial.print(elapsedTime);
  Serial.println(" microseconds");

  delay(1000);
}
