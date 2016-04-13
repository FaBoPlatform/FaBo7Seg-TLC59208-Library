/**
 @file FaBo7Seg_TLC59208.h
 @brief This is a library for the FaBo 7Seg I2C Brick.

   http://fabo.io/211.html

   Released under APACHE LICENSE, VERSION 2.0

   http://www.apache.org/licenses/

 @author FaBo<info@fabo.io>
*/

#ifndef FABO7SEG_TLC59208_H
#define FABO7SEG_TLC59208_H

#include <Arduino.h>
#include <Wire.h>

#define TLC59208_SLAVE_ADDRESS 0x20 ///< Default I2C slave address
#define TLC59208_PWM_VALUE 0x02 ///< PWM output value

/// @name LED点灯パターン1
/// LED点灯パターン定義(数字)
/// @{
#define TLC59208_LED_0 0x77 ///< 0
#define TLC59208_LED_1 0x14 ///< 1
#define TLC59208_LED_2 0xB3 ///< 2
#define TLC59208_LED_3 0xB6 ///< 3
#define TLC59208_LED_4 0xD4 ///< 4
#define TLC59208_LED_5 0xE6 ///< 5
#define TLC59208_LED_6 0xE7 ///< 6
#define TLC59208_LED_7 0x74 ///< 7
#define TLC59208_LED_8 0xF7 ///< 8
#define TLC59208_LED_9 0xF6 ///< 9
/// @}

/// @name LED点灯パターン2
/// LED点灯パターン定義(アルファベット)
/// @{
#define TLC59208_LED_A 0xB7 ///< A
#define TLC59208_LED_B 0xC7 ///< B
#define TLC59208_LED_C 0x63 ///< C
#define TLC59208_LED_D 0x97 ///< D
#define TLC59208_LED_E 0xE3 ///< E
#define TLC59208_LED_F 0xE1 ///< F
#define TLC59208_LED_H 0xD5 ///< H
/// @}

/// @name LED点灯パターン3
/// LED点灯パターン定義(そのた)
/// @{
#define TLC59208_LED_DP 0x08 ///< Dot
#define TLC59208_LED_OFF 0x00 ///< OFF
/// @}

/// @name PWMレジスタ
/// @{
#define TLC59208_LED_PWM0 0x01
#define TLC59208_LED_PWM1 0x02
#define TLC59208_LED_PWM2 0x04
#define TLC59208_LED_PWM3 0x08
#define TLC59208_LED_PWM4 0x10
#define TLC59208_LED_PWM5 0x20
#define TLC59208_LED_PWM6 0x40
#define TLC59208_LED_PWM7 0x80
/// @}

/// @name 7Segment PIN assign
/// @{
#define TLC59208_LED_PIN_A 0x20
#define TLC59208_LED_PIN_B 0x10
#define TLC59208_LED_PIN_C 0x04
#define TLC59208_LED_PIN_D 0x02
#define TLC59208_LED_PIN_E 0x01
#define TLC59208_LED_PIN_F 0x40
#define TLC59208_LED_PIN_G 0x80
#define TLC59208_LED_PIN_DP 0x08
/// @}

/**
 * @class FaBo7Seg_TLC59208
 * @brief FaBo 7Seg I2C Controll class
 */
class FaBo7Seg_TLC59208 {
  public:
    FaBo7Seg_TLC59208(uint8_t addr = TLC59208_SLAVE_ADDRESS);
    FaBo7Seg_TLC59208(uint8_t addr1, uint8_t addr2);
    FaBo7Seg_TLC59208(uint8_t addr1, uint8_t addr2, uint8_t addr3);
    FaBo7Seg_TLC59208(uint8_t addr1, uint8_t addr2, uint8_t addr3, uint8_t addr4);
    bool configure(void);
    void showNumber(uint8_t number, uint8_t digit = 0);
    void clearNumber(uint8_t digit = 0);
    void showNumberFullDigit(uint8_t number);
    void showDot(uint8_t digit = 0);
    void clearDot(uint8_t digit = 0);
    void showPattern(uint8_t data, uint8_t digit = 0);
  private:
    uint8_t _i2caddr[4];
    uint8_t _digits;
    void writeI2c(uint8_t address, uint8_t data);
};

#endif // FABO7SEG_TLC59208_H
