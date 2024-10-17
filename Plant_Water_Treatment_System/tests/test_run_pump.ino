// test_run_pump.ino

const int relay_pin = 7;  // Pin connected to IN pin on relay module

void setup() {
    Serial.begin(9600);
    pinMode(relay_pin, OUTPUT);
}

void loop() {
    // Turn the pump ON
    digitalWrite(relay_pin, HIGH);
    Serial.println("Pump ON");
    delay(5000);  // Pump is ON for 5 seconds

    // Turn the pump OFF
    digitalWrite(relay_pin, LOW);
    Serial.println("Pump OFF");
    delay(5000);  // Pump is OFF for 5 seconds
}
