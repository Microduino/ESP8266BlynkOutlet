#define BLYNK_PRINT Serial // Enables Serial Monitor

#include "user_def.h"
#include "WiFiBlynk.h"


void setup() {

  Serial.begin(9600); // See the connection status in Serial Monitor

  pinMode(outletPin, OUTPUT);
  digitalWrite(outletPin,LOW);

  // Set ESP8266 baud rate
  EspSerial.begin(115200);

  Blynk.begin(auth, wifi, SSID, PASS);

  while (Blynk.connect() == false) {
    // Wait until connected
  }

  delay(10);

  // pinMode(led_Pin, OUTPUT);
  // digitalWrite(led_Pin,HIGH);

}


void loop() {

  Blynk.run(); // All the Blynk Magic happens here...

}