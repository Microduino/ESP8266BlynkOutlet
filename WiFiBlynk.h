#include <ESP8266_HardSer.h>
#include <BlynkSimpleShieldEsp8266_HardSer.h>

// Set ESP8266 Serial object
#define EspSerial Serial1
#define outletPin 6
//#define led_Pin 5

ESP8266 wifi(EspSerial);

WidgetLED ledState(V1);


BLYNK_READ(V0) {
  if(digitalRead(outletPin)) {//如果检测到引脚为高电平
    Blynk.virtualWrite(V0, "ON");//设置状态为ON
    ledState.on();//设置手机上的小灯亮起
  } else {//否则
    Blynk.virtualWrite(V0, "OFF");//设置状态为OFF
    ledState.off();//设置手机上的小灯熄灭
  }
}
