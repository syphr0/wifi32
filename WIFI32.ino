/* ____________________________
   This software is licensed under the MIT License:
   https://github.com/cifertech/ESP32-DIV
   ________________________________________  */

#include <Adafruit_GFX.h>
#include <Adafruit_ST7735.h>
#include <Adafruit_NeoPixel.h>

#include "HCScreen.h"
#include "packetmonitor.h"
#include "detector.h"
#include "wifiscanner.h"
#include "beaconspam.h"

#include <SPI.h>

#include "icons.h"   // Different icons and logos displayed

#define TFT_CS 14    // TFT Chip Select 
#define TFT_RST 33   // TFT Reset
#define TFT_DC 27    // TFT Data/Command

#define TFT_MOSI 23  // TFT Data out
#define TFT_SCLK 18  // TFT Clock out

#define BTDOWNDTN 25 // Button Select
#define BTUP 21      // Button Up
#define BTDOWND 22   // Button Down
#define BACK 26      // Button Back

#define MAIN_MENU 0
#define SUB_MENU 1

String main_menu[] = {"1.Wifi Analyzer", "2.Packet Monitor", "3.Beacon Spam", "4.Deauth Detector"};
uint8_t main_menu_cnt = 4;

volatile int whichMenu = 0;
String lastPath = "";

Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_MOSI, TFT_SCLK, TFT_RST);
// Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_RST); // Appears to not work by default.
HCScreen screen = HCScreen(tft);

Adafruit_NeoPixel pixels(1, 4, NEO_GRB + NEO_KHZ800);

String selection = screen.getSelection();
int8_t selectionIndex = screen.getSelectionIndex();

// Function pointers for setup and loop functions
void (*setupFunctions[])(void) = {wifiscannerSetup, packetmonitorSetup, beaconspamSetup, detectorSetup};
void (*loopFunctions[])(void) = {wifiscannerLoop, packetmonitorLoop, beaconspamLoop, detectorLoop};

const uint16_t ORANGE = 0xba6525;
// const uint16_t ORANGE = 0xff9514;
const uint16_t WHITE = 0xf0f0f0;
const uint16_t PURPLE = 0x7b21db;
const uint16_t DARKPURPLE = 0x6614d9;

void setup() {
  Serial.begin(115200);

  pixels.begin();

  tft.initR(INITR_BLACKTAB);
  tft.fillScreen(ST7735_BLACK);
  tft.setRotation(0);

  // tft.drawBitmap(12, 5, skull1, 100, 100,ORANGE);
  // tft.drawBitmap(12, 5, animeminiBitmap, 100, 100,ORANGE);
  // tft.drawBitmap(12, 5, animeminiBitmap, 100, 100,ORANGE);
  tft.drawBitmap(0, 0, sypherBitmap, 120, 120, 0xffffff);

  tft.setTextWrap(false);
  tft.setCursor(10, 110);
  tft.setTextColor(WHITE);
  tft.setTextSize(1);
  tft.println("ESP32 HackOne");
  tft.setCursor(10, 120);
  tft.setTextSize(2);
  tft.println("Sypher0");
  tft.setCursor(45, 140);
  tft.setTextSize(1);
  tft.println("Alpha Version");

    delay(3000);


  tft.fillScreen(ST7735_BLACK);

  screen.setMenu(main_menu, main_menu_cnt);
  screen.setTitle("[ESP32 HackOne]");
  screen.setLineHeight(12);

  pinMode(BTDOWNDTN, INPUT_PULLUP);
  pinMode(BTUP, INPUT_PULLUP);
  pinMode(BTDOWND, INPUT_PULLUP);
  pinMode(BACK, INPUT_PULLUP);
}

void loop() {
  String selection = screen.getSelection();
  int8_t selectionIndex = screen.getSelectionIndex();

  if (digitalRead(BTUP) == 0) {
    screen.selectNext();
      pixels.setPixelColor(0, pixels.Color(255, 125, 0));
      pixels.show();     
      pixels.setPixelColor(0, pixels.Color(0, 0, 0));
      pixels.show();    
  }
  if (digitalRead(BTDOWND) == 0) {
    screen.selectPrevious();
      pixels.setPixelColor(0, pixels.Color(255, 125, 0));
      pixels.show();     
      pixels.setPixelColor(0, pixels.Color(0, 0, 0));
      pixels.show();    
  }

  if (digitalRead(BACK) == 0) {
    screen.setMenu(main_menu, main_menu_cnt);
    whichMenu = MAIN_MENU;
  }

  if (digitalRead(BTDOWNDTN) == 0) {
    while (digitalRead(BTDOWNDTN) == 0)
      delay(100);

    if (selection == "Back") {
      screen.setMenu(main_menu, main_menu_cnt);
      whichMenu = MAIN_MENU;
    }

    if (selectionIndex >= 0 && selectionIndex < main_menu_cnt) {
      // Execute the selected setup and loop functions
      setupFunctions[selectionIndex]();
      while (selection == main_menu[selectionIndex]) {
        loopFunctions[selectionIndex]();
        if (digitalRead(BACK) == 0) {
          screen.setMenu(main_menu, main_menu_cnt);
          break;
        }
      }
    }
  }
}
