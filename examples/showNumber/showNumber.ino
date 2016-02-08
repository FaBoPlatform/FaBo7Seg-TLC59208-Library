//
// FaBo Brick Example
//
// FaBo 7Seg TLC59208
//

#include <Wire.h>
#include <FaBo7Seg_TLC59208.h>

FaBo7Seg_TLC59208 fabo_7seg;

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
  for (int i = 0; i<10; i++) {
    Serial.println(i);
    fabo_7seg.showNumber(i); // 0〜9を順番に表示
    delay(500);
  }
}
