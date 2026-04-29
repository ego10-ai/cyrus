#ifndef POWER_MMANAGER_H
#define POWER_MMANAGER_H

#include "hal_pins.h"
#include <Arduino.h>
#include <Wire.h>

class PowerManager {

    public:
    // fuction will call his once during boot to init the power management system
    void init();


    // LDO Control Fuctions
    void enableGPS(bool state);
    void enableLoRa(bool state);
    void enableSD(bool stae);

    // Peripheral Controls
    void resetOLED();
    void enableMotor(bool state);

    private:

    // helper function to write to the XL9555 I/O expander regisers via I2C
    void wrieIOExpander(uint8_t reg, uint8_t data);


    // keeps track of state of  ports 0
    uint8_t port0State = 0x00; // all off by default
};

#endif

