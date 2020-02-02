
#include <Wire.h>
#include "Grove_LED_Matrix_Driver_HT16K33.h"


// Create uint64_t type 8x8 matrix picture at
// https://xantorohara.github.io/led-matrix-editor/#
const uint64_t EXAMPLE[12] = {
    0x5554545050404000,
    0x3f21212121212121,
    0x3f212d2121212121,
    0x3f212d212d212121,
    0x3f212d212d212d21,
    0x3f212d2d2d212121,
    0x3f212d2d2d2d2d2d,
    0x00040a1120408000,
    0x081c3e7f1c1c1c1c,
    0x0010307fff7f3010,
    0x1c1c1c1c7f3e1c08,
    0x00080cfefffe0c08
};

Matrix_8x8 matrix;

void setup() {
    Wire.begin();
    matrix.init();
    matrix.setBrightness(0);
    matrix.setBlinkRate(BLINK_OFF);
}

void loop() {
    matrix.writeOnePicture(EXAMPLE[11]);
    matrix.display();
    delay(1000);


    matrix.writePictures(EXAMPLE, 12, 1000, ACTION_SCROLLING);
    matrix.display();
}