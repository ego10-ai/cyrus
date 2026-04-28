#include <Arduino.h>
#include <U8g2lib.h>
#include <Wire.h>

// Initialize the display
U8G2_SSD1306_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, /* reset=*/ U8X8_PIN_NONE, /* clock=*/ 9, /* data=*/ 8);

// Button Pins (Add these to your Wokwi diagram)
const int BTN_UP = 4;
const int BTN_DOWN = 5;

// Define the UI States
enum SystemState {
  STATE_BOOT,
  STATE_MAIN_MENU,
  STATE_LORA_SNIFFER
};

// Global variable to track where we are
SystemState currentState = STATE_BOOT;

// Menu tracking
int menuIndex = 0;
const int totalMenuItems = 2;

void setup(void) {
  pinMode(BTN_UP, INPUT_PULLUP);
  pinMode(BTN_DOWN, INPUT_PULLUP);
  
  u8g2.begin();
}

void drawBootScreen() {
  u8g2.setFont(u8g2_font_ncenB08_tr);	
  u8g2.drawStr(10, 30, "CYRUS TERMINAL");	
  u8g2.drawStr(10, 45, "SYSTEM BOOT...");
}

void drawMainMenu() {
  u8g2.setFont(u8g2_font_ncenB08_tr);
  u8g2.drawStr(0, 15, "--- MAIN MENU ---");

  // Highlight the selected item
  if (menuIndex == 0) u8g2.drawStr(10, 35, "> Inbox");
  else u8g2.drawStr(10, 35, "  Inbox");

  if (menuIndex == 1) u8g2.drawStr(10, 50, "> LoRa Sniffer");
  else u8g2.drawStr(10, 50, "  LoRa Sniffer");
}

void loop(void) {
  // 1. Read Inputs
  bool upPressed = (digitalRead(BTN_UP) == LOW);
  bool downPressed = (digitalRead(BTN_DOWN) == LOW);

  // 2. Update Logic based on State
  if (currentState == STATE_BOOT) {
    // Show boot screen for 2 seconds, then switch to menu
    if (millis() > 2000) {
      currentState = STATE_MAIN_MENU;
    }
  } 
  else if (currentState == STATE_MAIN_MENU) {
    if (downPressed) {
      menuIndex++;
      if (menuIndex >= totalMenuItems) menuIndex = 0; // Wrap around
      delay(200); // Simple debounce
    }
    if (upPressed) {
      menuIndex--;
      if (menuIndex < 0) menuIndex = totalMenuItems - 1; // Wrap around
      delay(200); // Simple debounce
    }
  }

  // 3. Draw the Screen
  u8g2.clearBuffer();					
  
  if (currentState == STATE_BOOT) {
    drawBootScreen();
  } else if (currentState == STATE_MAIN_MENU) {
    drawMainMenu();
  }

  u8g2.sendBuffer();					
}