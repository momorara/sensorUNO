//2024/4/9　sensorUNO用のスケッチ　TKJ

// LEDを接続したピンの定義
const int ledPins[] = {12, 11, 10}; // LEDのピン番号配列

void setup() {
  // LEDのピンを出力モードに設定
  for (int i = 0; i < sizeof(ledPins) / sizeof(ledPins[0]); i++) {
    pinMode(ledPins[i], OUTPUT);
  }
}

void loop() {
  for (int j = 0; j < 3; j++) {
    // LEDを順に点滅させる
    for (int i = 0; i < sizeof(ledPins) / sizeof(ledPins[0]); i++) {
      digitalWrite(ledPins[i], HIGH); // LEDを点灯
      delay(500); // 0.5秒待つ
      digitalWrite(ledPins[i], LOW); // LEDを消灯
      delay(200); // 0.5秒待つ
    }
  }
}
