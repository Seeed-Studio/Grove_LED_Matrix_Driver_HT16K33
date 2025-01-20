#include <Wire.h>
#include "Grove_LED_Matrix_Driver_HT16K33.h"

#include "SoftI2C.h"
#include "I2Cdev.h"

Default_IIC_Adapter hard_ware_iic;
Matrix_8x8 matrix;

void setup() {
    hard_ware_iic.begin();
    matrix.init(&hard_ware_iic,0x70);
    matrix.setBrightness(0);
    matrix.setBlinkRate(BLINK_OFF);

}

void loop() {
    matrix.writeString("!", 1000, ACTION_SHIFT);
    matrix.display();

    matrix.writeString("abc", 1000, ACTION_SHIFT);
    matrix.display();

    matrix.writeString("efg", 1000, ACTION_SCROLLING);
    matrix.display();
}