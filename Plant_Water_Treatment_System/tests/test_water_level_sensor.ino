// test_water_level_sensor.ino

const int water_trig_pin = 9;
const int water_echo_pin = 10;
unsigned long duration;
float distance;
float water_level;
float tank_height = 14.5;
const int low_water_threshold = 3;

void setup() {
    Serial.begin(9600);
    pinMode(water_trig_pin, OUTPUT);
    pinMode(water_echo_pin, INPUT);
}

void loop()
{
    digitalWrite(water_trig_pin, LOW);
    delay(2000);
    digitalWrite(water_trig_pin, HIGH);
    delay(10000);
    digitalWrite(water_trig_pin, LOW);

    duration = pulseIn(water_echo_pin, HIGH);  // Read the sensor signal
    distance = (duration * 0.0343) / 2;  // Convert to cm
    water_level = tank_height - distance;

    Serial.print("Water level: ");
    Serial.println(water_level);

    if (water_level >= low_water_threshold)
    {
        Serial.println("Enough water");
    }
    else
    {
        Serial.println("Water is too low");
    }
}