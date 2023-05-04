#define IOT47_DS18B20_PIN 8  //nếu dùng các chân A thì A0=14 A1=15 A2=16 A3=17 A4=18 A5=19
#include "i47_async_ds18b20.h"

void setup() 
{
  Serial.begin(115200);
  ds18b20_begin();
}
void loop() 
{
  Serial.println(ds18b20_read_and_wait_finish());
  delay(1000);
}
