
#include <Wire.h>
#include "Grove_LED_Matrix_Driver_HT16K33.h"

Matrix_8x8 matrix;

void setup()
{
    Wire.begin();
    matrix.init();
    matrix.setBrightness(0);
    matrix.setBlinkRate(BLINK_OFF);
}

void loop()
{
    // display number "0" and delay 800ns
    matrix.writeNumber(0,800);
    matrix.display();

    // display number "-2147483648" and delay (800*11)ns
    // the display range of writeNumber() is int32_t (from -2147483648 to 2147483647)
    matrix.writeNumber(-2147483648,800);
    matrix.display();
}