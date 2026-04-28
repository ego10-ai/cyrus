#include <Arduino.h>
#include <U8g2lib.h>
#include <Wire.h>

// Screen
U8G2_SSD1306_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, U8X8_PIN_NONE, 9,8);

PCA9555 ioExpander(0x20); // initialize the PCA9555 I/O expander at address 0x20 which is a defualt address

// --- cyrus schmetic mapping ---
const int BTN_BOOT = 0;     // 
const int BTN_UP = 4;       // 
const int BTN_DOWN = 5;     //
const int BTN_SELECT = 6;   //
// Note: RESET is wired to the EN pin on your PCB. It needs no code.

// Define the UI States
enum SystemState {
  STATE_BOOT,
  STATE_MAIN_MENU,
  STATE_LORA_SNIFFER
};

SystemState currentState = STATE_BOOT;

// Menu tracking
int menuIndex = 0;
const int totalMenuItems = 2;

void setup(void) {
  // Initialize the 4 programmable buttons
  pinMode(BTN_BOOT, INPUT_PULLUP);
  pinMode(BTN_UP, INPUT_PULLUP);
  pinMode(BTN_DOWN, INPUT_PULLUP);
  pinMode(BTN_SELECT, INPUT_PULLUP);
  
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

  if (menuIndex == 0) u8g2.drawStr(10, 35, "> Inbox");
  else u8g2.drawStr(10, 35, "  Inbox");

  if (menuIndex == 1) u8g2.drawStr(10, 50, "> LoRa Sniffer");
  else u8g2.drawStr(10, 50, "  LoRa Sniffer");
}

void drawSnifferScreen() {
  u8g2.setFont(u8g2_font_ncenB08_tr);
  u8g2.drawStr(0, 15, "[ LORA SNIFFER ]");
  u8g2.drawStr(0, 35, "Scanning 915MHz...");
  u8g2.drawStr(0, 50, "Packets found: 0");
  u8g2.drawStr(0, 64, "(Press BOOT to exit)"); // Remind user what back is
}

void loop(void) {
  // 1. Read Inputs (LOW means it is pressed down)
  bool upPressed = (digitalRead(BTN_UP) == LOW);
  bool downPressed = (digitalRead(BTN_DOWN) == LOW);
  bool selectPressed = (digitalRead(BTN_SELECT) == LOW);
  bool bootPressed = (digitalRead(BTN_BOOT) == LOW); // Using BOOT as Back

  // 2. Update Logic based on State
  if (currentState == STATE_BOOT) {
    if (millis() > 2000) {
      currentState = STATE_MAIN_MENU;
    }
  } 
  else if (currentState == STATE_MAIN_MENU) {
    if (downPressed) {
      menuIndex++;
      if (menuIndex >= totalMenuItems) menuIndex = 0;
      delay(200); 
    }
    if (upPressed) {
      menuIndex--;
      if (menuIndex < 0) menuIndex = totalMenuItems - 1;
      delay(200); 
    }
    if (selectPressed) {
      if (menuIndex == 1) { // 1 is LoRa Sniffer
        currentState = STATE_LORA_SNIFFER;
      }
      delay(200);
    }
  }
  else if (currentState == STATE_LORA_SNIFFER) {
n
    if (bootPressed) {
      currentState = STATE_MAIN_MENU;
      delay(200);
    }
  }


  u8g2.clearBuffer();					
  
  if (currentState == STATE_BOOT) drawBootScreen();
  else if (currentState == STATE_MAIN_MENU) drawMainMenu();
  else if (currentState == STATE_LORA_SNIFFER) drawSnifferScreen();

  u8g2.sendBuffer();					
}