# Bare-Metal LED Blink Project for Renesas RA4M1 Microcontroller
This project demonstrates how to configure a GPIO pin on the Renesas RA4M1 microcontroller to blink an LED using bare-metal programming. The pin being controlled is Port 1, Pin 2 (P102), and the project toggles this pin between high and low states with a simple delay function.

## Project Overview
- **Microcontroller:** Renesas RA4M1
- **Board:** Arduino UNO R4 WiFi (Renesas RA4M1)
- **Pin Used:** Port 1, Pin 2 (P102)
- **Functionality:** The code sets P102 as an output and toggles it between high (1) and low (0), creating an LED blink effect. A software delay is used to control the blink interval.
- **Programming Language:** C
- **Toolchain:** GCC for ARM