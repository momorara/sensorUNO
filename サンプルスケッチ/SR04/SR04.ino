const int trigPin = 5; // Trigピン
const int echoPin = 4; // Echoピン

void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
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
  
  delay(1000); // 1秒待つ
}
