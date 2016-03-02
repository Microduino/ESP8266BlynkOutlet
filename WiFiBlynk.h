#include <ESP8266_HardSer.h>
#include <BlynkSimpleShieldEsp8266_HardSer.h>

// Set ESP8266 Serial object
#define EspSerial Serial1
#define outletPin 6

ESP8266 wifi(EspSerial);

WidgetLED ledState(V1);


BLYNK_READ(V0) {
  if(digitalRead(outletPin)) {
    Blynk.virtualWrite(V0, "ON");
    ledState.on();
  } else {
    Blynk.virtualWrite(V0, "OFF");
    ledState.off();
  }
}
