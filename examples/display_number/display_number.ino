
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
    // display number "0" and delay 800ns
    matrix.writeNumber(0, 800);
    matrix.display();

    // display number "-2147483648" and delay (800*11)ns
    // the display range of writeNumber() is int32_t (from -2147483648 to 2147483647)
    matrix.writeNumber(-2147483648, 800);
    matrix.display();
}