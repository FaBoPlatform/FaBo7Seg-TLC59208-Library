/*************************************************** 
 This is an Example for the FaBo 7Seg I2C Brick.

  http://fabo.io/211.html

 author:FaBo<info@fabo.io>
 maintainer:Hideki Yamauchi<yamauchi@fabo.io>

 Released under APACHE LICENSE, VERSION 2.0
  http://www.apache.org/licenses/
 ****************************************************/

#include <Wire.h>
#include <FaBo7Seg_TLC59208.h>

FaBo7Seg_TLC59208 fabo_7seg;

void setup() {
  Serial.begin(9600);
  Serial.println("RESET");
  Serial.println();

  Serial.println("configuring device.");
  if (fabo_7seg.configure()) {
    Serial.println("configured FaBo 7Seg Brick");
  } else {
    Serial.println("device error");
    while(1);
  }
}

void loop() {
  for (int i = 0; i<10; i++) {
    fabo_7seg.showNumber(i); // show a number
    delay(1000);
  }
}
