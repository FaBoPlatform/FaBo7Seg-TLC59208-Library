//
// FaBo Brick Example
//
// FaBo 7Seg TLC59208
//

#include <Wire.h>
#include <FaBo7Seg_TLC59208.h>

FaBo7Seg_TLC59208 fabo_7seg;

void setup() {
  // デバイス初期化
  fabo_7seg.init();
}

void loop() {
  fabo_7seg.showPattern(TLC59208_LED_PIN_A|TLC59208_LED_PIN_G|TLC59208_LED_PIN_D);
  delay(1000);

  for (int i = 0; i<10; i++) {
    fabo_7seg.showPattern(TLC59208_LED_PWM5);
    delay(100);
    fabo_7seg.showPattern(TLC59208_LED_PWM4);
    delay(100);
    fabo_7seg.showPattern(TLC59208_LED_PWM2);
    delay(100);
    fabo_7seg.showPattern(TLC59208_LED_PWM1);
    delay(100);
    fabo_7seg.showPattern(TLC59208_LED_PWM0);
    delay(100);
    fabo_7seg.showPattern(TLC59208_LED_PWM6);
    delay(100);
    fabo_7seg.showPattern(TLC59208_LED_PWM5);
    delay(100);
    fabo_7seg.showPattern(TLC59208_LED_PWM4);
    delay(100);
    fabo_7seg.showPattern(TLC59208_LED_PWM2);
    delay(100);
    fabo_7seg.showPattern(TLC59208_LED_PWM1);
    delay(100);
    fabo_7seg.showPattern(TLC59208_LED_PWM0);
    delay(100);
    fabo_7seg.showPattern(TLC59208_LED_PWM6);
    delay(100);
    fabo_7seg.showPattern(TLC59208_LED_PWM5);
    delay(100);
    fabo_7seg.showPattern(TLC59208_LED_OFF);
    delay(100);

    fabo_7seg.showNumber(i);
    delay(1000);
    fabo_7seg.showDot();
    delay(1000);
    fabo_7seg.showPattern(TLC59208_LED_OFF);
    delay(100);
  }
}
