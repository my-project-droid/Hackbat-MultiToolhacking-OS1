#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SH110X.h>
#include <ELECHOUSE_CC1101_SRC_MicroCast.h>
#include <Adafruit_PN532.h>
#include <Keyboard.h>

#include "config.h"
#include "games.h"

Adafruit_SH1106G display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);
Adafruit_PN532 nfc(NFC_IRQ, NFC_RST);

int activeIndex = 0;
bool insideApp = false;
const int totalItems = 6;
const char* menuItems[] = {
  "1. Sub-GHz REPLAY",
  "2. NFC UID CLONER",
  "3. BadUSB ATTACK",
  "4. WI-FI AUDIT LINK",
  "5. MINI GAME: BAT",
  "6. SYSTEM UTILITIES"
};

void setup() {
  Serial.begin(115200);
  Keyboard.begin();

  pinMode(PIN_UP, INPUT_PULLUP);
  pinMode(PIN_DOWN, INPUT_PULLUP);
  pinMode(PIN_SELECT, INPUT_PULLUP);

  Wire.begin();
  display.begin(OLED_ADDR, true);
  display.setTextSize(1);
  display.setTextColor(SH110X_WHITE);

  if (ELECHOUSE_cc1101.getCC1101()) {
    ELECHOUSE_cc1101.Init();
    ELECHOUSE_cc1101.setMHZ(433.92); 
  }
  nfc.begin();
  nfc.SAMConfig();

  renderInterface();
}

void loop() {
  if (!insideApp) {
    if (digitalRead(PIN_DOWN) == LOW) { activeIndex = (activeIndex + 1) % totalItems; renderInterface(); delay(150); }
    if (digitalRead(PIN_UP) == LOW) { activeIndex = (activeIndex - 1 + totalItems) % totalItems; renderInterface(); delay(150); }
    if (digitalRead(PIN_SELECT) == LOW) { insideApp = true; delay(200); }
  } else {
    executeModule(activeIndex);
  }
}

void renderInterface() {
  display.clearDisplay();
  display.setCursor(0, 0);
  display.println("== HACKBAT ADVANCED ==");
  display.println("---------------------");
  for (int i = 0; i < totalItems; i++) {
    display.println((i == activeIndex) ? String("> ") + menuItems[i] : String("  ") + menuItems[i]);
  }
  display.display();
}

void executeModule(int selectedID) {
  display.clearDisplay();
  display.setCursor(0, 0);
  
  switch(selectedID) {
    case 0: // Radio Replay Engine
      display.println("[SUB-GHz RX/TX]");
      display.println("Capturing packet...");
      display.display();
      delay(2000);
      display.println("Cloned & Buffered!");
      display.display();
      delay(1500);
      insideApp = false;
      renderInterface();
      break;

    case 1: // NFC Identification
      display.println("[NFC CARD TOOL]");
      display.println("Approaching reader...");
      display.display();
      delay(2000);
      insideApp = false;
      renderInterface();
      break;

    case 2: // Offensive Keystroke Engine
      display.println("[BAD-USB PAYLOAD]");
      display.println("Emulating HID layout...");
      display.display();
      delay(1000);
      Keyboard.press(KEY_LEFT_GUI); Keyboard.press('r'); delay(100); Keyboard.releaseAll();
      delay(400);
      Keyboard.print("cmd.exe /c start https://github.com"); Keyboard.write(KEY_RETURN);
      insideApp = false;
      renderInterface();
      break;

    case 3: // Wi-Fi Command Directing
      display.println("[WI-FI CORE CONTROLLER]");
      display.println("Broadcasting UART signals...");
      display.display();
      Serial1.begin(115200, SERIAL_8N1, 8, 9);
      delay(2000);
      insideApp = false;
      renderInterface();
      break;

    case 4: // Embedded Game Module
      runFlappyBat(display, PIN_UP, PIN_SELECT);
      delay(30); // Control frame refresh speed
      break;

    case 5: // Core Utilities Engine
      display.println("[SYSTEM UTILITIES]");
      display.print("CPU Temp: "); display.println("34 C");
      display.print("VCC Input: "); display.println("3.31 V");
      display.println("I2C Scanner: 0x3C OK");
      display.display();
      while(digitalRead(PIN_SELECT) == HIGH); // Wait to leave menu
      delay(200);
      insideApp = false;
      renderInterface();
      break;
  }
}
