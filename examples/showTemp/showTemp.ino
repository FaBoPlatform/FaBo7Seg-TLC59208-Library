//
// FaBo Brick Example
//
// FaBo 7Seg TLC59208
//

#include <Wire.h>
#include <FaBo7Seg_TLC59208.h>

// FaBo 7Seg Brickを2個接続
FaBo7Seg_TLC59208 fabo_7seg(0x20, 0x21);

int temp_pin = A0; // Analog Temperature Brickのポート

void setup() {
  Serial.begin(9600); // シリアルの開始
  Serial.println();
  Serial.println("RESET");

  // デバイス初期化
  Serial.println("Checking I2C device...");
  if (fabo_7seg.searchDevice()) {
    Serial.println("configuring 7Seg TLC59208");
    fabo_7seg.configure();
  } else {
    Serial.println("device error");
    while(1);
  }
}

void loop() {
  uint16_t temp_value = 0;

  // 計測中にドットを表示
  fabo_7seg.showDot();

  // Analog Temperature Brickで温度を計測
  for (int i=0;i<100;i++) {
    temp_value += analogRead(temp_pin);
    delay(10);
  }
  temp_value /= 100;
  temp_value = map(temp_value,0,1023,0,5000);
  temp_value = map(temp_value,300,1600,-30,100);
  Serial.print("Temp: ");
  Serial.println(temp_value);

  // 7Segment LED Brickで温度を表示
  fabo_7seg.showNumberFullDigit(temp_value);
  delay(1000);
}
