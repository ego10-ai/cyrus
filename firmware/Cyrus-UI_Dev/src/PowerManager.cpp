#include "PowerManager.h"

// XL9555 I2C address 

#define XL9555_REG_OUTPUT_PORT0 0x02
#define XL9555_REG_CONFIG_PORT0 0x06

void PowerManager::init() {
    Serial.println("Power: Inittializing I2C BUS ...");

    // sart the I2C bus using thepin from  schewmatics
    Wire.begin(PIN_I2C_SDA, PIN_I2C_SCL);

    //  for stablization we need to give the bus some delay
    delay(10);

    Serial.println("Power: CConfiguring XL9555 I/O Expander ...");

    // Binary: 1001 0000 (0x90 in Hex) sets 4 and 7 as inputs, rest as outputs.
    // pin 4(KEY_INT) should be input (1)
    // i  need   pin 0(GPS),  1(LoRa), 2(SD), 3(lcd reset), 5(motor), 6(kb bl) as outputs.

    writeIOExpander(XL9555_REG_CONFIG_PORT0, 0x90);

    // allpower rails are initially off to save power.
    port0State = 0x00; // all off
    writeIOExpander(XL9555_REG_OUTPUT_PORT0, port0State);

}

void PowerManager::enableGPS(bool state) {
    if (state) port0State |= (1 << EXP_PIN_GPS_EN);  // turn on gps bit
    else       port0State &= ~(1 << EXP_PIN_GPS_EN); // turn off gps bit

    writeIOExpander(XL9555_REG_OUTPUT_PORT0, port0State);
    Serial.println(state ? "Power: GPS LDO ON" : "Power: GPS LDO OFF");
}

void PowerManager::enableLoRa(bool state) {
    if  (state) port0State |= (1 << EXP_PIN_LORA_EN);  // turn on LoRa bit
    else        port0State &= ~(1 << EXP_PIN_LORA_EN); // 
    
    writeIOExpander(XL9555_REG_OUTPUT_PORT0, port0State);
    Serial.println(state ? "Power: LoRa LDO ON" : "Power: LoRa LDO OFF");
}

void PowerManager::enableSD(bool state) {
    if (state) port0State |= (1 << EXP_PIN_SD_EN);  // turn on SD bit
    else       port0State &= ~(1 << EXP_PIN_SD_EN); // turn off SD bit

    writeIOExpander(XL9555_REG_OUTPUT_PORT0, port0State);
    Serial.println(state ? "Power: SD Card LDO ON" : "Power: SD Card LDO OFF");
}


void PowerManager::resetOLED() {
    // 
    Serial.println("Power: hardware reseting OLED...............");
    // Pull LCD_RST low ,wait ,then pull it high again

    port0State &= ~(1 << EXP_PIN_LCD_RST); 

    writeIOExpander(XL9555_REG_OUTPUT_PORT0, port0State);
    delay(50); // wait for 50 ms with reset low

    port0State |= (1 << EXP_PIN_LCD_RST);
    writeIOExpander(XL9555_REG_OUTPUT_PORT0, port0State);
    delay(50); // wait for 50 ms after releasing reset
}

// ----- Private I2C Helper-------------
void PowerManager::writeIOExpander(unit8_t reg, uint8_t data) {
    Wire.eginTransmission(I2C_ADDR_XL9555);
    Wire.write(reg);
    Wire.write(data);
    Wire.endTransmission();
}
