#define IOT47_DS18B20_PIN 8  //nếu dùng các chân A thì A0=14 A1=15 A2=16 A3=17 A4=18 A5=19
#include "i47_async_ds18b20.h"

void DS18B20_CALLBACK(float temp)
{
  Serial.println(temp);
}

void setup() 
{
  Serial.begin(115200);
  pinMode(3,OUTPUT);
  ds18b20_begin(DS18B20_CALLBACK);
}
void loop() 
{
  ds18b20_read();
  delay(1000);
}
