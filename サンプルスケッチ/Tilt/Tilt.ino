//2024/4/9　sensorUNO用のスケッチ　TKJ

// スイッチを接続したピンの定義
const int switchPin3 = 7;
// LEDを接続したピンの定義
const int ledPin3 = 10; // LED3のピン番号

void setup() {
  // スイッチのピンを入力モードに設定し、プルアップする
  pinMode(switchPin3, INPUT_PULLUP);
  // LEDのピンを出力モードに設定
  pinMode(ledPin3, OUTPUT);
}

void loop() {
  // スイッチの状態を読み取る
  int switchState3 = digitalRead(switchPin3);

  // スイッチが押されている場合
  if (switchState3 == LOW) {
    // LED3を点灯
    digitalWrite(ledPin3, HIGH);
  } 
  // スイッチが離されている場合
  else {
    // LED3を消灯
    digitalWrite(ledPin3, LOW);
  }
}
