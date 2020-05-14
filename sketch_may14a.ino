/*
  Arduino Slave for Raspberry Pi Master
  i2c_slave_ard.ino
  Connects to Raspberry Pi via I2C
  
  DroneBot Workshop 2019
  https://dronebotworkshop.com
*/
 
// Include the Wire library for I2C
#include <Wire.h>
 
void setup() {
  // Join I2C bus as slave with address 8
  Wire.begin(0x8);
  
  // Call receiveEvent when data received                
  Wire.onReceive(receiveEvent);
  
  Serial.begin(9600);
}
 
// Function that executes whenever data is received from master
void receiveEvent(int howMany) {
  while (Wire.available()) { // loop through all but the last
    char c = Wire.read(); // receive byte as a character
    if (c == 1) {
      Serial.print("too dark\n");
    }
    else if (c == 2) {
      Serial.print("dark\n");
    }
    else if (c == 3) {
      Serial.print("medium\n");
    }
    else if (c == 4) {
      Serial.print("bright\n");
    }
    else if (c == 5) {
      Serial.print("too bright\n");
    }
  }
}
void loop() {
  delay(100);
}
