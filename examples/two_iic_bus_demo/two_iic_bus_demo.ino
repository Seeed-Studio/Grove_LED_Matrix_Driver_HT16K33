
#include <Wire.h>
#include "Grove_LED_Matrix_Driver_HT16K33.h"

#include "SoftI2C.h"
#include "I2Cdev.h"

Default_IIC_Adapter hard_ware_iic;
SoftI2C soft_ware_iic(D8,D9); //sda, scl
Matrix_8x8 matrix1;
Matrix_8x8 matrix2;

void setup() {
  hard_ware_iic.begin();
  soft_ware_iic.begin();

  matrix1.init(&hard_ware_iic,0x70);
  matrix1.setBrightness(0);
  matrix1.setBlinkRate(BLINK_OFF);

  matrix2.init(&soft_ware_iic,0x70);
  matrix2.setBrightness(0);
  matrix2.setBlinkRate(BLINK_OFF);
}

void loop() {
    for (int i = 0; i < 33; i++) {
        // The input range of writeBar is [0-32]
        matrix1.writeBar(i);
        matrix2.writeBar(i);
        matrix1.display();
        matrix2.display();
        delay(150);
    }
}