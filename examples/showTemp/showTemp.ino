//
// FaBo Brick Example
//
// FaBo 7Seg TLC59208
//

#include <Wire.h>
#include <FaBo7Seg_TLC59208.h>

FaBo7Seg_TLC59208 fabo_7seg(0x20, 0x21);

int temp_pin = A0; // Analog Temperature Brickのポート

void setup() {
  Serial.begin(9600); // シリアルの開始
  Serial.println();
  Serial.println("RESET");

  // デバイス初期化
  fabo_7seg.init();
}

void loop() {
  unsigned int temp_value;

  // Analog Temperature Brickで温度を計測
  temp_value = analogRead(temp_pin);
  temp_value = map(temp_value,0,1023,0,5000);
  temp_value = map(temp_value,300,1600,-30,100);
  Serial.println(temp_value);

  // 7Segment LED Brickで温度を表示
  fabo_7seg.showNumberFullDigit(temp_value);
  delay(500);

  fabo_7seg.showDot();
  delay(500);
  fabo_7seg.clearDot();
  delay(500);

}
