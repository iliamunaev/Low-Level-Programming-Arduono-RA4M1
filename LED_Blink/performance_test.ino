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
