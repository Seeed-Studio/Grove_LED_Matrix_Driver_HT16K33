
#include <Wire.h>
#include "Grove_LED_Matrix_Driver_HT16K33.h"


Matrix_8x8 matrix;

void setup()
{
    Wire.begin();
    matrix.init();
    matrix.setBrightness(10);
    matrix.setBlinkRate(BLINK_OFF);
}

void loop()
{
    for (int i=0;i<29;i++)
    {
        // The input range of writeIcon is [0-28]
        matrix.writeIcon(i);
        matrix.display();
        delay(500);
    }
}