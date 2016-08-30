/**
 * LED Matrix library for http://www.seeedstudio.com/depot/ultrathin-16x32-red-led-matrix-panel-p-1582.html
 * The LED Matrix panel has 32x16 pixels. Several panel can be combined together as a large screen.
 *
 * Coordinate & Connection (Arduino -> panel 0 -> panel 1 -> ...)
 *   (0, 0)                                     (0, 0)
 *     +--------+--------+--------+               +--------+--------+
 *     |   5    |    4   |    3   |               |    1   |    0   |
 *     |        |        |        |               |        |        |<----- Arduino
 *     +--------+--------+--------+               +--------+--------+
 *     |   2    |    1   |    0   |                              (64, 16) 
 *     |        |        |        |<----- Arduino
 *     +--------+--------+--------+
 *                             (96, 32)
 *
 */

#include "HUB08.h"

#include <Fonts/TomThumb.h>

#define WIDTH   64
#define HEIGHT  16

// LEDMatrix(a, b, c, d, oe, r1, stb, clk);

#define A 15
#define B 13
#define C 12
#define D 14
#define OE 4
#define R1 5
#define STB 2
#define CLK 0

HUB08 matrix(A, B, C, D, OE, R1, STB, CLK);


void setup()
{
  matrix.begin();
  matrix.clearDisplay();
  matrix.setFont(&TomThumb);
  /*
  matrix.drawPixel(1,1,WHITE);
  matrix.drawPixel(2,2,WHITE);
  matrix.drawPixel(3,3,WHITE);
  matrix.drawPixel(4,4,WHITE);
  matrix.drawPixel(5,5,WHITE);
  */
  matrix.setTextSize(1);
  matrix.setTextColor(WHITE);
  matrix.setCursor(0,14);
  matrix.println("Hello Dave, I'm Sorry.");
    
}


void loop()
{

    matrix.scan();

}

