
#ifndef HAL_PINS_H
#define HAL_PINS_H

// --- I2C Bus ---()(Devices ;- BQ25896, MAX17048, PCF85063A, XL9555, BME280, DRV2605, OLED, Keyboard )

#define PIN_I2C_SDA       8
#define PIN_I2C_SCL       9

// --- SPI Bus (Shared) ---
#define PIN_SPI_MOSI      11
#define PIN_SPI_MISO      13
#define PIN_SPI_SCK       12

// --- LoRa (E22-900M22S) ---
#define PIN_LORA_CS       10
#define PIN_LORA_RST      14
#define PIN_LORA_BUSY     21
#define PIN_LORA_IRQ      47




// in my schematics i uses IO1 and IO2 for LoRa, but in the E22-900M22S 

// --- GPS (MAX-M10S) ---
#define PIN_GPS_RX_ESP_TX 42  // ESP32 TX connects to GPS RX
#define PIN_GPS_TX_ESP_RX 41  // ESP32 RX connects to GPS TX
#define PIN_GPS_PPS       39

// --- Peripherals & Interrupts ---
#define PIN_SD_CS         46
#define PIN_NFC_CS        38
#define PIN_NFC_IRQ       5
#define PIN_BAT_ALRT      4
#define PIN_RTC_INT       6
#define PIN_IO_EXP_INT    7

// --- I2S Audio ---
#define PIN_I2S_BCLK      15
#define PIN_I2S_LRCLK     16
#define PIN_I2S_DIN       17
#define PIN_I2S_DOUT      18

// --- Hardware Buttons ---
#define PIN_BTN_DOWN      37
#define PIN_BTN_UP        36
#define PIN_BTN_SEL       35    // labeled SCLT in schematics

// XL9555 I/O Expander Pins Mappings
// (these are not ESP32 pins,these are IO expender ports )
//------------------------------------------------------
#define EXP_PIN_GPS_EN   0   // Port 100-0: Turns the GPS LDO on/off
#define EXP_PIN_LORA_EN  1   // Port 100-1: Turns the LoRa LDO on/off
#define EXP_PIN_SD_EN    2   // Port 100-2: Turns the SD card LDO on/off
#define EXP_PIN_LCD_RST  3   // Port 100-3: Resets the OLED display
#define EXP_PIN_KEY_INT  4   // Port 100-4: Interrupt from the keyboard
#define EXP_PIN_MOTOR_EN 5   // Port 100-5: turns vibration motor no/off
#define EXP_PIN_KB_BL    6   // Port 100-6: Keyboard backlight control

//------------------------------
//I2C DEVICES Addresses
//------------------------------
#define I2C_ADDR_BQ25896   0x68
#define I2C_ADDR_MAX17048  0x36
#define I2C_ADDR_PCF85063  0x51
#define I2C_ADDR_XL9555    0x20
#define I2c_ADDR_BME280    0x76



// notew for me to self: OLED was originally plan to used at 0x20 but the XL9555 is also at 0x20, 
// so i change the OLED to 0x3C, and it works fine, but i forgot to update the define here, so i will do it later when i implement the OLED driver.
