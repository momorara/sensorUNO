//2024/4/10　sensorUNO用のスケッチ　TKJ

//ssd1306の設定
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#define SCREEN_WIDTH 128 // 画面の幅（ピクセル）
#define SCREEN_HEIGHT 64 // 画面の高さ（ピクセル）
#define OLED_RESET    -1 // RESETピンが未使用の場合は-1を指定
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

//AHT30の設定
#include <Adafruit_AHTX0.h>
Adafruit_AHTX0 aht;

//BMP280の設定
#include <Wire.h>
#include <SPI.h>
#include <Adafruit_BMP280.h>
#define BMP280_ADDRESS 0x76
Adafruit_BMP280 bmp;  // use I2C interface

// LEDを接続したピンの定義
const int ledPins[] = {12, 11, 10}; // LEDのピン番号配列
// スイッチを接続したピンの定義
const int switchPin1 = 9;
const int switchPin2 = 8;
const int switchPin3 = 7;

void setup() {
  // LEDのピンを出力モードに設定
  for (int i = 0; i < sizeof(ledPins) / sizeof(ledPins[0]); i++) {
    pinMode(ledPins[i], OUTPUT);
  }
  // I2Cディスプレイの初期化
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // 0x3CはディスプレイのI2Cアドレス
    Serial.println(F("SSD1306の初期化に失敗しました"));
    for(;;);
  }  
  // OLEDディスプレイのクリア
  display.clearDisplay();
  // テキスト表示の基本設定
  display.setTextSize(3); // テキストサイズ
  display.setTextColor(SSD1306_WHITE); // テキストの色（白）
  display.setCursor(0, 0); // テキストの位置
  //シリアルモニタ設定
  Serial.begin(9600);          
  while (!Serial) delay(100); // Clear the serial monitor
  Serial.println("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");

  // AHT21の初期化
  aht.begin(); 
  Serial.println(F("AHT30 Data Display"));

  //BMP280の初期化
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

  // スイッチのピンを入力モードに設定
  pinMode(switchPin1, INPUT_PULLUP);
  pinMode(switchPin2, INPUT_PULLUP);
  pinMode(switchPin3, INPUT_PULLUP);
}

void loop() {
  
  display.println(F("start!"));
  display.display();
  
  //LEDのテスト
  for (int j = 0; j < 3; j++) {
    // LEDを順に点滅させる
    for (int i = 0; i < sizeof(ledPins) / sizeof(ledPins[0]); i++) {
      digitalWrite(ledPins[i], HIGH); // LEDを点灯
      delay(100); // 0.1秒待つ
      digitalWrite(ledPins[i], LOW); // LEDを消灯
      delay(100); // 0.1秒待つ
    }
  }

  // AHT30のテスト
  display.clearDisplay();
  display.setCursor(0, 0); // テキストの位置
  display.setTextSize(2); // テキストサイズ
  display.println(F("Temp &"));
  display.println(F(""));
  display.println(F("Humidity"));
  display.display();

  // AHT30から湿度と温度の取得
  sensors_event_t humidity, temp;
  aht.getEvent(&humidity, &temp); 

  Serial.print(F("Temperature = "));
  Serial.print(temp.temperature,1);
  Serial.println(" °C");
  Serial.print(F("humidity    = "));
  Serial.print(humidity.relative_humidity,1);
  Serial.println(" %");
  Serial.println();
  delay(1000);

  // BMP280のテスト
  display.clearDisplay();
  display.setCursor(0, 0); // テキストの位置
  display.setTextSize(2); // テキストサイズ
  display.println(F("Pressure"));
  display.println(F(""));
  display.display();

  Serial.print(F("PBMP280 Data Display"));
  Serial.println();
  Serial.print(F("Pressure    = "));
  Serial.print(bmp.readPressure()/100,1);
  Serial.println(" hPa");
  Serial.println();
  delay(1000); // 1秒待つ

  // Cdsのテスト
  display.clearDisplay();
  display.setCursor(0, 0); // テキストの位置
  display.setTextSize(2); // テキストサイズ
  display.println(F("Cds"));
  display.println(F(""));
  display.display();
  // シリアルモニタに値を表示
  Serial.println("Cds");
  Serial.print("Analog value: ");
  // A0ピンの値を読み取る
  int sensorValue = analogRead(A0);
  Serial.println(sensorValue);
  delay(1000); // 1秒待つ
  for (int j = 0; j < 5; j++) {
    Serial.print("Analog value: ");
    Serial.println(analogRead(A0));
    delay(1000); // 1秒待つ
  }
  Serial.println(" ");
  delay(1000); // 1秒待つ

  //swのテスト　OLEDにsw1と表示
  Serial.println(F("SW-1"));
  display.clearDisplay();
  display.setCursor(0, 0); // テキストの位置
  display.setTextSize(2); // テキストサイズ
  display.println(F("SW-1"));
  display.println(F(""));
  display.display();
  //sw1を押下すると　
  // スイッチが押されるまで待つ
  // スイッチ1の状態を読み取る
  int switchState1 = digitalRead(switchPin1);
  while (switchState1 == HIGH) {
    // スイッチの状態を再度読み取る
    switchState1 = digitalRead(switchPin1);
  }

  //OLEDにsw2と表示
  Serial.println(F("SW-2"));
  display.clearDisplay();
  display.setCursor(0, 0); // テキストの位置
  display.setTextSize(2); // テキストサイズ
  display.println(F("SW-2"));
  display.println(F(""));
  display.display();
  //sw2を押下すると　
  // スイッチ2の状態を読み取る
  int switchState2 = digitalRead(switchPin2);
  while (switchState2 == HIGH) {
    // スイッチの状態を再度読み取る
    switchState2 = digitalRead(switchPin2);
  }
  
  //OLEDにtiltと表示
  Serial.println(F("Tilt"));
  display.clearDisplay();
  display.setCursor(0, 0); // テキストの位置
  display.setTextSize(2); // テキストサイズ
  display.println(F("tilt"));
  display.println(F(""));
  display.display();
  //傾けると 
  // スイッチ3の状態を読み取る
  int switchState3 = digitalRead(switchPin3);
  while (switchState3 == HIGH) {
    // スイッチの状態を再度読み取る
    switchState3 = digitalRead(switchPin3);
  }

  //endと表示して、3秒後に消える
  Serial.println(F("END of Test"));
  // プログラムを終了する
  display.clearDisplay();
  display.println(F("ENDofTest"));
  display.display();
  delay(3000); // 1秒待つ
  display.clearDisplay();
  display.display();
  
  exit(0);
}
