
#include <Wire.h>
#include "Grove_LED_Matrix_Driver_HT16K33.h"

#include "SoftI2C.h"
#include "I2Cdev.h"

Default_IIC_Adapter hard_ware_iic;
Matrix_8x8 matrix;
int temp = -8;
uint8_t orientation = DISPLAY_ROTATE_0;

void setup() {
    hard_ware_iic.begin();
    matrix.init(&hard_ware_iic,0x70);
    matrix.setBrightness(0);
    matrix.setBlinkRate(BLINK_OFF);
    matrix.writeIcon(21);
}

void loop() {
    matrix.display();
    delay(100);
    // Activate after call display()
    matrix.setDisplayOffset(temp, temp);
    temp++;
    if (temp == 9) {
        temp = -8;
        orientation = orientation + 1;
        if (orientation == 4) {
            orientation = DISPLAY_ROTATE_0;
        }
        // Activate after call writeXXX
        matrix.setDisplayOrientation(orientation);
        matrix.writeIcon(21);
    }
}