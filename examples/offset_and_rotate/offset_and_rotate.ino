
#include <Wire.h>
#include "Grove_LED_Matrix_Driver_HT16K33.h"


Matrix_8x8 matrix;
int temp = -8;
orientation_type_t orientation = DISPLAY_ROTATE_0;

void setup()
{
    Wire.begin();
    matrix.init();
    matrix.setBrightness(0);
    matrix.setBlinkRate(BLINK_OFF);
    matrix.writeIcon(21);
}

void loop()
{
    matrix.display();
    delay(100);
    // Activate after call display()
    matrix.setDisplayOffset(temp, temp);
    temp++;
    if (temp == 9) 
    {
        temp = -8;
        orientation = orientation + 1;
        if (orientation == 4) orientation = DISPLAY_ROTATE_0;
        // Activate after call writeXXX
        matrix.setDisplayOrientation(orientation);
        matrix.writeIcon(21);
    }
}