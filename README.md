# Cyrus : Solar-Powered LoRa communication with GPS  
Cyrus is a project that allows the use of affordable LoRa radios for long-range, off-grid communication where reliable infrastructure is absent. It is entirely community-driven. It uses the LoRa protocol, which is license-free and widely available in most areas without needing any additional licenses or certifications, unlike traditional HAM radio.
For location awareness and asset tracking, Cyrus features an integrated u-blox GNSS receiver.
The hardware is designed for indefinite deployment in remote environments. It utilizes a dedicated Maximum Power Point Tracking (MPPT) charge controller to efficiently harvest energy from a 6V solar panel.
<img width="1872" height="2272" alt="Remove background project" src="https://github.com/user-attachments/assets/9b82a06c-5981-46c4-8d6d-db9bbfa54162" />

## Hardware specifications
- Microcontroller: ESPRESSIF ESP32-S3-WROOM-1-N8R8
- Communication: Ai-Thinker Ra-01SH-P (Semtech SX1262 LoRa module) routed to an edge-launch SMA-SMD connector.
- GPS for Positioning: u-blox MAX-M10S-00B GNSS Receiver with hardware MOSFET power gating, coin cell backup, and a 6GHz U.FL-R-SMT antenna connector.
- Power Management: Dual-charger setup featuring a Consonance CN3791 MPPT Solar Charger IC and a Microchip MCP73871 Battery Management IC.
- Voltage Regulation: TOREX XC6220B331PR-G 3.3V Ultra-Low Quiescent Current LDO for high efficiency during deep sleep.
- Sensors: Bosch BME688 Environmental Sensor (Temperature, Humidity, Barometric Pressure, and VOC Gas).
- Interface: Integrated TYPE-C 16-PIN USB connector
- Display: HS242L03B2C01 OLED display.
- 
## Design Details
Software Used: EasyEDA
Component Size: Primarily 0603 SMD for a balance between compact size and hand-solderability.

## Schemetic
![](https://image-pro.easyeda.com/pullimages/8fa98248aa934d5c965c4f3c3752a967.webp)

## Hardware size and pcb view
![](https://image-pro.easyeda.com/pullimages/b95d34b9c34a40c1961e5731502df87b.webp)

## project files
- `Netlist_Schematic1_2026-03-31.tel`: Netlist schematic file
- `ProPrj_cyrus_2026-03-31.epro`: Project file

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.
