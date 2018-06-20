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
    matrix.writeString("!", 1000, ACTION_SHIFT);
    matrix.display();

    matrix.writeString("abc", 1000, ACTION_SHIFT);
    matrix.display();

    matrix.writeString("efg", 1000, ACTION_SCROLLING);
    matrix.display();
}