#pragma once
#include <U8g2lib.h> 
#include <Wire.h>

extern U8G2_SH1107_128X128_1_HW_I2C u8g2; // final display, 128x128px [page buffer, size = 128 bytes], HW IIC connection

void init_display(); // no need extern, because it's a function declaration, not a variable