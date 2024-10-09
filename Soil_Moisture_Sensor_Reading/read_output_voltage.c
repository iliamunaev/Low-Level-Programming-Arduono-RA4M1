/*
* Quantization Level = 2 power of ADC bits
* in owr case is 10-bits ADC
* Voltage range = 5 (0 - 5 V)
*/
float quantization_level = pow(2, 10) - 1; // 1023
short voltage_range = 5;

void setup()
{
  Serial.begin(9600);
}

void loop()
{
    // Read humidity sensor from analog pin A0
    int sensor_value = analogRead(A0);

    // Voltage resolution = Voltage range / Quantization Level
    float voltage_resolution = sensor_value * (voltage_range / quantization_level);
    
    // Print voltage to Serial Monitor
    Serial.println(voltage_resolution, 3);
    delay(2000);
}