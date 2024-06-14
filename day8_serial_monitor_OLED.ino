/*
 * 30 Days - Lost in Space
 * Day 8 - Adding some color to this dark place
 *
 * Learn more at https://learn.inventr.io/adventure
 *
 * Previously we have used different color LEDs with our HERO, but when we require
 * more output, or desire a color different from the available colors we use a more
 * flexible "RGB LED".  RGB LEDs have a red, a green and a blue LED packaged into a
 * single LED package.  By using something called Pulse Width Modulation (PWM) we
 * can vary the intensity of each LED and come up a wide variety of colors.
 *
 * Alex Eschenauer
 * David Schmidt
 * Greg Lyzenga
 */

/*
 * Arduino concepts introduced/documented in this lesson.
 * - analogWrite(): Used to control a PWM pin, giving a variable intensity
 * - Passing variables into functions
 *
 * Parts and electronics concepts introduced in this lesson.
 * - Common Cathode (single grounded pin) RGB LED.
 */

// Explicitly include Arduino.h
#include "Arduino.h"

#include <U8g2lib.h>  // Include file for the U8g2 library.

/*
 * The U8g2 library supports many different types of display.  It does this by
 * having a different "constructor" for each.  A constructor is used to create
 * the "handle" that we use to access the libray code.  In this case, our handle
 * will be named "lander_display".
 *
 * The documentation for this library lists all of the displays supported along
 * with the corresponding constructors and options.  This constructor is for our
 * SH1106, 128x64 pixel generic display.  The "_F_" indicates that we will use
 * a full-sized graphics buffer and the clearBuffer()/sendBuffer() methods to
 * update the entire display at once. The "HW_I2C" indicates that we will be using
 * I2C communications with this display.
 */
U8G2_SH1106_128X64_NONAME_F_HW_I2C lander_display(U8G2_R0, /* reset=*/U8X8_PIN_NONE);

/*
 * Each color in an RGB LED is controlled with a different pin on our HERO board.
 *
 * NOTE: Only pins 3, 5, 6, 9, 10 and 11 on the HERO board support PWM which is
 *       indicated on the board by preceding those pin numbers on the HERO board
 *       with a tilde ('~') character.  Only those pins support PWM and analogWrite().
 */
const byte RED_PIN = 11;    // PWM pin controlling the red leg of our RGB LED
const byte GREEN_PIN = 10;  // PWM pin ccontrolling the green leg of our RGB LED
const byte BLUE_PIN = 9;    // PWM pin ccontrolling the blue leg of our RGB LED

/*
 * Define a set of constants to represent 4 different brightness levels for our
 * RGB LED using PWM pins and analogWrite().  PWM can set values ranging from 0
 * to 255 which we will demonstrate by adding 64 (roughly 1/4 of that range) to
 * each preceding value.
 *
 * NOTE: this also demonstrates that our constants can be computed using an expression
 *       that includes any previouly defined constant.  However, the expression cannot
 *       include variables or values that could change during execution.
 */
const byte OFF = 0;                 // Selected color is OFF
const byte DIM = 64;                // Selected color is 1/4 intensity
const byte BRIGHTER = DIM + 64;     // Selected color is 1/2 intensity
const byte BRIGHT = BRIGHTER + 64;  // Selected color is 3/4 intensity
const byte BRIGHTEST = 255;         // Selected color is maximum intensity (255)

// We can change this constant here, in one place, to change how long each color is displayed.
const unsigned int COLOR_DELAY = 2000;  // show each color for 500 milliseconds

void setup() {
  // Set each of our PWM pins as OUTPUT pins
  pinMode(RED_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(BLUE_PIN, OUTPUT);

  // Initialize Serial Montitor (9600) to display colors
  Serial.begin(9600);
  delay(1000);
  lander_display.begin();  // Initialize our display

  // Select a font to use for character display
  // The library supports hundreds of different fonts which can be found at
  // https://github.com/olikraus/u8g2/wiki/fntlistall
  lander_display.setFont(u8g2_font_ncenB08_tr);  // choose a suitable font

  // Uncomment the next line if your display shows the text upside down.
  // lander_display.setDisplayRotation(U8G2_R2);
}

// Each time through loop() we display some of the color variations available
// using an RGB LED.
void loop() {

    // Save the number of vertical pixels required for the tallest character
  // in the current font.  This is used later to properly position text on
  // our display.
  byte font_height = lander_display.getMaxCharHeight();

  lander_display.clearBuffer();  // clear the internal memory

  /*
   * Even though we will only be displaying text in this lesson, our display is a
   * graphics display.  Text can be displayed at ANY point on the display so the
   * library has a setCursor() function to locate the first character to be displayed.
   *
   * By default, the cursor position is set to the bit at the lower-left of the
   * first character, but here we set this to be the UPPER-left of the first
   * character which makes it easier to position our first line of text on the top
   * of our display.
   */
  lander_display.setFontPosTop();

  // Title line for our display
  drawCenteredString(0, "Current Color");
  byte centered_y = (font_height * 2) + ((lander_display.getDisplayHeight() - (font_height * 2)) / 2);
  // This statement instructs the graphics library that the Y coordinate used to position
  // the text will be halfway between the top and bottom of the text.
  lander_display.setFontPosCenter();  // Draw text with centered Y coordinate

  // First demonstrate our different PWM levels by slowly brightening our red LED
  displayColor(OFF, OFF, OFF);  // OFF!
  drawCenteredString(centered_y, "Off");
  lander_display.sendBuffer();  // transfer internal memory to the display
  Serial.println("OFF");
  delay(COLOR_DELAY);
  lander_display.clearBuffer();  // clear the internal memory

  displayColor(DIM, OFF, OFF);  // Display red LED at 1/4 intensity
  drawCenteredString(centered_y, "25% RED");
  lander_display.sendBuffer();  // transfer internal memory to the display
  Serial.println("1/4 RED");
  delay(COLOR_DELAY);
  lander_display.clearBuffer();  // clear the internal memory

  displayColor(BRIGHTER, OFF, OFF);  // Display red LED at 1/2 intensity
  drawCenteredString(centered_y, "50% RED");
  lander_display.sendBuffer();  // transfer internal memory to the display
  Serial.println("1/2 RED");
  delay(COLOR_DELAY);
  lander_display.clearBuffer();  // clear the internal memory

  displayColor(BRIGHT, OFF, OFF);  // Display red LED at 3/4 intensity
  drawCenteredString(centered_y, "75% RED");
  lander_display.sendBuffer();  // transfer internal memory to the display
  Serial.println("3/4 RED");
  delay(COLOR_DELAY);
  lander_display.clearBuffer();  // clear the internal memory

  displayColor(BRIGHTEST, OFF, OFF);  // Display red LED at FULL intensity
  drawCenteredString(centered_y, "100% RED");
  lander_display.sendBuffer();  // transfer internal memory to the display
  Serial.println("FULL RED");
  delay(COLOR_DELAY);
  lander_display.clearBuffer();  // clear the internal memory


  // Display our other two LED colors at half intensity
  displayColor(OFF, BRIGHT, OFF);  // Display the green LED
  Serial.println("3/4 GREEN");
  delay(COLOR_DELAY);
  displayColor(OFF, OFF, BRIGHT);  // Display the blue LED
  Serial.println("3/4 BLUE");
  delay(COLOR_DELAY);

  // Now show various colors (at half intensity) by mixing our three colors
  displayColor(BRIGHT, BRIGHT, OFF);  // Display yellow by mixing red and green LEDs
  Serial.println("YELLOW");
  delay(COLOR_DELAY);
  displayColor(OFF, BRIGHT, BRIGHT);  // Display cyan by mixing green and blue LEDs
  Serial.println("CYAN");
  delay(COLOR_DELAY);
  displayColor(BRIGHT, OFF, BRIGHT);  // Display magenta by mixing red and blue LEDs
  Serial.println("MAGENTA");
  delay(COLOR_DELAY);

  // Display all of our LEDs to get white.
  displayColor(BRIGHT, BRIGHT, BRIGHT);  // white
  Serial.println("WHITE");
  delay(COLOR_DELAY);
}

/*
 * displayColor() is a function that accepts three parameters representing the desired
 * intensity for each of the LEDs in the RGB LED.
 *
 * Each parameter passed must have a type (here we match what analogWrite() will use) and
 * a name to be used inside the function to refer to the parameter.  The parameters can all
 * be included on a single line like:
 * void displayColor( byte red_intensity, byte green_intensity, byte blue_intensity) {
 * 
 * However, if we display each parameter on it's own line we can add a comment to each
 * for additional clarity.
 */
void displayColor(
  byte red_intensity,    // red LED intensity (0-255)
  byte green_intensity,  // green LED intensity (0-255)
  byte blue_intensity    // blue LED intensity (0-255)
) {
  analogWrite(RED_PIN, red_intensity);      // Set red LED intensity using PWM
  analogWrite(GREEN_PIN, green_intensity);  // Set green LED intensity using PWM
  analogWrite(BLUE_PIN, blue_intensity);    // Set blue LED intensity using PWM
}

byte drawCenteredString(byte y, char *string) {
  byte centered_x = (lander_display.getDisplayWidth() - lander_display.getStrWidth(string)) / 2;
  lander_display.drawStr(centered_x, y, string);
}