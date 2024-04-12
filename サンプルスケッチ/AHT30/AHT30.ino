//2024/4/10　sensorUNO用のスケッチ　TKJ
#include <Adafruit_AHTX0.h>
Adafruit_AHTX0 aht;

void setup() {
  Serial.begin(9600);          
  while (!Serial) delay(100); 
  Serial.println(F("AHT30 Data Display"));
  aht.begin(); // AHT21の初期化
}

void loop() {
  sensors_event_t humidity, temp;
  aht.getEvent(&humidity, &temp); // AHT21から湿度と温度の取得

  Serial.print(F("Temperature = "));
  Serial.print(temp.temperature,1);
  Serial.println(" °C");

  Serial.print(F("humidity    = "));
  Serial.print(humidity.relative_humidity,1);
  Serial.println(" %");

  Serial.println();

  delay(1000);
}