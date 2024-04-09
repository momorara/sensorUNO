// スイッチを接続したピンの定義
const int switchPin1 = 9;
const int switchPin2 = 8;
// LEDを接続したピンの定義
const int ledPin1 = 12; // LED1のピン番号
const int ledPin2 = 11; // LED2のピン番号

void setup() {
  // スイッチのピンを入力モードに設定
  pinMode(switchPin1, INPUT_PULLUP);
  pinMode(switchPin2, INPUT_PULLUP);
  // LEDのピンを出力モードに設定
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
}

void loop() {
  // スイッチ1の状態を読み取る
  int switchState1 = digitalRead(switchPin1);

  // スイッチ1がONの場合
  if (switchState1 == LOW) {
    // LED1を点灯
    digitalWrite(ledPin1, HIGH);
  } 
  // スイッチ1がOFFの場合
  else {
    // LED1を消灯
    digitalWrite(ledPin1, LOW);
  }

  // スイッチ2の状態を読み取る
  int switchState2 = digitalRead(switchPin2);

  // スイッチ2がONの場合
  if (switchState2 == LOW) {
    // LED2を点灯
    digitalWrite(ledPin2, HIGH);
  } 
  // スイッチ2がOFFの場合
  else {
    // LED2を消灯
    digitalWrite(ledPin2, LOW);
  }
}
