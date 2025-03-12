#define soilMoisturePin A0  // Soil moisture sensor pin
#define relayPin 7          // Relay control pin

void setup() {
  Serial.begin(9600);
  pinMode(relayPin, OUTPUT);
}

void loop() {
  int moistureLevel = analogRead(soilMoisturePin);  // Read moisture level
  Serial.print("Soil Moisture: ");
  Serial.println(moistureLevel);

  if (moistureLevel < 500) {  // If soil is dry, activate the relay
    digitalWrite(relayPin, HIGH);  // Turn on the water pump
    Serial.println("Watering the plant...");
  } else {
    digitalWrite(relayPin, LOW);  // Turn off the water pump
    Serial.println("Soil is wet, no need to water.");
  }
  delay(10000);  // Wait 10 seconds before checking again
}
