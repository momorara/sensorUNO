//2024/4/9　sensorUNO用のスケッチ　TKJ

const int trigPin = 5;  // Trigピン
const int echoPin = 4;  // Echoピン
// スイッチを接続したピンの定義
const int switchPin1 = 9;

void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  // スイッチのピンを入力モードに設定
  pinMode(switchPin1, INPUT_PULLUP);
}

void loop() {
  //sw1の押下を待つ　
  int switchState1 = digitalRead(switchPin1);
  while (switchState1 == HIGH) {
    // スイッチの状態を再度読み取る
    switchState1 = digitalRead(switchPin1);
  }

  long duration, distance;

  // Trigピンを10マイクロ秒だけHIGHにする
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Echoピンからパルスの長さを読み取る
  duration = pulseIn(echoPin, HIGH);

  // 距離を計算する（音速は340m/sと仮定）
  distance = duration * 0.034 / 2;

  // シリアルモニタに距離を表示する
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  delay(500);  // 0.5秒待つ
}
