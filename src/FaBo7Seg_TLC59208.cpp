/*************************************************** 
 This is a library for the FaBo 7Seg I2C Brick.

  http://fabo.io/211.html

 author:FaBo<info@fabo.io>
 maintainer:Hideki Yamauchi<yamauchi@fabo.io>

 Released under APACHE LICENSE, VERSION 2.0
  http://www.apache.org/licenses/
 ****************************************************/

#include "FaBo7Seg_TLC59208.h"

FaBo7Seg_TLC59208::FaBo7Seg_TLC59208(uint8_t addr) {
  _i2caddr[0] = addr;
  _digits = 1;
  Wire.begin();
}

FaBo7Seg_TLC59208::FaBo7Seg_TLC59208(uint8_t addr1, uint8_t addr2) {
  _i2caddr[0] = addr1;
  _i2caddr[1] = addr2;
  _digits = 2;
  Wire.begin();
}

FaBo7Seg_TLC59208::FaBo7Seg_TLC59208(uint8_t addr1, uint8_t addr2, uint8_t addr3) {
  _i2caddr[0] = addr1;
  _i2caddr[1] = addr2;
  _i2caddr[2] = addr3;
  _digits = 3;
  Wire.begin();
}

FaBo7Seg_TLC59208::FaBo7Seg_TLC59208(uint8_t addr1, uint8_t addr2, uint8_t addr3, uint8_t addr4) {
  _i2caddr[0] = addr1;
  _i2caddr[1] = addr2;
  _i2caddr[2] = addr3;
  _i2caddr[3] = addr4;
  _digits = 4;
  Wire.begin();
}

bool FaBo7Seg_TLC59208::configure(void) {
  uint8_t i;
  uint8_t ret = 1;
  for (i=0; i<_digits; i++) {
    Wire.beginTransmission(_i2caddr[i]);
    Wire.write(0x80); // Control: Auto-Increment on All Registers
    Wire.write(0x81); // 00h: MODE1
    Wire.write(0x03); // 01h: MODE2
    Wire.write(0x00); // 02h: PWM0
    Wire.write(0x00); // 03h: PWM1
    Wire.write(0x00); // 04h: PWM2
    Wire.write(0x00); // 05h: PWM3
    Wire.write(0x00); // 06h: PWM4
    Wire.write(0x00); // 07h: PWM5
    Wire.write(0x00); // 08h: PWM6
    Wire.write(0x00); // 09h: PWM7
    Wire.write(0xFF); // 0Ah: GRPPWM
    Wire.write(0x00); // 0Bh: GRPFREQ
    Wire.write(0xAA); // 0Ch: LEDOUT0
    Wire.write(0xAA); // 0Dh: LEDOUT1
    Wire.write(0x92); // 0Eh: SUBADR1
    Wire.write(0x94); // 0Fh: SUBADR2
    Wire.write(0x98); // 10h: SUBADR3
    Wire.write(0xD0); // 11h: ALLCALLADR
    ret &= ! Wire.endTransmission();
  }
  return ret;
}

void FaBo7Seg_TLC59208::showNumber(uint8_t number, uint8_t digit) {
  switch (number) {
    case 0:
      writeI2c(_i2caddr[digit], TLC59208_LED_0);
    break;
    case 1:
      writeI2c(_i2caddr[digit], TLC59208_LED_1);
    break;
    case 2:
      writeI2c(_i2caddr[digit], TLC59208_LED_2);
    break;
    case 3:
      writeI2c(_i2caddr[digit], TLC59208_LED_3);
    break;
    case 4:
      writeI2c(_i2caddr[digit], TLC59208_LED_4);
    break;
    case 5:
      writeI2c(_i2caddr[digit], TLC59208_LED_5);
    break;
    case 6:
      writeI2c(_i2caddr[digit], TLC59208_LED_6);
    break;
    case 7:
      writeI2c(_i2caddr[digit], TLC59208_LED_7);
    break;
    case 8:
      writeI2c(_i2caddr[digit], TLC59208_LED_8);
    break;
    case 9:
      writeI2c(_i2caddr[digit], TLC59208_LED_9);
    break;
    default:
      writeI2c(_i2caddr[digit], TLC59208_LED_OFF);
    break;
  }
}

void FaBo7Seg_TLC59208::clearNumber(uint8_t digit) {
  writeI2c(_i2caddr[digit], TLC59208_LED_OFF);
}

void FaBo7Seg_TLC59208::showNumberFullDigit(uint8_t number) {
  uint8_t i;
  for (i=0; i<_digits; i++) {
    if (number <= 0) {
      clearNumber(i);
    } else {
      showNumber(number % 10, i);
    }
    number /= 10;
  }
}

void FaBo7Seg_TLC59208::showDot(uint8_t digit) {
  Wire.beginTransmission(_i2caddr[digit]);
  Wire.write(0x05); // set only PWM3
  Wire.write(TLC59208_PWM_VALUE); // DP on
  Wire.endTransmission();
}

void FaBo7Seg_TLC59208::clearDot(uint8_t digit) {
  Wire.beginTransmission(_i2caddr[digit]);
  Wire.write(0x05); // set only PWM3
  Wire.write(TLC59208_LED_OFF); // DP off
  Wire.endTransmission();
}

void FaBo7Seg_TLC59208::showPattern(uint8_t data, uint8_t digit) {
  writeI2c(_i2caddr[digit], data);
}

////////////////////////////////////////////////////////////////

void FaBo7Seg_TLC59208::writeI2c(uint8_t address, uint8_t data) {
  uint8_t i;
  Wire.beginTransmission(address);
  Wire.write(0xA2);// Control: Auto-Increment on PWM Registers
  for (i=0; i<8; i++) {
    if (bitRead(data, i)) {
      Wire.write(TLC59208_PWM_VALUE);
    } else {
      Wire.write(TLC59208_LED_OFF);
    }
  }
  Wire.endTransmission();
}
