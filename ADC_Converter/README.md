# ADC Converter (Analog to Binary)
 
 The program converts an analog input value from an ADC into its binary representation
 based on specified bit resolution and voltage range. 
 
 It takes command-line arguments
 for the number of bits, lowest voltage, highest voltage, and the analog input value.
 The binary representation of the converted value is then printed to the console.
 
 ### Usage:
Compile:  
  ```
gcc adc_converter.c -o adc_converter -lm
```
Run:

```
./adc_converter <bits> <lowest_voltage> <highest_voltage> <analog_input_value>
```
Example:
```
./adc_converter 10 0 5 3
```
Output: 
```
Binary Representation: 1001100101
```