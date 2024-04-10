//2024/4/9　sensorUNO用のスケッチ　TKJ

#include <Wire.h>
#include <SPI.h>
#include <Adafruit_BMP280.h>
#define BMP280_ADDRESS 0x76
Adafruit_BMP280 bmp;  // use I2C interface

void setup() {
  Serial.begin(9600);          
  while (!Serial) delay(100); 
  Serial.println(F("BMP280 Data Display"));

  unsigned status;
  status = bmp.begin(BMP280_ADDRESS);
  if (!status) {
    Serial.println(F("BMP280センサーが見つかりません。配線を確認してください。"));
    while (1) delay(10);  // BMP280センサーが見つかりません。
  }

  /* Default settings from datasheet. */
  bmp.setSampling(Adafruit_BMP280::MODE_NORMAL,     /* Operating Mode. */
                  Adafruit_BMP280::SAMPLING_X2,     /* Temp. oversampling */
                  Adafruit_BMP280::SAMPLING_X16,    /* Pressure oversampling */
                  Adafruit_BMP280::FILTER_X16,      /* Filtering. */
                  Adafruit_BMP280::STANDBY_MS_500); /* Standby time. */
}

void loop() {
  Serial.print(F("Temperature = "));
  Serial.print(bmp.readTemperature(),1);
  Serial.println(" °C");

  Serial.print(F("Pressure    = "));
  Serial.print(bmp.readPressure()/100,1);
  Serial.println(" Pa");
  
  Serial.println(" ");
  delay(2000); // 2秒待つ
}
