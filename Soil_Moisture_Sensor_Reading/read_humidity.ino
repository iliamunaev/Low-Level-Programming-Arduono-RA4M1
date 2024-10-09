/*
 * Arduino Program to Read and Display Soil Humidity Percentage Using Calibrated Sensor Data
 *
 * This script reads the analog value from a soil moisture sensor connected to analog pin A0.
 * It maps the sensor reading to a humidity percentage based on calibration values
 * for dry and wet soil and prints the result to the Serial Monitor.
 *
 * Calibration Data:
 * Dry Soil Reading (0% humidity): dry = 891
 * Wet Soil Reading (100% humidity): wet = 496
 */
const int dry = 891;
const int wet = 496;

void setup()
{
  Serial.begin(9600);
}

void loop()
{
    // Read the analog value from analog pin A0
    int sensor_value = analogRead(A0);

    // Map the sensor value to humidity percentage
    float humidity = map(sensor_value, dry, wet, 0, 100);

    // Ensure humidity is within 0% to 100%
    if (humidity > 100.0)
    {
      humidity = 100.0;
    }
    else if (humidity < 0.0)
    {
      humidity = 0.0;
    }

    // Print humidity to the Serial Monitor
    Serial.print("Humidity: ");
    Serial.print(humidity, 1);
    Serial.println("%");
    delay(2000);
}