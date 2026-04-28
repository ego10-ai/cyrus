// --- I2C Bus ---
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
#define PIN_BTN_SEL       35