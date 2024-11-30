const byte BITMAP_WIDTH = 71;
const byte BITMAP_HEIGHT = 64;
 
const unsigned char SWITCHES_ZERO [] PROGMEM = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xfe, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0xff, 0x01, 0xf8, 0x3f, 0x00, 0xfe, 0x0f, 0xc0, 0x7f, 0xff,
    0x01, 0xf8, 0x3f, 0x00, 0xfe, 0x0f, 0xc0, 0x7f, 0xff, 0x01, 0xf8, 0x3f, 0x00, 0xfe, 0x0f, 0xc0,
    0x7f, 0xff, 0x01, 0xf8, 0x3f, 0x00, 0xfe, 0x0f, 0xc0, 0x7f, 0xff, 0x01, 0xf8, 0x3f, 0x00, 0xfe,
    0x0f, 0xc0, 0x7f, 0xff, 0x01, 0xf8, 0x3f, 0x00, 0xfe, 0x0f, 0xc0, 0x7f, 0xff, 0x01, 0xf8, 0x3f,
    0x00, 0xfe, 0x0f, 0xc0, 0x7f, 0xff, 0x01, 0xf8, 0x3f, 0x00, 0xfe, 0x0f, 0xc0, 0x7f, 0xff, 0x01,
    0xf8, 0x3f, 0x00, 0xfe, 0x0f, 0xc0, 0x7f, 0xff, 0x01, 0xf8, 0x3f, 0x00, 0xfe, 0x0f, 0xc0, 0x7f,
    0xff, 0xf1, 0xf8, 0x3f, 0x1c, 0xfe, 0x8f, 0xc7, 0x7f, 0xff, 0xf1, 0xf8, 0x3f, 0x1c, 0xfe, 0x8f,
    0xc7, 0x7f, 0xff, 0xf1, 0xf8, 0x3f, 0x1c, 0xfe, 0x8f, 0xc7, 0x7f, 0xff, 0xf1, 0xf8, 0x3f, 0x1c,
    0xfe, 0x8f, 0xc7, 0x7f, 0xff, 0xf1, 0xf8, 0x3f, 0x1c, 0xfe, 0x8f, 0xc7, 0x7f, 0xff, 0xf1, 0xf8,
    0x3f, 0x1c, 0xfe, 0x8f, 0xc7, 0x7f, 0xff, 0xf1, 0xf8, 0x3f, 0x1c, 0xfe, 0x8f, 0xc7, 0x7f, 0xff,
    0xf1, 0xf8, 0x3f, 0x1c, 0xfe, 0x8f, 0xc7, 0x7f, 0xff, 0xf1, 0xf8, 0x3f, 0x1c, 0xfe, 0x8f, 0xc7,
    0x7f, 0xff, 0xf1, 0xf8, 0x3f, 0x1c, 0xfe, 0x8f, 0xc7, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0x3f, 0x00, 0xf0, 0x00, 0x00, 0x1c, 0x00, 0x80, 0x07, 0x00, 0x00, 0xf0, 0x00, 0x00, 0x1c,
    0x00, 0x80, 0x07, 0x00, 0x00, 0xf0, 0x00, 0x00, 0x1c, 0x00, 0x80, 0x07, 0x00, 0x00, 0xf0, 0x00,
    0x00, 0x1c, 0x00, 0x80, 0x07, 0x00, 0x00, 0xf0, 0x00, 0x00, 0x1c, 0x00, 0x80, 0x07, 0x00, 0x00,
    0xf8, 0x00, 0x00, 0x3e, 0x00, 0x80, 0x0f, 0x00, 0x00, 0xfc, 0x01, 0x00, 0x7f, 0x00, 0xc0, 0x1f,
    0x00, 0x00, 0xfe, 0x03, 0x80, 0xff, 0x00, 0xe0, 0x3f, 0x00, 0x00, 0xfe, 0x03, 0x80, 0xff, 0x00,
    0xe0, 0x3f, 0x00, 0x00, 0xfe, 0x03, 0x80, 0xff, 0x00, 0xe0, 0x3f, 0x00, 0x00, 0xfe, 0x03, 0x80,
    0xff, 0x00, 0xe0, 0x3f, 0x00, 0x00, 0xfc, 0x01, 0x00, 0x7f, 0x00, 0xc0, 0x1f, 0x00, 0x00, 0xf8,
    0x01, 0x00, 0x7e, 0x00, 0xc0, 0x0f, 0x00, 0x00, 0x60, 0x00, 0x00, 0x1c, 0x00, 0x00, 0x03, 0x00
};
 
const unsigned char SWITCHES_ONE [] PROGMEM = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0,
    0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0xe0, 0x3f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x3f, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0xe0, 0x3f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x3f, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x0f,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x80, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x80, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x07, 0x00, 0xfe, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0xff, 0x01, 0xf8, 0x3f, 0x00, 0xfe, 0x8f, 0xc7, 0x7f, 0xff,
    0x01, 0xf8, 0x3f, 0x00, 0xfe, 0x8f, 0xc7, 0x7f, 0xff, 0x01, 0xf8, 0x3f, 0x00, 0xfe, 0x8f, 0xc7,
    0x7f, 0xff, 0x01, 0xf8, 0x3f, 0x00, 0xfe, 0x8f, 0xc7, 0x7f, 0xff, 0x01, 0xf8, 0x3f, 0x00, 0xfe,
    0x8f, 0xc7, 0x7f, 0xff, 0x01, 0xf8, 0x3f, 0x00, 0xfe, 0x8f, 0xc7, 0x7f, 0xff, 0x01, 0xf8, 0x3f,
    0x00, 0xfe, 0x8f, 0xc7, 0x7f, 0xff, 0x01, 0xf8, 0x3f, 0x00, 0xfe, 0x8f, 0xc7, 0x7f, 0xff, 0x01,
    0xf8, 0x3f, 0x00, 0xfe, 0x8f, 0xc7, 0x7f, 0xff, 0x01, 0xf8, 0x3f, 0x00, 0xfe, 0x8f, 0xc7, 0x7f,
    0xff, 0xf1, 0xf8, 0x3f, 0x1c, 0xfe, 0x0f, 0xc0, 0x7f, 0xff, 0xf1, 0xf8, 0x3f, 0x1c, 0xfe, 0x0f,
    0xc0, 0x7f, 0xff, 0xf1, 0xf8, 0x3f, 0x1c, 0xfe, 0x0f, 0xc0, 0x7f, 0xff, 0xf1, 0xf8, 0x3f, 0x1c,
    0xfe, 0x0f, 0xc0, 0x7f, 0xff, 0xf1, 0xf8, 0x3f, 0x1c, 0xfe, 0x0f, 0xc0, 0x7f, 0xff, 0xf1, 0xf8,
    0x3f, 0x1c, 0xfe, 0x0f, 0xc0, 0x7f, 0xff, 0xf1, 0xf8, 0x3f, 0x1c, 0xfe, 0x0f, 0xc0, 0x7f, 0xff,
    0xf1, 0xf8, 0x3f, 0x1c, 0xfe, 0x0f, 0xc0, 0x7f, 0xff, 0xf1, 0xf8, 0x3f, 0x1c, 0xfe, 0x0f, 0xc0,
    0x7f, 0xff, 0xf1, 0xf8, 0x3f, 0x1c, 0xfe, 0x0f, 0xc0, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0x3f, 0x00, 0xf0, 0x00, 0x00, 0x1c, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf0, 0x00, 0x00, 0x1c,
    0x00, 0x00, 0x00, 0x00, 0x00, 0xf0, 0x00, 0x00, 0x1c, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf0, 0x00,
    0x00, 0x1c, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf0, 0x00, 0x00, 0x1c, 0x00, 0x00, 0x00, 0x00, 0x00,
    0xf8, 0x00, 0x00, 0x3e, 0x00, 0x00, 0x00, 0x00, 0x00, 0xfc, 0x01, 0x00, 0x7f, 0x00, 0x00, 0x00,
    0x00, 0x00, 0xfe, 0x03, 0x80, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0xfe, 0x03, 0x80, 0xff, 0x00,
    0x00, 0x00, 0x00, 0x00, 0xfe, 0x03, 0x80, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0xfe, 0x03, 0x80,
    0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0xfc, 0x01, 0x00, 0x7f, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf8,
    0x01, 0x00, 0x7e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x60, 0x00, 0x00, 0x1c, 0x00, 0x00, 0x00, 0x00
};
 
const unsigned char SWITCHES_TWO [] PROGMEM = {
    0x00, 0x00, 0x00, 0x00, 0x1c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7f, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xff,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x80, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x7f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3e, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x1c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1c, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x1c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1c, 0x00, 0x00, 0x00, 0x00, 0xfe, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0xff, 0x01, 0xf8, 0x3f, 0x1c, 0xfe, 0x0f, 0xc0, 0x7f, 0xff,
    0x01, 0xf8, 0x3f, 0x1c, 0xfe, 0x0f, 0xc0, 0x7f, 0xff, 0x01, 0xf8, 0x3f, 0x1c, 0xfe, 0x0f, 0xc0,
    0x7f, 0xff, 0x01, 0xf8, 0x3f, 0x1c, 0xfe, 0x0f, 0xc0, 0x7f, 0xff, 0x01, 0xf8, 0x3f, 0x1c, 0xfe,
    0x0f, 0xc0, 0x7f, 0xff, 0x01, 0xf8, 0x3f, 0x1c, 0xfe, 0x0f, 0xc0, 0x7f, 0xff, 0x01, 0xf8, 0x3f,
    0x1c, 0xfe, 0x0f, 0xc0, 0x7f, 0xff, 0x01, 0xf8, 0x3f, 0x1c, 0xfe, 0x0f, 0xc0, 0x7f, 0xff, 0x01,
    0xf8, 0x3f, 0x1c, 0xfe, 0x0f, 0xc0, 0x7f, 0xff, 0x01, 0xf8, 0x3f, 0x1c, 0xfe, 0x0f, 0xc0, 0x7f,
    0xff, 0xf1, 0xf8, 0x3f, 0x00, 0xfe, 0x8f, 0xc7, 0x7f, 0xff, 0xf1, 0xf8, 0x3f, 0x00, 0xfe, 0x8f,
    0xc7, 0x7f, 0xff, 0xf1, 0xf8, 0x3f, 0x00, 0xfe, 0x8f, 0xc7, 0x7f, 0xff, 0xf1, 0xf8, 0x3f, 0x00,
    0xfe, 0x8f, 0xc7, 0x7f, 0xff, 0xf1, 0xf8, 0x3f, 0x00, 0xfe, 0x8f, 0xc7, 0x7f, 0xff, 0xf1, 0xf8,
    0x3f, 0x00, 0xfe, 0x8f, 0xc7, 0x7f, 0xff, 0xf1, 0xf8, 0x3f, 0x00, 0xfe, 0x8f, 0xc7, 0x7f, 0xff,
    0xf1, 0xf8, 0x3f, 0x00, 0xfe, 0x8f, 0xc7, 0x7f, 0xff, 0xf1, 0xf8, 0x3f, 0x00, 0xfe, 0x8f, 0xc7,
    0x7f, 0xff, 0xf1, 0xf8, 0x3f, 0x00, 0xfe, 0x8f, 0xc7, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0x3f, 0x00, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x80, 0x07, 0x00, 0x00, 0xf0, 0x00, 0x00, 0x00,
    0x00, 0x80, 0x07, 0x00, 0x00, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x80, 0x07, 0x00, 0x00, 0xf0, 0x00,
    0x00, 0x00, 0x00, 0x80, 0x07, 0x00, 0x00, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x80, 0x07, 0x00, 0x00,
    0xf8, 0x00, 0x00, 0x00, 0x00, 0x80, 0x0f, 0x00, 0x00, 0xfc, 0x01, 0x00, 0x00, 0x00, 0xc0, 0x1f,
    0x00, 0x00, 0xfe, 0x03, 0x00, 0x00, 0x00, 0xe0, 0x3f, 0x00, 0x00, 0xfe, 0x03, 0x00, 0x00, 0x00,
    0xe0, 0x3f, 0x00, 0x00, 0xfe, 0x03, 0x00, 0x00, 0x00, 0xe0, 0x3f, 0x00, 0x00, 0xfe, 0x03, 0x00,
    0x00, 0x00, 0xe0, 0x3f, 0x00, 0x00, 0xfc, 0x01, 0x00, 0x00, 0x00, 0xc0, 0x1f, 0x00, 0x00, 0xf8,
    0x01, 0x00, 0x00, 0x00, 0xc0, 0x0f, 0x00, 0x00, 0x60, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00
};
 
const unsigned char SWITCHES_THREE [] PROGMEM = {
    0x00, 0x00, 0x00, 0x00, 0x1c, 0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7f, 0x00, 0xc0,
    0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7f, 0x00, 0xe0, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x80, 0xff,
    0x00, 0xe0, 0x3f, 0x00, 0x00, 0x00, 0x00, 0x80, 0xff, 0x00, 0xe0, 0x3f, 0x00, 0x00, 0x00, 0x00,
    0x80, 0xff, 0x00, 0xe0, 0x3f, 0x00, 0x00, 0x00, 0x00, 0x80, 0xff, 0x00, 0xe0, 0x3f, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x7f, 0x00, 0xc0, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3e, 0x00, 0x80, 0x0f,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x1c, 0x00, 0x80, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1c, 0x00,
    0x80, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1c, 0x00, 0x80, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x1c, 0x00, 0x80, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1c, 0x00, 0x80, 0x07, 0x00, 0xfe, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0xff, 0x01, 0xf8, 0x3f, 0x1c, 0xfe, 0x8f, 0xc7, 0x7f, 0xff,
    0x01, 0xf8, 0x3f, 0x1c, 0xfe, 0x8f, 0xc7, 0x7f, 0xff, 0x01, 0xf8, 0x3f, 0x1c, 0xfe, 0x8f, 0xc7,
    0x7f, 0xff, 0x01, 0xf8, 0x3f, 0x1c, 0xfe, 0x8f, 0xc7, 0x7f, 0xff, 0x01, 0xf8, 0x3f, 0x1c, 0xfe,
    0x8f, 0xc7, 0x7f, 0xff, 0x01, 0xf8, 0x3f, 0x1c, 0xfe, 0x8f, 0xc7, 0x7f, 0xff, 0x01, 0xf8, 0x3f,
    0x1c, 0xfe, 0x8f, 0xc7, 0x7f, 0xff, 0x01, 0xf8, 0x3f, 0x1c, 0xfe, 0x8f, 0xc7, 0x7f, 0xff, 0x01,
    0xf8, 0x3f, 0x1c, 0xfe, 0x8f, 0xc7, 0x7f, 0xff, 0x01, 0xf8, 0x3f, 0x1c, 0xfe, 0x8f, 0xc7, 0x7f,
    0xff, 0xf1, 0xf8, 0x3f, 0x00, 0xfe, 0x0f, 0xc0, 0x7f, 0xff, 0xf1, 0xf8, 0x3f, 0x00, 0xfe, 0x0f,
    0xc0, 0x7f, 0xff, 0xf1, 0xf8, 0x3f, 0x00, 0xfe, 0x0f, 0xc0, 0x7f, 0xff, 0xf1, 0xf8, 0x3f, 0x00,
    0xfe, 0x0f, 0xc0, 0x7f, 0xff, 0xf1, 0xf8, 0x3f, 0x00, 0xfe, 0x0f, 0xc0, 0x7f, 0xff, 0xf1, 0xf8,
    0x3f, 0x00, 0xfe, 0x0f, 0xc0, 0x7f, 0xff, 0xf1, 0xf8, 0x3f, 0x00, 0xfe, 0x0f, 0xc0, 0x7f, 0xff,
    0xf1, 0xf8, 0x3f, 0x00, 0xfe, 0x0f, 0xc0, 0x7f, 0xff, 0xf1, 0xf8, 0x3f, 0x00, 0xfe, 0x0f, 0xc0,
    0x7f, 0xff, 0xf1, 0xf8, 0x3f, 0x00, 0xfe, 0x0f, 0xc0, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0x3f, 0x00, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf0, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf0, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0xf8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xfc, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0xfe, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xfe, 0x03, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0xfe, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xfe, 0x03, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xfc, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf8,
    0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x60, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};
 
const unsigned char SWITCHES_FOUR [] PROGMEM = {
    0x00, 0x70, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf8, 0x01, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0xfc, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xfe, 0x03, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0xfe, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xfe, 0x03,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xfc, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0xfc, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf0, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf0, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xfe, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0xff, 0xf1, 0xf8, 0x3f, 0x00, 0xfe, 0x0f, 0xc0, 0x7f, 0xff,
    0xf1, 0xf8, 0x3f, 0x00, 0xfe, 0x0f, 0xc0, 0x7f, 0xff, 0xf1, 0xf8, 0x3f, 0x00, 0xfe, 0x0f, 0xc0,
    0x7f, 0xff, 0xf1, 0xf8, 0x3f, 0x00, 0xfe, 0x0f, 0xc0, 0x7f, 0xff, 0xf1, 0xf8, 0x3f, 0x00, 0xfe,
    0x0f, 0xc0, 0x7f, 0xff, 0xf1, 0xf8, 0x3f, 0x00, 0xfe, 0x0f, 0xc0, 0x7f, 0xff, 0xf1, 0xf8, 0x3f,
    0x00, 0xfe, 0x0f, 0xc0, 0x7f, 0xff, 0xf1, 0xf8, 0x3f, 0x00, 0xfe, 0x0f, 0xc0, 0x7f, 0xff, 0xf1,
    0xf8, 0x3f, 0x00, 0xfe, 0x0f, 0xc0, 0x7f, 0xff, 0xf1, 0xf8, 0x3f, 0x00, 0xfe, 0x0f, 0xc0, 0x7f,
    0xff, 0x01, 0xf8, 0x3f, 0x1c, 0xfe, 0x8f, 0xc7, 0x7f, 0xff, 0x01, 0xf8, 0x3f, 0x1c, 0xfe, 0x8f,
    0xc7, 0x7f, 0xff, 0x01, 0xf8, 0x3f, 0x1c, 0xfe, 0x8f, 0xc7, 0x7f, 0xff, 0x01, 0xf8, 0x3f, 0x1c,
    0xfe, 0x8f, 0xc7, 0x7f, 0xff, 0x01, 0xf8, 0x3f, 0x1c, 0xfe, 0x8f, 0xc7, 0x7f, 0xff, 0x01, 0xf8,
    0x3f, 0x1c, 0xfe, 0x8f, 0xc7, 0x7f, 0xff, 0x01, 0xf8, 0x3f, 0x1c, 0xfe, 0x8f, 0xc7, 0x7f, 0xff,
    0x01, 0xf8, 0x3f, 0x1c, 0xfe, 0x8f, 0xc7, 0x7f, 0xff, 0x01, 0xf8, 0x3f, 0x1c, 0xfe, 0x8f, 0xc7,
    0x7f, 0xff, 0x01, 0xf8, 0x3f, 0x1c, 0xfe, 0x8f, 0xc7, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0x3f, 0x00, 0x00, 0x00, 0x00, 0x1c, 0x00, 0x80, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1c,
    0x00, 0x80, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1c, 0x00, 0x80, 0x07, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x1c, 0x00, 0x80, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1c, 0x00, 0x80, 0x07, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x3e, 0x00, 0x80, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7f, 0x00, 0xc0, 0x1f,
    0x00, 0x00, 0x00, 0x00, 0x80, 0xff, 0x00, 0xe0, 0x3f, 0x00, 0x00, 0x00, 0x00, 0x80, 0xff, 0x00,
    0xe0, 0x3f, 0x00, 0x00, 0x00, 0x00, 0x80, 0xff, 0x00, 0xe0, 0x3f, 0x00, 0x00, 0x00, 0x00, 0x80,
    0xff, 0x00, 0xe0, 0x3f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7f, 0x00, 0xc0, 0x1f, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x7e, 0x00, 0xc0, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1c, 0x00, 0x00, 0x03, 0x00
};
 
const unsigned char SWITCHES_FIVE [] PROGMEM = {
    0x00, 0x70, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x00, 0x00, 0xf8, 0x01, 0x00, 0x00, 0x00, 0xc0,
    0x0f, 0x00, 0x00, 0xfc, 0x03, 0x00, 0x00, 0x00, 0xe0, 0x1f, 0x00, 0x00, 0xfe, 0x03, 0x00, 0x00,
    0x00, 0xe0, 0x3f, 0x00, 0x00, 0xfe, 0x03, 0x00, 0x00, 0x00, 0xe0, 0x3f, 0x00, 0x00, 0xfe, 0x03,
    0x00, 0x00, 0x00, 0xe0, 0x3f, 0x00, 0x00, 0xfc, 0x03, 0x00, 0x00, 0x00, 0xe0, 0x3f, 0x00, 0x00,
    0xfc, 0x01, 0x00, 0x00, 0x00, 0xc0, 0x1f, 0x00, 0x00, 0xf8, 0x00, 0x00, 0x00, 0x00, 0x80, 0x0f,
    0x00, 0x00, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x80, 0x07, 0x00, 0x00, 0xf0, 0x00, 0x00, 0x00, 0x00,
    0x80, 0x07, 0x00, 0x00, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x80, 0x07, 0x00, 0x00, 0xf0, 0x00, 0x00,
    0x00, 0x00, 0x80, 0x07, 0x00, 0x00, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x80, 0x07, 0x00, 0xfe, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0xff, 0xf1, 0xf8, 0x3f, 0x00, 0xfe, 0x8f, 0xc7, 0x7f, 0xff,
    0xf1, 0xf8, 0x3f, 0x00, 0xfe, 0x8f, 0xc7, 0x7f, 0xff, 0xf1, 0xf8, 0x3f, 0x00, 0xfe, 0x8f, 0xc7,
    0x7f, 0xff, 0xf1, 0xf8, 0x3f, 0x00, 0xfe, 0x8f, 0xc7, 0x7f, 0xff, 0xf1, 0xf8, 0x3f, 0x00, 0xfe,
    0x8f, 0xc7, 0x7f, 0xff, 0xf1, 0xf8, 0x3f, 0x00, 0xfe, 0x8f, 0xc7, 0x7f, 0xff, 0xf1, 0xf8, 0x3f,
    0x00, 0xfe, 0x8f, 0xc7, 0x7f, 0xff, 0xf1, 0xf8, 0x3f, 0x00, 0xfe, 0x8f, 0xc7, 0x7f, 0xff, 0xf1,
    0xf8, 0x3f, 0x00, 0xfe, 0x8f, 0xc7, 0x7f, 0xff, 0xf1, 0xf8, 0x3f, 0x00, 0xfe, 0x8f, 0xc7, 0x7f,
    0xff, 0x01, 0xf8, 0x3f, 0x1c, 0xfe, 0x0f, 0xc0, 0x7f, 0xff, 0x01, 0xf8, 0x3f, 0x1c, 0xfe, 0x0f,
    0xc0, 0x7f, 0xff, 0x01, 0xf8, 0x3f, 0x1c, 0xfe, 0x0f, 0xc0, 0x7f, 0xff, 0x01, 0xf8, 0x3f, 0x1c,
    0xfe, 0x0f, 0xc0, 0x7f, 0xff, 0x01, 0xf8, 0x3f, 0x1c, 0xfe, 0x0f, 0xc0, 0x7f, 0xff, 0x01, 0xf8,
    0x3f, 0x1c, 0xfe, 0x0f, 0xc0, 0x7f, 0xff, 0x01, 0xf8, 0x3f, 0x1c, 0xfe, 0x0f, 0xc0, 0x7f, 0xff,
    0x01, 0xf8, 0x3f, 0x1c, 0xfe, 0x0f, 0xc0, 0x7f, 0xff, 0x01, 0xf8, 0x3f, 0x1c, 0xfe, 0x0f, 0xc0,
    0x7f, 0xff, 0x01, 0xf8, 0x3f, 0x1c, 0xfe, 0x0f, 0xc0, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0x3f, 0x00, 0x00, 0x00, 0x00, 0x1c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1c,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x1c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1c, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x3e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7f, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x80, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xff, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80,
    0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x7e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1c, 0x00, 0x00, 0x00, 0x00
};
 
const unsigned char SWITCHES_SIX [] PROGMEM = {
    0x00, 0x70, 0x00, 0x00, 0x1c, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf8, 0x01, 0x00, 0x7f, 0x00, 0x00,
    0x00, 0x00, 0x00, 0xfc, 0x03, 0x00, 0x7f, 0x00, 0x00, 0x00, 0x00, 0x00, 0xfe, 0x03, 0x80, 0xff,
    0x00, 0x00, 0x00, 0x00, 0x00, 0xfe, 0x03, 0x80, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0xfe, 0x03,
    0x80, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0xfc, 0x03, 0x80, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00,
    0xfc, 0x01, 0x00, 0x7f, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf8, 0x00, 0x00, 0x3e, 0x00, 0x00, 0x00,
    0x00, 0x00, 0xf0, 0x00, 0x00, 0x1c, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf0, 0x00, 0x00, 0x1c, 0x00,
    0x00, 0x00, 0x00, 0x00, 0xf0, 0x00, 0x00, 0x1c, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf0, 0x00, 0x00,
    0x1c, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf0, 0x00, 0x00, 0x1c, 0x00, 0x00, 0x00, 0x00, 0xfe, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0xff, 0xf1, 0xf8, 0x3f, 0x1c, 0xfe, 0x0f, 0xc0, 0x7f, 0xff,
    0xf1, 0xf8, 0x3f, 0x1c, 0xfe, 0x0f, 0xc0, 0x7f, 0xff, 0xf1, 0xf8, 0x3f, 0x1c, 0xfe, 0x0f, 0xc0,
    0x7f, 0xff, 0xf1, 0xf8, 0x3f, 0x1c, 0xfe, 0x0f, 0xc0, 0x7f, 0xff, 0xf1, 0xf8, 0x3f, 0x1c, 0xfe,
    0x0f, 0xc0, 0x7f, 0xff, 0xf1, 0xf8, 0x3f, 0x1c, 0xfe, 0x0f, 0xc0, 0x7f, 0xff, 0xf1, 0xf8, 0x3f,
    0x1c, 0xfe, 0x0f, 0xc0, 0x7f, 0xff, 0xf1, 0xf8, 0x3f, 0x1c, 0xfe, 0x0f, 0xc0, 0x7f, 0xff, 0xf1,
    0xf8, 0x3f, 0x1c, 0xfe, 0x0f, 0xc0, 0x7f, 0xff, 0xf1, 0xf8, 0x3f, 0x1c, 0xfe, 0x0f, 0xc0, 0x7f,
    0xff, 0x01, 0xf8, 0x3f, 0x00, 0xfe, 0x8f, 0xc7, 0x7f, 0xff, 0x01, 0xf8, 0x3f, 0x00, 0xfe, 0x8f,
    0xc7, 0x7f, 0xff, 0x01, 0xf8, 0x3f, 0x00, 0xfe, 0x8f, 0xc7, 0x7f, 0xff, 0x01, 0xf8, 0x3f, 0x00,
    0xfe, 0x8f, 0xc7, 0x7f, 0xff, 0x01, 0xf8, 0x3f, 0x00, 0xfe, 0x8f, 0xc7, 0x7f, 0xff, 0x01, 0xf8,
    0x3f, 0x00, 0xfe, 0x8f, 0xc7, 0x7f, 0xff, 0x01, 0xf8, 0x3f, 0x00, 0xfe, 0x8f, 0xc7, 0x7f, 0xff,
    0x01, 0xf8, 0x3f, 0x00, 0xfe, 0x8f, 0xc7, 0x7f, 0xff, 0x01, 0xf8, 0x3f, 0x00, 0xfe, 0x8f, 0xc7,
    0x7f, 0xff, 0x01, 0xf8, 0x3f, 0x00, 0xfe, 0x8f, 0xc7, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0x3f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x80, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x07, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x80, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x07, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0x1f,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x3f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0xe0, 0x3f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x3f, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0xe0, 0x3f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0x1f, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0xc0, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00
};
 
const unsigned char SWITCHES_SEVEN [] PROGMEM = {
    0x00, 0x70, 0x00, 0x00, 0x1c, 0x00, 0x00, 0x07, 0x00, 0x00, 0xf8, 0x01, 0x00, 0x7f, 0x00, 0xc0,
    0x0f, 0x00, 0x00, 0xfc, 0x03, 0x00, 0x7f, 0x00, 0xe0, 0x1f, 0x00, 0x00, 0xfe, 0x03, 0x80, 0xff,
    0x00, 0xe0, 0x3f, 0x00, 0x00, 0xfe, 0x03, 0x80, 0xff, 0x00, 0xe0, 0x3f, 0x00, 0x00, 0xfe, 0x03,
    0x80, 0xff, 0x00, 0xe0, 0x3f, 0x00, 0x00, 0xfc, 0x03, 0x80, 0xff, 0x00, 0xe0, 0x3f, 0x00, 0x00,
    0xfc, 0x01, 0x00, 0x7f, 0x00, 0xc0, 0x1f, 0x00, 0x00, 0xf8, 0x00, 0x00, 0x3e, 0x00, 0x80, 0x0f,
    0x00, 0x00, 0xf0, 0x00, 0x00, 0x1c, 0x00, 0x80, 0x07, 0x00, 0x00, 0xf0, 0x00, 0x00, 0x1c, 0x00,
    0x80, 0x07, 0x00, 0x00, 0xf0, 0x00, 0x00, 0x1c, 0x00, 0x80, 0x07, 0x00, 0x00, 0xf0, 0x00, 0x00,
    0x1c, 0x00, 0x80, 0x07, 0x00, 0x00, 0xf0, 0x00, 0x00, 0x1c, 0x00, 0x80, 0x07, 0x00, 0xfe, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0xff, 0xf1, 0xf8, 0x3f, 0x1c, 0xfe, 0x8f, 0xc7, 0x7f, 0xff,
    0xf1, 0xf8, 0x3f, 0x1c, 0xfe, 0x8f, 0xc7, 0x7f, 0xff, 0xf1, 0xf8, 0x3f, 0x1c, 0xfe, 0x8f, 0xc7,
    0x7f, 0xff, 0xf1, 0xf8, 0x3f, 0x1c, 0xfe, 0x8f, 0xc7, 0x7f, 0xff, 0xf1, 0xf8, 0x3f, 0x1c, 0xfe,
    0x8f, 0xc7, 0x7f, 0xff, 0xf1, 0xf8, 0x3f, 0x1c, 0xfe, 0x8f, 0xc7, 0x7f, 0xff, 0xf1, 0xf8, 0x3f,
    0x1c, 0xfe, 0x8f, 0xc7, 0x7f, 0xff, 0xf1, 0xf8, 0x3f, 0x1c, 0xfe, 0x8f, 0xc7, 0x7f, 0xff, 0xf1,
    0xf8, 0x3f, 0x1c, 0xfe, 0x8f, 0xc7, 0x7f, 0xff, 0xf1, 0xf8, 0x3f, 0x1c, 0xfe, 0x8f, 0xc7, 0x7f,
    0xff, 0x01, 0xf8, 0x3f, 0x00, 0xfe, 0x0f, 0xc0, 0x7f, 0xff, 0x01, 0xf8, 0x3f, 0x00, 0xfe, 0x0f,
    0xc0, 0x7f, 0xff, 0x01, 0xf8, 0x3f, 0x00, 0xfe, 0x0f, 0xc0, 0x7f, 0xff, 0x01, 0xf8, 0x3f, 0x00,
    0xfe, 0x0f, 0xc0, 0x7f, 0xff, 0x01, 0xf8, 0x3f, 0x00, 0xfe, 0x0f, 0xc0, 0x7f, 0xff, 0x01, 0xf8,
    0x3f, 0x00, 0xfe, 0x0f, 0xc0, 0x7f, 0xff, 0x01, 0xf8, 0x3f, 0x00, 0xfe, 0x0f, 0xc0, 0x7f, 0xff,
    0x01, 0xf8, 0x3f, 0x00, 0xfe, 0x0f, 0xc0, 0x7f, 0xff, 0x01, 0xf8, 0x3f, 0x00, 0xfe, 0x0f, 0xc0,
    0x7f, 0xff, 0x01, 0xf8, 0x3f, 0x00, 0xfe, 0x0f, 0xc0, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0x3f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};
 