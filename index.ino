#include <Wire.h>

void setup() {
  Wire.begin();
  Serial.begin(9600);
  while (!Serial); // Wait for Serial to be ready
  Serial.println("I2C Scanner running...");
}

void loop() {
  byte error, address;
  Serial.println("Scanning...");
  for (address = 1; address < 127; address++) {
    Wire.beginTransmission(address);
    error = Wire.endTransmission();
    if (error == 0) {
      Serial.print("Found I2C device at 0x");
      Serial.println(address, HEX);
    }
  }
  delay(5000); // Repeat scan every 5 seconds
}
