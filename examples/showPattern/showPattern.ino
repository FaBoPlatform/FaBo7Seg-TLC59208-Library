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
  fabo_7seg.showPattern(TLC59208_LED_PIN_A|TLC59208_LED_PIN_G|TLC59208_LED_PIN_D);
  delay(1000);

  for (int i = 0; i<10; i++) {
    fabo_7seg.showPattern(TLC59208_LED_PWM5);
    delay(50);
    fabo_7seg.showPattern(TLC59208_LED_PWM4);
    delay(50);
    fabo_7seg.showPattern(TLC59208_LED_PWM2);
    delay(50);
    fabo_7seg.showPattern(TLC59208_LED_PWM1);
    delay(50);
    fabo_7seg.showPattern(TLC59208_LED_PWM0);
    delay(50);
    fabo_7seg.showPattern(TLC59208_LED_PWM6);
    delay(50);
    fabo_7seg.showPattern(TLC59208_LED_PWM5);
    delay(50);
    fabo_7seg.showPattern(TLC59208_LED_PWM4);
    delay(50);
    fabo_7seg.showPattern(TLC59208_LED_PWM2);
    delay(50);
    fabo_7seg.showPattern(TLC59208_LED_PWM1);
    delay(50);
    fabo_7seg.showPattern(TLC59208_LED_PWM0);
    delay(50);
    fabo_7seg.showPattern(TLC59208_LED_PWM6);
    delay(50);
    fabo_7seg.showPattern(TLC59208_LED_PWM5);
    delay(50);
    fabo_7seg.showPattern(TLC59208_LED_OFF);
    delay(50);

    fabo_7seg.showNumber(i);
    delay(1000);
    fabo_7seg.showDot();
    delay(1000);
    fabo_7seg.showPattern(TLC59208_LED_OFF);
    delay(100);
  }
}
