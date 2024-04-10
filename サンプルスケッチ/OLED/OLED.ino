//2024/4/9　sensorUNO用のスケッチ　TKJ

#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // 画面の幅（ピクセル）
#define SCREEN_HEIGHT 64 // 画面の高さ（ピクセル）
#define OLED_RESET    -1 // RESETピンが未使用の場合は-1を指定

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void setup() {
  // I2Cディスプレイの初期化
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // 0x3CはディスプレイのI2Cアドレス
    Serial.println(F("SSD1306の初期化に失敗しました"));
    for(;;);
  }
  
  // ディスプレイのクリア
  display.clearDisplay();
  
  // テキストの表示
  display.setTextSize(3); // テキストサイズ
  display.setTextColor(SSD1306_WHITE); // テキストの色（白）
  display.setCursor(0, 0); // テキストの位置
  display.println(F("Hello, World!"));
  
  // ディスプレイに反映
  display.display();
  
  delay(2000); // 2秒待つ
}

void loop() {
  // カウントダウン
  for (int i = 10; i >= 0; --i) {
    // ディスプレイのクリア
    display.clearDisplay();
  
    // テキストの表示
    display.setTextSize(7); // テキストサイズ
    display.setTextColor(SSD1306_WHITE); // テキストの色（白）
    display.setCursor(0, 10); // テキストの位置
    display.print(i); // カウントダウンの数字を表示
    // ディスプレイに反映
    display.display();
    
    delay(1000); // 1秒待つ
  }
  
  // ディスプレイのクリア
  display.clearDisplay();
  
  // テキストの表示
  display.setTextSize(2); // テキストサイズ
  display.setTextColor(SSD1306_WHITE); // テキストの色（白）
  display.setCursor(10, 30); // テキストの位置
  display.println(F("good bye"));
  // ディスプレイに反映
  display.display();
  
  delay(4000); // 2秒待つ
  
  // ディスプレイのクリア
  display.clearDisplay();
  // ディスプレイに反映
  display.display();

  // プログラムを停止
  while(1);
}
