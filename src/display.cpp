#include <U8g2lib.h> 
#include <Wire.h>
#include "display.h"

U8G2_SH1107_128X128_1_HW_I2C u8g2(U8G2_R0); // final display, 128x128px [page buffer, size = 128 bytes], HW IIC connection

void init_display() {
    u8g2.begin();
    u8g2.setContrast(255);
}
