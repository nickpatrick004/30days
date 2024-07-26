/*
 * 30 Days - Lost in Space
 * Day 26 - Fun With Bitmaps
 *
 * Explorer, your lander is finally back in space, but we still need to rejoin
 * the mother ship so more work is required.
 *
 * As we continue to build up your control panel we can see that our loop
 * is running slower and slower, especially as we draw more complex graphics
 * on the display (like our lander).
 *
 * There is a more efficient way to display graphics on our display though.
 * What if we draw an image *once* and save that picture?  Then we can just
 * move it quickly onto our display rather than going through the work to draw
 * each piece separately.
 *
 * Our graphics library provides a way to do JUST that using something called
 * a "bitmap".  This is simply a representation of an image using zero and one
 * bits.  A zero bit leaves a pixel turned off, and a one bit turns it on.
 *
 * Our image can now be saved in our sketch as an array of bits that then gets
 * mapped to our display.  (Thus, "bitmaps").  You can find a number of sample
 * images below our loop() below, along with an explanation of how they were
 * created and represented in our sketch.
 *
 * Learn more at https://learn.inventr.io/adventure
 *
 * Alex Eschenauer
 * David Schmidt
 * Greg Lyzenga
 */

/*
 * Arduino concepts introduced/documented in this lesson.
 * - bitmaps
 * - hexadecimal
 * - forward declarations
 * - pointers
 *
 * Parts and electronics concepts introduced in this lesson.
 * - 
 */

// Explicitly include Arduino.h
#include "Arduino.h"

// Extensive documentation for this library can be found at https://github.com/olikraus/u8g2
#include <U8g2lib.h>  // Include file for the U8g2 library.
#include "Wire.h"     // Sometimes required for I2C communications.

// Use _2_ version of constructor and firstPage()/nextPage() for OLED
// graphics to save memory.
U8G2_SH1106_128X64_NONAME_2_HW_I2C lander_display(U8G2_R0, /* reset=*/U8X8_PIN_NONE);

/*
 * Forward declarations
 *
 * Our bitmaps need to be declared in our sketch before they are referenced
 * by code.  But the declaration for each of these images can extend for many
 * lines, forcing us to scroll down to find our setup(), loop() and any
 * additional functions.
 *
 * In order to keep our code near the top of our file we can use a "forward
 * declaration".  This starts with "extern" which tells the compiler that
 * the remaining data is "external" to this line.  The remainder of the line
 * gives enough information about the name and structure of the data so that
 * code can be created.
 *
 * The full declaration MUST be included in our sketch, but now we can move
 * those long declaration to the BOTTOM of our sketch so our setup() and loop()
 * are easy to find near the top of our sketch.
 */
extern const unsigned char niceRocketBro[] U8X8_PROGMEM;
extern const unsigned char planetBitmap[] U8X8_PROGMEM;
extern const unsigned char earthBitmap[] U8X8_PROGMEM;
extern const unsigned char inventrCorpLogoBitmap[] U8X8_PROGMEM;

/*
 * Data pointers (addresses)
 *
 * In this sketch we wish to display each of the images in turn
 * on our lander display.  We COULD write this like:
 *
 * lander_display.drawXBM(...); // Draw first image
 * delay(2000);                 // delay 2 seconds
 * lander_display.drawXBM(...); // Draw second image
 * delay(2000);                 // delay 2 seconds
 *
 * But this is very repetative and wordy.  If we simply had a list
 * of images in an array we could then write a loop that displays
 * each in turn.
 *
 * Arduino C++ allows us to do this, using something called a "pointer".
 * A pointer represents the ADDRESS in memory of the first byte of
 * a piece of data (like the arrays of data for our images).
 *
 * This array simply holds pointers to each of our image arrays and
 * we can now reference each images using bitmaps[0], bitmap[1], etc.
 */
const static char* bitmaps[] = {
  niceRocketBro,
  planetBitmap,
  earthBitmap,
  inventrCorpLogoBitmap,
};

// ************************************************
void setup(void) {
  Serial.begin(9600);
  lander_display.begin();   // initialize lander display
}

// ************************************************
void loop(void) {

  // The number of items in our array is the total size of our array (in bytes)
  // divided by the size of the first item.
  int number_of_bitmaps = sizeof(bitmaps) / sizeof(bitmaps[0]);
  
  // Now display each of the bitmaps followed by a delay.
  for (int i = 0; i < number_of_bitmaps; i++) {
    lander_display.firstPage();
    do {
      // .drawXBMP() displays each bitmap starting at the upper left corner
      // (0, 0) that has width of 128 and height of 64.
      lander_display.drawXBMP(0, 0, 128, 64, bitmaps[i]);
    } while (lander_display.nextPage());

    // Display each bitmap for 2 seconds.
    delay(2000);
  }
}

/*
 * Graphics data arrays definition
 *
 * We need to define each of our images using zeros and ones and there are a
 * number of ways we can do this.
 *
 * 1) We could use decimal numbers to represent each byte of data using the
 *    numbers 0-255:
 *      234, 0, 127, 255, ...
 *    But this is hard to align since each byte is 1-3 digits long.
 * 2) We could use binary constants like you've used before:
 *      0b11101101, 0b00000000, 0b01111111, 0b11111111, ...
 *    But this isn't very compact and is more error prone if typed manually.
 *
 * There is another way of representing data that is commonly used for computer
 * code.  Instead of only having 0 or 1 (two values) to represent a single bit
 * we can use more symbol.  We could use decimal (base 10) numbers but this doesn't
 * map well onto computers with data lengths that are powers of two (1, 2, 4, 8, etc.).
 *
 * Programmers created Hexadecimal notation to address these issues.  Hexadecimal
 * is a base-16 number system, meaning it has 16 distinct symbols: 0-9 to represent
 * values zero to nine, and A-F to represent values ten to fifteen.  This allows
 * data to be represented in a compact format that aligns well with bit lengths that
 * are powers of 2.
 */

static const unsigned char niceRocketBro[] U8X8_PROGMEM = {
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x80, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0xc0, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0xf0, 0xff, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0xd0, 0xff, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc4, 0x83, 0x03, 0x00, 0x00, 0x00, 0x00,
  0x00, 0xf8, 0xff, 0x5f, 0x02, 0x00, 0x00, 0x00, 0x80, 0xcd, 0x03, 0x03, 0x00, 0x00, 0x00, 0x00,
  0x00, 0xfc, 0xff, 0xff, 0x03, 0x00, 0x00, 0x00, 0x80, 0xcf, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0xff, 0xff, 0xff, 0x03, 0x00, 0x00, 0x00, 0x00, 0x40, 0x87, 0x63, 0xd1, 0x00, 0x00, 0x00,
  0x80, 0xff, 0xff, 0xff, 0x07, 0x00, 0x00, 0x00, 0x00, 0x40, 0x0e, 0x33, 0xdb, 0x01, 0x00, 0x00,
  0xe0, 0xff, 0xff, 0xff, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x40, 0x0e, 0xbb, 0xdf, 0x01, 0x00, 0x00,
  0xc0, 0xff, 0xff, 0xff, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x40, 0x1c, 0x3b, 0x1c, 0x00, 0x00, 0x00,
  0x80, 0xff, 0xff, 0xff, 0x3f, 0x00, 0x00, 0x00, 0x00, 0x40, 0x1c, 0x3b, 0x1c, 0x00, 0x00, 0x00,
  0xc0, 0xff, 0xff, 0xff, 0x3f, 0x00, 0x00, 0x00, 0x00, 0x40, 0x18, 0x33, 0x1a, 0x00, 0x00, 0x00,
  0xe0, 0xff, 0xff, 0xff, 0x7f, 0x00, 0x00, 0x00, 0x00, 0x40, 0x18, 0x63, 0x31, 0x00, 0x00, 0x00,
  0xe0, 0xff, 0xfd, 0xff, 0x7f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0xe8, 0xff, 0xf9, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0xf8, 0xef, 0xf0, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0xe0, 0xff, 0xc0, 0xff, 0xff, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0xf0, 0xff, 0xe0, 0xff, 0xff, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0xfc, 0xff, 0xe0, 0xff, 0xff, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0xfc, 0xdf, 0x00, 0xff, 0xff, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0xff, 0xcf, 0x00, 0x7e, 0xff, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0xff, 0xc3, 0x20, 0x78, 0xfc, 0x0b, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0xff, 0xc7, 0x80, 0x72, 0xfd, 0x11, 0x00, 0x00, 0xc0, 0x03, 0x00, 0x00, 0x3c, 0x00, 0x00, 0x00,
  0xff, 0xc3, 0x00, 0x30, 0xfc, 0x03, 0x00, 0x00, 0x80, 0x03, 0x00, 0x00, 0x38, 0x00, 0x00, 0x6c,
  0xff, 0x03, 0x80, 0xf3, 0xfb, 0x03, 0x00, 0x00, 0x80, 0x03, 0x80, 0x03, 0x38, 0x00, 0x00, 0x60,
  0xff, 0x03, 0xa0, 0xf3, 0xff, 0x03, 0x00, 0x00, 0x80, 0x03, 0x80, 0x03, 0x38, 0x00, 0x00, 0x48,
  0xf7, 0x03, 0xe8, 0xf1, 0xff, 0x01, 0x7e, 0x16, 0x96, 0x03, 0x9a, 0x03, 0xf8, 0xb9, 0xd1, 0x00,
  0xd7, 0x03, 0xf8, 0xf1, 0xff, 0x03, 0x6e, 0x33, 0xb3, 0x03, 0xbb, 0x03, 0xb8, 0xb3, 0xdf, 0x01,
  0xff, 0x01, 0xf0, 0xf1, 0x9f, 0x09, 0x6e, 0xf3, 0xbb, 0x8b, 0xbb, 0x03, 0x38, 0xb3, 0xdd, 0x01,
  0xfe, 0x01, 0xf0, 0xe1, 0x9f, 0x03, 0x0e, 0xf3, 0x83, 0x9f, 0x83, 0x03, 0x38, 0x33, 0xdc, 0x01,
  0xfe, 0x01, 0xe0, 0xe0, 0xc7, 0x02, 0x0e, 0xf3, 0x83, 0x9f, 0x83, 0x03, 0x38, 0x33, 0xdc, 0x01,
  0xfe, 0x01, 0x60, 0xc0, 0xe6, 0x00, 0x0e, 0x33, 0xa3, 0xbb, 0xa3, 0x7b, 0xb8, 0x33, 0xdc, 0x01,
  0xfe, 0x07, 0x40, 0xe0, 0xe7, 0x02, 0x0e, 0x36, 0x97, 0x3b, 0x17, 0x63, 0xb8, 0x31, 0xd8, 0x00,
  0xff, 0x07, 0x00, 0xe0, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0x00, 0x00, 0x00, 0x00,
  0xff, 0x0f, 0x00, 0x20, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x00, 0x00, 0x00, 0x00,
  0xff, 0x07, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0xff, 0x07, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0xff, 0x03, 0x00, 0x80, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0xff, 0x01, 0x00, 0xfc, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0xbf, 0x01, 0x00, 0x78, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x83, 0x01, 0x00, 0x00, 0xfe, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x61, 0x02, 0x00, 0x00, 0x84, 0x05, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0xd1, 0x00, 0x00, 0x00, 0x38, 0x15, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0xfc, 0x00, 0x00, 0x00, 0x80, 0x6d, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x7e, 0x01, 0x00, 0x00, 0x40, 0x5c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x1f, 0x00, 0x00, 0x00, 0x00, 0xc2, 0x00, 0x00, 0xfe, 0x19, 0x00, 0x00, 0x00, 0x06, 0x00, 0x00,
  0x8f, 0x00, 0x00, 0x04, 0x08, 0x04, 0x00, 0x00, 0x08, 0x01, 0x00, 0x20, 0x00, 0x00, 0x00, 0x00,
  0x09, 0x00, 0x00, 0x80, 0x00, 0x20, 0x00, 0x00, 0x48, 0xdd, 0x8e, 0xf7, 0x39, 0x77, 0x03, 0x00,
  0x0b, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0x98, 0xc9, 0x24, 0x4c, 0x44, 0x06, 0x00,
  0x50, 0x01, 0x00, 0x00, 0x00, 0x60, 0x00, 0x00, 0x78, 0x98, 0x99, 0x20, 0xc4, 0x44, 0x04, 0x00,
  0x00, 0x00, 0x00, 0x08, 0x00, 0x02, 0x00, 0x00, 0x48, 0x99, 0x19, 0x27, 0x04, 0x44, 0x04, 0x00,
  0x00, 0x0c, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x08, 0x99, 0x99, 0x2c, 0x05, 0x44, 0x04, 0x00,
  0x00, 0x04, 0x00, 0x00, 0x00, 0x14, 0x00, 0x00, 0x08, 0x99, 0xd9, 0x6c, 0x4d, 0x44, 0x04, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xfe, 0xfd, 0xbf, 0xc7, 0x38, 0xff, 0x0e, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

static const unsigned char planetBitmap[] U8X8_PROGMEM = {
  0x10, 0x08, 0x82, 0x20, 0x08, 0x82, 0x20, 0x08, 0x82, 0x20, 0x08, 0x82,
  0x20, 0x08, 0x82, 0x20, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFE, 0x05, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xC0, 0xFF,
  0x1F, 0x00, 0xEA, 0x1B, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0xF0, 0xFF, 0x7F, 0xA0, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xF8, 0xFF, 0xFF, 0xFD, 0xEF, 0xFF,
  0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFC, 0xFF,
  0xFF, 0xFF, 0xFF, 0xFF, 0x01, 0x00, 0x00, 0x80, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0xFE, 0xFF, 0xFF, 0xFF, 0x7F, 0xFA, 0x01, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x01, 0xF0,
  0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xFF, 0xFF,
  0xFF, 0x0F, 0x00, 0xF8, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x80, 0xFF, 0x7F, 0xFC, 0x0F, 0x00, 0xFC, 0x01, 0x00, 0x00, 0x80,
  0x00, 0x00, 0x00, 0x00, 0x00, 0xC0, 0xFF, 0x3F, 0xFC, 0x1F, 0x00, 0xFE,
  0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0xC0, 0xFF, 0x3F,
  0xF8, 0x1F, 0x80, 0x3F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0xE0, 0xFF, 0x3F, 0xFC, 0x1F, 0xE0, 0x3F, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0xE0, 0x1F, 0xFF, 0xFE, 0x3F, 0xF0, 0x0F,
  0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0xF8, 0x1F, 0xFE,
  0xFF, 0x3F, 0xFE, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0xFC, 0x0F, 0xFE, 0xFF, 0x7F, 0xFF, 0x01, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0x1F, 0xFF, 0xFF, 0xFF, 0xFF, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0xC0, 0xFF, 0xBF, 0xFF,
  0xFF, 0xFF, 0x1F, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0x00, 0x00,
  0xF0, 0xFF, 0xFF, 0xFF, 0x3F, 0xFF, 0x0F, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0xFC, 0xF7, 0xFF, 0xFF, 0x3F, 0xFE, 0x03, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFE, 0xE3, 0xFF, 0xFF,
  0x0F, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80,
  0xFF, 0xE0, 0xFF, 0xFF, 0x07, 0x3F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80,
  0x00, 0x00, 0x00, 0xE0, 0x3F, 0xE0, 0xFF, 0xFF, 0x83, 0x3F, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0xE0, 0x0F, 0xC0, 0xFF, 0xFF,
  0xC0, 0x1F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xF0,
  0x07, 0xC0, 0x7F, 0x0B, 0xF0, 0x1F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0xF8, 0x01, 0x80, 0x7F, 0x00, 0xF8, 0x0F, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0x00, 0xFC, 0x00, 0x80, 0x3F, 0x00,
  0xFE, 0x0F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7C,
  0x00, 0xF0, 0x7F, 0xC0, 0xFF, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x3C, 0x6A, 0xFF, 0xFF, 0xFF, 0xFF, 0x03, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0xFE, 0xFF, 0xFF, 0xFF, 0xFF,
  0xFF, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0x00, 0xFC,
  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0xF8, 0xFF, 0x7F, 0xF0, 0xFF, 0x7F, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xF0, 0xFF, 0x01, 0xC0, 0xFF,
  0x1F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0xFF, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x84, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x41, 0x10, 0x04, 0x41,
  0x10, 0x04, 0x41, 0x88
};

static const unsigned char earthBitmap[] U8X8_PROGMEM = {
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x00,
  0x00, 0xf8, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0x1f, 0x00,
  0x00, 0xf8, 0xff, 0x00, 0x00, 0x00, 0x00, 0xf8, 0x07, 0x00, 0x00, 0x00, 0x00, 0xff, 0x1f, 0x00,
  0x00, 0xf8, 0xff, 0x00, 0x00, 0x00, 0xc0, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0xff, 0x1f, 0x00,
  0x00, 0xf8, 0xff, 0x00, 0x00, 0x00, 0xf0, 0x7f, 0xc3, 0x03, 0x00, 0x00, 0x00, 0xff, 0x1f, 0x00,
  0x00, 0x08, 0x02, 0x00, 0x00, 0x00, 0xfe, 0x0f, 0x00, 0x1f, 0x00, 0x00, 0x00, 0x40, 0x10, 0x00,
  0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x7f, 0x07, 0xe0, 0x3f, 0x00, 0x00, 0x00, 0x41, 0x10, 0x00,
  0x00, 0x08, 0x02, 0x00, 0x00, 0x80, 0xbf, 0x05, 0xc0, 0xff, 0x00, 0x00, 0x00, 0xf1, 0x10, 0x00,
  0x00, 0xf8, 0xff, 0x00, 0x00, 0x60, 0xc2, 0x04, 0x82, 0x97, 0x01, 0x00, 0x00, 0x03, 0x18, 0x00,
  0x00, 0xf8, 0xff, 0x00, 0x00, 0x10, 0xe1, 0xc0, 0x40, 0x62, 0x07, 0x00, 0x00, 0x07, 0x1e, 0x00,
  0x00, 0xf8, 0xff, 0x00, 0x00, 0xf8, 0xfb, 0xf0, 0x0f, 0x80, 0x0e, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0xf8, 0xff, 0x00, 0x00, 0xbc, 0x70, 0x20, 0xbf, 0xc2, 0x11, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x08, 0x00, 0x00, 0x00, 0xfe, 0x10, 0xf1, 0x0f, 0x85, 0x3f, 0x00, 0x00, 0x03, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x0b, 0x38, 0xe0, 0x7f, 0xdb, 0x3c, 0x00, 0x00, 0x08, 0x00, 0x00,
  0x00, 0x78, 0x00, 0x00, 0x00, 0x00, 0x28, 0xe0, 0x7f, 0xfe, 0x61, 0x00, 0x00, 0x50, 0x00, 0x00,
  0x00, 0x18, 0x00, 0x00, 0x00, 0xa0, 0x15, 0x74, 0xbe, 0x5f, 0xc3, 0x00, 0x00, 0x10, 0x03, 0x00,
  0x00, 0x08, 0x00, 0x00, 0x00, 0x40, 0x08, 0xf8, 0x70, 0x3f, 0xe2, 0x00, 0x00, 0x90, 0x0f, 0x00,
  0x00, 0x08, 0x00, 0x00, 0x00, 0x00, 0x81, 0x62, 0xfe, 0x57, 0xf8, 0x01, 0x00, 0xf0, 0x1f, 0x00,
  0x00, 0xf8, 0xff, 0x00, 0x00, 0x0c, 0x40, 0xe1, 0xbf, 0x7e, 0x78, 0x00, 0x00, 0xfc, 0x0f, 0x00,
  0x00, 0xf8, 0xff, 0x00, 0x00, 0x00, 0xc0, 0xff, 0x7f, 0x7e, 0x08, 0x00, 0x00, 0xff, 0x01, 0x00,
  0x00, 0xf8, 0xff, 0x00, 0x00, 0x02, 0x80, 0x7f, 0xff, 0x3c, 0x00, 0x00, 0x00, 0x3f, 0x00, 0x00,
  0x00, 0x08, 0x00, 0x00, 0x00, 0x00, 0x40, 0xff, 0xf3, 0x72, 0x00, 0x00, 0x00, 0x0f, 0x00, 0x00,
  0x00, 0x08, 0x00, 0x00, 0x80, 0x00, 0x00, 0x18, 0xf8, 0x63, 0x40, 0x00, 0x00, 0x01, 0x00, 0x00,
  0x00, 0x18, 0x00, 0x00, 0x40, 0x11, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0xf8, 0x00, 0x00, 0x00, 0x70, 0x00, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x10, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x7d, 0x00, 0x00, 0x20, 0x00, 0x04, 0x00, 0x00, 0xff, 0x1f, 0x00,
  0x00, 0x00, 0x40, 0x00, 0xa0, 0x4e, 0x00, 0x00, 0x20, 0x00, 0x04, 0x00, 0x00, 0xff, 0x1f, 0x00,
  0x00, 0xe0, 0x80, 0x00, 0x00, 0x0d, 0x00, 0x04, 0x40, 0x01, 0x00, 0x00, 0x00, 0xff, 0x1f, 0x00,
  0x00, 0xf0, 0xfd, 0x00, 0x00, 0x07, 0x00, 0x02, 0x40, 0x41, 0x00, 0x00, 0x00, 0x41, 0x10, 0x00,
  0x00, 0xf0, 0xfd, 0x00, 0x80, 0xe1, 0x01, 0x00, 0xff, 0x9c, 0x00, 0x00, 0x00, 0x40, 0x10, 0x00,
  0x00, 0xf8, 0xff, 0x00, 0xe0, 0xe8, 0x13, 0xc0, 0xe4, 0xb7, 0x00, 0x00, 0x00, 0x40, 0x10, 0x00,
  0x00, 0x08, 0x02, 0x00, 0xe0, 0xff, 0x00, 0x80, 0xc5, 0x7f, 0x00, 0x00, 0x00, 0xff, 0x1f, 0x00,
  0x00, 0x08, 0x02, 0x00, 0x70, 0x60, 0x00, 0x60, 0x68, 0xff, 0x02, 0x00, 0x00, 0xbf, 0x0f, 0x00,
  0x00, 0x08, 0x82, 0x00, 0xf0, 0x12, 0x00, 0x10, 0x70, 0x7c, 0x00, 0x00, 0x00, 0xbf, 0x0f, 0x00,
  0x00, 0xf8, 0xff, 0x00, 0xf8, 0x96, 0x00, 0x00, 0xb8, 0x00, 0xc0, 0x00, 0x00, 0x01, 0x07, 0x00,
  0x00, 0xf8, 0xff, 0x00, 0xf8, 0x09, 0x02, 0x00, 0xf0, 0x03, 0xc0, 0x00, 0x00, 0x02, 0x00, 0x00,
  0x00, 0xf8, 0xff, 0x00, 0xe8, 0x03, 0x40, 0x00, 0xe0, 0x51, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x08, 0x00, 0x00, 0xf0, 0x02, 0x00, 0x00, 0xf2, 0x2f, 0x00, 0x00, 0x00, 0x00, 0x1f, 0x00,
  0x00, 0x00, 0x00, 0x00, 0xe0, 0x03, 0x00, 0x00, 0xdc, 0xd7, 0x01, 0x00, 0x00, 0x00, 0x18, 0x00,
  0x00, 0x00, 0x80, 0x00, 0x60, 0x01, 0x00, 0x00, 0xeb, 0x32, 0x01, 0x00, 0x00, 0x00, 0x10, 0x00,
  0x00, 0x00, 0xf0, 0x00, 0xc0, 0x02, 0x00, 0x00, 0x5e, 0x78, 0x20, 0x00, 0x00, 0x00, 0x10, 0x00,
  0x00, 0x00, 0xfc, 0x00, 0xf0, 0x00, 0x80, 0xc0, 0x88, 0x49, 0x00, 0x00, 0x00, 0xff, 0x1f, 0x00,
  0x00, 0x80, 0xff, 0x00, 0x60, 0x00, 0xc0, 0x00, 0x0c, 0xf1, 0x00, 0x00, 0x00, 0xff, 0x1f, 0x00,
  0x00, 0xf0, 0x3f, 0x00, 0x60, 0x02, 0x81, 0xfc, 0x0a, 0x0e, 0x00, 0x01, 0x00, 0xff, 0x1f, 0x00,
  0x00, 0xf8, 0x0f, 0x00, 0x40, 0x6e, 0x61, 0xc0, 0x10, 0x08, 0xa8, 0x01, 0x00, 0x00, 0x10, 0x00,
  0x00, 0xf0, 0x09, 0x00, 0xc0, 0xe8, 0x3f, 0x05, 0x01, 0x44, 0xe0, 0x00, 0x00, 0x00, 0x10, 0x00,
  0x00, 0xc0, 0x08, 0x00, 0xc0, 0x00, 0xff, 0x02, 0x00, 0x40, 0x02, 0x00, 0x00, 0x00, 0x18, 0x00,
  0x00, 0x00, 0x0a, 0x00, 0x80, 0x01, 0xfe, 0x05, 0x00, 0x00, 0x33, 0x00, 0x00, 0x00, 0x1e, 0x00,
  0x00, 0x00, 0x10, 0x00, 0x00, 0x41, 0x7c, 0x02, 0x82, 0x02, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0xc0, 0x00, 0x00, 0x02, 0xd8, 0x00, 0x07, 0x82, 0x1f, 0x00, 0x00, 0x00, 0x10, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x40, 0x49, 0x1e, 0x8a, 0x07, 0x00, 0x00, 0xff, 0x1f, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 0x01, 0x70, 0x49, 0x1e, 0x10, 0x00, 0x00, 0xff, 0x1f, 0x00,
  0x00, 0x78, 0xe0, 0x00, 0x00, 0x20, 0xc4, 0xc5, 0x0f, 0x0f, 0x0f, 0x00, 0x00, 0xff, 0x1f, 0x00,
  0x00, 0x18, 0xc0, 0x00, 0x00, 0xc0, 0x03, 0xec, 0x5f, 0x5d, 0x00, 0x00, 0x00, 0xff, 0x1f, 0x00,
  0x00, 0x08, 0x8f, 0x00, 0x00, 0x00, 0xff, 0xfe, 0xff, 0xb7, 0x01, 0x00, 0x00, 0x40, 0x10, 0x00,
  0x00, 0x08, 0x82, 0x00, 0x00, 0x00, 0xfc, 0xff, 0xf7, 0xff, 0x00, 0x00, 0x00, 0x40, 0x00, 0x00,
  0x00, 0x08, 0x02, 0x00, 0x00, 0x00, 0xfc, 0xff, 0xf7, 0x3f, 0x00, 0x00, 0x00, 0x40, 0x10, 0x00,
  0x00, 0xf8, 0xff, 0x00, 0x00, 0x00, 0xf0, 0xff, 0xf1, 0x0f, 0x00, 0x00, 0x00, 0xff, 0x1f, 0x00,
  0x00, 0xf8, 0xff, 0x00, 0x00, 0x00, 0xe0, 0xff, 0xf3, 0x00, 0x00, 0x00, 0x00, 0xff, 0x1f, 0x00,
  0x00, 0xf8, 0xff, 0x00, 0x00, 0x00, 0x00, 0x3f, 0x4e, 0x00, 0x00, 0x00, 0x00, 0xff, 0x1f, 0x00,
  0x00, 0xf8, 0xff, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x07, 0x00, 0x00, 0x00, 0x00, 0xff, 0x1f, 0x00,
  0x00, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

static const unsigned char inventrCorpLogoBitmap[] U8X8_PROGMEM = {
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0xf0, 0x01, 0x00, 0x00, 0x00, 0x00, 0xf0, 0x01, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0xfc, 0x07, 0x00, 0x00, 0x00, 0x00, 0xf8,
  0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xfe, 0x07, 0x00,
  0x00, 0x00, 0x00, 0xfc, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0xff, 0x0f, 0x00, 0x00, 0x07, 0x00, 0xfe, 0x3f, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x80, 0xff, 0x0f, 0x00, 0xc0, 0x1f, 0x00, 0xfe,
  0x7f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0xff, 0x0f, 0x00,
  0xe0, 0x3f, 0x00, 0xfe, 0xff, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0xe0, 0xff, 0x0f, 0x00, 0xf0, 0x7f, 0x00, 0xfe, 0xff, 0x03, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0xf0, 0xff, 0x0f, 0x00, 0xf0, 0x7f, 0x00, 0xfe,
  0xff, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf8, 0xff, 0x07, 0x00,
  0xf0, 0x7f, 0x00, 0xfc, 0xff, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0xfc, 0xff, 0x07, 0x00, 0xf8, 0x7f, 0x00, 0xfc, 0xff, 0x7f, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0xfe, 0xff, 0x03, 0x00, 0xf8, 0x7f, 0x38, 0xf0,
  0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0x01, 0x00,
  0xfc, 0x7f, 0x78, 0xe0, 0xff, 0xff, 0x03, 0x00, 0x00, 0x00, 0x00, 0x80,
  0xff, 0xff, 0x00, 0x00, 0xfc, 0x3f, 0xfc, 0xc1, 0xff, 0xff, 0x07, 0x00,
  0x00, 0x00, 0x00, 0xc0, 0xff, 0x7f, 0x00, 0x00, 0xfe, 0x3f, 0xfc, 0x03,
  0xff, 0xff, 0x0f, 0x00, 0x00, 0x00, 0x00, 0xe0, 0xff, 0x1f, 0x00, 0x03,
  0xfe, 0x1f, 0xfe, 0x0f, 0xfe, 0xff, 0x3f, 0x00, 0x00, 0x00, 0x00, 0xf0,
  0xff, 0x0f, 0x80, 0x03, 0xfe, 0x1f, 0xfe, 0x1f, 0xf8, 0xff, 0x7f, 0x00,
  0x00, 0x00, 0x00, 0xf8, 0xff, 0x07, 0x8c, 0x03, 0xff, 0x1f, 0xff, 0x7f,
  0xf0, 0xff, 0xff, 0x01, 0x00, 0x00, 0x00, 0xfc, 0xff, 0x07, 0x1f, 0x00,
  0xff, 0x0f, 0xff, 0xff, 0xc0, 0xff, 0xff, 0x03, 0x00, 0x00, 0x00, 0xfe,
  0xff, 0x03, 0x1f, 0x80, 0xff, 0x8f, 0xff, 0xff, 0x83, 0xff, 0xff, 0x03,
  0x00, 0x00, 0x00, 0xff, 0xff, 0x01, 0x1f, 0x80, 0xff, 0x87, 0xff, 0xff,
  0x07, 0xfe, 0xff, 0x07, 0x00, 0x00, 0x80, 0xff, 0xff, 0x00, 0x1e, 0xc0,
  0xff, 0x87, 0xff, 0xff, 0x1f, 0xfc, 0xff, 0x07, 0x00, 0x00, 0xc0, 0xff,
  0x7f, 0x38, 0xc0, 0xc0, 0xff, 0xc3, 0xff, 0xff, 0x3f, 0xf0, 0xff, 0x07,
  0x00, 0x00, 0xe0, 0xff, 0x3f, 0xfc, 0xc0, 0xc0, 0xff, 0xc3, 0xff, 0xff,
  0x7f, 0xf8, 0xff, 0x03, 0x00, 0x00, 0xf0, 0xff, 0x1f, 0xfe, 0x01, 0xe0,
  0xff, 0xe3, 0xff, 0xff, 0x3f, 0xfc, 0xff, 0x03, 0x00, 0x00, 0xf0, 0xff,
  0x0f, 0xff, 0x03, 0xe0, 0xff, 0xe1, 0xff, 0xf3, 0x1f, 0xfe, 0xff, 0x01,
  0x00, 0x00, 0xfc, 0xff, 0x87, 0xff, 0x03, 0xf0, 0xff, 0xf1, 0xc3, 0xe3,
  0x0f, 0xff, 0xff, 0x00, 0x00, 0x00, 0xfe, 0xff, 0xc3, 0xff, 0x07, 0xf0,
  0xff, 0xf0, 0xc1, 0xe3, 0x87, 0xff, 0x7f, 0x00, 0x00, 0x00, 0xff, 0xff,
  0xe1, 0xe7, 0x0f, 0xf8, 0xff, 0xf8, 0xc1, 0xf3, 0xc3, 0xff, 0x3f, 0x00,
  0x00, 0x80, 0xff, 0xff, 0xf0, 0xe7, 0xff, 0xf8, 0x7f, 0xf8, 0xe3, 0xff,
  0xe1, 0xff, 0x1f, 0x00, 0x00, 0xc0, 0xff, 0x7f, 0xf8, 0xff, 0x7f, 0xfc,
  0x7f, 0xfc, 0xff, 0xff, 0xf0, 0xff, 0x0f, 0x00, 0x00, 0xe0, 0xff, 0x3f,
  0xfc, 0xff, 0x7f, 0xfc, 0x7f, 0xfc, 0xff, 0x7f, 0xf8, 0xff, 0x07, 0x00,
  0x00, 0xf0, 0xff, 0x1f, 0xfe, 0xff, 0x3f, 0xfc, 0x3f, 0xfc, 0xff, 0x3f,
  0xfc, 0xff, 0x03, 0x00, 0x00, 0xf8, 0xff, 0x0f, 0xff, 0xcf, 0x3f, 0xfe,
  0x3f, 0xfe, 0xff, 0x1f, 0xfe, 0xff, 0x01, 0x00, 0x00, 0xf8, 0xff, 0x87,
  0xff, 0x87, 0x1f, 0xfe, 0x1f, 0xfa, 0xcf, 0x0f, 0xff, 0xff, 0x00, 0x00,
  0x00, 0xfc, 0xff, 0xc3, 0x8f, 0x87, 0x1f, 0xff, 0x1f, 0xe0, 0xcf, 0x87,
  0xff, 0x7f, 0x00, 0x00, 0x00, 0xfe, 0xff, 0xe1, 0x87, 0x87, 0x1f, 0xff,
  0x0f, 0xc0, 0xff, 0xc3, 0xff, 0x3f, 0x00, 0x00, 0x80, 0xff, 0xff, 0xf0,
  0x8f, 0xcf, 0x8f, 0xff, 0x0f, 0x80, 0xff, 0xe1, 0xff, 0x1f, 0x00, 0x00,
  0x80, 0xff, 0x7f, 0xf8, 0xff, 0xff, 0x8f, 0xff, 0x07, 0x80, 0xff, 0xf0,
  0xff, 0x0f, 0x00, 0x00, 0xc0, 0xff, 0x3f, 0xfc, 0xff, 0xff, 0xc7, 0xff,
  0x07, 0x02, 0x7f, 0xf8, 0xff, 0x07, 0x00, 0x00, 0xc0, 0xff, 0x1f, 0xfe,
  0xff, 0xff, 0xc7, 0xff, 0x07, 0x07, 0x3e, 0xfc, 0xff, 0x03, 0x00, 0x00,
  0xc0, 0xff, 0x3f, 0xf8, 0xff, 0xff, 0xc3, 0xff, 0x03, 0x72, 0x00, 0xfe,
  0xff, 0x01, 0x00, 0x00, 0xc0, 0xff, 0x7f, 0xf0, 0xff, 0xff, 0xe3, 0xff,
  0x03, 0xf0, 0x00, 0xff, 0xff, 0x00, 0x00, 0x00, 0xc0, 0xff, 0xff, 0xc1,
  0xff, 0xff, 0xe1, 0xff, 0x01, 0xf8, 0x81, 0xff, 0x7f, 0x00, 0x00, 0x00,
  0x80, 0xff, 0xff, 0x83, 0xff, 0xff, 0xf1, 0xff, 0x01, 0xf8, 0xc0, 0xff,
  0x3f, 0x00, 0x00, 0x00, 0x80, 0xff, 0xff, 0x0f, 0xfe, 0xff, 0xf0, 0xff,
  0x80, 0xf1, 0xe0, 0xff, 0x1f, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0x1f,
  0xfc, 0xff, 0xf0, 0xff, 0xc0, 0x01, 0xf0, 0xff, 0x1f, 0x00, 0x00, 0x00,
  0x00, 0xfc, 0xff, 0x3f, 0xf0, 0x7f, 0xf8, 0xff, 0xc0, 0x01, 0xf8, 0xff,
  0x07, 0x00, 0x00, 0x00, 0x00, 0xf8, 0xff, 0xff, 0xc0, 0x7f, 0xf8, 0x7f,
  0x00, 0x00, 0xfc, 0xff, 0x03, 0x00, 0x00, 0x00, 0x00, 0xe0, 0xff, 0xff,
  0x81, 0x7f, 0xfc, 0x7f, 0x00, 0x00, 0xfe, 0xff, 0x01, 0x00, 0x00, 0x00,
  0x00, 0xc0, 0xff, 0xff, 0x07, 0x3e, 0xfc, 0x3f, 0x00, 0x00, 0xff, 0xff,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0x0f, 0x3c, 0xfe, 0x3f,
  0x00, 0x80, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xfe, 0xff,
  0x3f, 0x18, 0xfe, 0x1f, 0x00, 0xc0, 0xff, 0x7f, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0xf8, 0xff, 0x7f, 0x00, 0xff, 0x1f, 0x00, 0xe0, 0xff, 0x3f,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf0, 0xff, 0x7f, 0x00, 0xff, 0x1f,
  0x00, 0xe0, 0xff, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0xff,
  0x7f, 0x00, 0xff, 0x0f, 0x00, 0xf0, 0xff, 0x0f, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x80, 0xff, 0xff, 0x00, 0xff, 0x0f, 0x00, 0xf0, 0xff, 0x07,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xfe, 0x7f, 0x00, 0xff, 0x07,
  0x00, 0xf0, 0xff, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xfc,
  0x7f, 0x00, 0xfe, 0x07, 0x00, 0xe0, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0xf0, 0x7f, 0x00, 0xfc, 0x03, 0x00, 0xe0, 0x7f, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x3f, 0x00, 0xf8, 0x00,
  0x00, 0xc0, 0x3f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80,
  0x1f, 0x00, 0x00, 0x00, 0x00, 0x80, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 0x00,
  0x00, 0x00, 0x00, 0x00
};