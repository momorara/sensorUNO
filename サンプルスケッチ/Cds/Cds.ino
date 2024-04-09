void setup() {
  // シリアル通信の初期化
  Serial.begin(9600);
}

void loop() {
  // A0ピンの値を読み取る
  int sensorValue = analogRead(A0);

  // シリアルモニタに値を表示
  Serial.print("Analog value: ");
  Serial.println(sensorValue);

  // 少し待つ
  delay(1000); // 1秒待つ
}
