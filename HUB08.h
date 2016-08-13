/*********************************************************************
This is a library for our Monochrome OLEDs based on SSD1306 drivers

  Pick one up today in the adafruit shop!
  ------> http://www.adafruit.com/category/63_98

These displays use SPI to communicate, 4 or 5 pins are required to
interface

Adafruit invests time and resources providing this open source code,
please support Adafruit and open-source hardware by purchasing
products from Adafruit!

Written by Limor Fried/Ladyada  for Adafruit Industries.
BSD license, check license.txt for more information
All text above, and the splash screen must be included in any redistribution
*********************************************************************/
#ifndef _HUB08_H_
#define _HUB08_H_

#if ARDUINO >= 100
 #include "Arduino.h"
 #define WIRE_WRITE Wire.write
#else
 #include "WProgram.h"
  #define WIRE_WRITE Wire.send
#endif

#if defined(__SAM3X8E__)
 typedef volatile RwReg PortReg;
 typedef uint32_t PortMask;
 #define HAVE_PORTREG
#elif defined(ARDUINO_ARCH_SAMD)
// not supported
#elif defined(ESP8266) || defined(ARDUINO_STM32_FEATHER)
  typedef volatile uint32_t PortReg;
  typedef uint32_t PortMask;
#else
  typedef volatile uint8_t PortReg;
  typedef uint8_t PortMask;
 #define HAVE_PORTREG
#endif

#include <SPI.h>
#include <Adafruit_GFX.h>

#define BLACK 0
#define WHITE 1
#define INVERSE 2


#define HUB08_LCDWIDTH    64
#define HUB08_LCDHEIGHT   16


class HUB08 : public Adafruit_GFX {
 public:
  HUB08(uint8_t a, uint8_t b, uint8_t c, uint8_t d, uint8_t oe, uint8_t r1, uint8_t stb, uint8_t clk);

  void drawPixel(int16_t x, int16_t y, uint16_t color);
  void begin();
  void on();
  void off();
  void scan();
  void clearDisplay();

 private:
  int8_t _i2caddr, _vccstate, sid, sclk, dc, rst, cs;
  uint8_t clk, r1, stb, oe, a, b, c, d;
  uint8_t  mask;
  uint8_t  state;
};

#endif /* _HUB08_H_ */
