# Cyrus : Solar-Powered LoRa communication with GPS  
Cyrus is a project that allows the use of affordable LoRa radios for long-range, off-grid communication where reliable infrastructure is absent. It is entirely community-driven. It uses the LoRa protocol, which is license-free and widely available in most areas without needing any additional licenses or certifications, unlike traditional HAM radio.
- For location awareness and asset tracking, Cyrus features an integrated u-blox GNSS receiver.
- The hardware is designed for indefinite deployment in remote environments. It utilizes a dedicated Maximum Power Point Tracking (MPPT) charge controller to efficiently harvest energy from a 6V solar panel.
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
- Software Used: EasyEDA
- Component Size: Primarily 0603 SMD for a balance between compact size and hand-solderability.

## Schemetic
![](https://image-pro.easyeda.com/pullimages/8fa98248aa934d5c965c4f3c3752a967.webp)

## Hardware size and pcb view
![](https://image-pro.easyeda.com/pullimages/b95d34b9c34a40c1961e5731502df87b.webp)

## Project Bill of Materials (BOM)

| Qty | Reference | Description | Part Number | Manufacturer | LCSC Part |
|:---:|:---|:---|:---|:---|:---|
| 2 | BATTERY, SOLAR | CONN-SMD P2.00 S2B-PH-SM4-TB-LF-SN | S2B-PH-SM4-TB(LF)(SN) | JST | [C295747](https://www.lcsc.com/product-detail/C295747.html) |
| 2 | boot, RESET | SW-SMD HX-3X6X2.5-X Tact Switch | HX-3x6x2.5-X | hanxia | [C49234125](https://www.lcsc.com/product-detail/C49234125.html) |
| 1 | BT1 | BAT-SMD KH-BS1632-1-SMT Coin Cell Holder | KH-BS1632-1-SMT | kinghelm | [C5365934](https://www.google.com/search?q=https://www.lcsc.com/product-detail/C5365934.html) |
| 2 | C1, C3 | 10uF Capacitor 0603 | 10uF | - | - |
| 5 | C2, C4, C6, C7, C16 | 100nF Capacitor 0603 | 100nF | - | - |
| 1 | C5 | 1uF Capacitor 0603 | 1uF | - | - |
| 2 | C8, C9 | 100nF Capacitor 0603 | CC0603KRX7R9BB104 | YAGEO | [C14663](https://www.lcsc.com/product-detail/C14663.html) |
| 2 | C10, C11 | 4.7uF Capacitor 0402 | CL05A475MP5NRNC | SAMSUNG | [C23733](https://www.lcsc.com/product-detail/C23733.html) |
| 1 | C12 | 10uF Capacitor 0402 | CL05A106MP5NUNC | SAMSUNG | [C315248](https://www.lcsc.com/product-detail/C315248.html) |
| 2 | C13, C14 | 10uF Capacitor 0603 | CL10A106MA8NRNC | SAMSUNG | [C96446](https://www.lcsc.com/product-detail/C96446.html) |
| 1 | C15 | 100nF Capacitor 0201 | 100nF | - | - |
| 3 | CHRG, DONE, HEALTH | LED 0603 Red | LED0603-R-RD | - | - |
| 3 | D1, D2, D3 | SOD-523 TVS Diode | LESD5Z5.0CT1G | LRC | [C136167](https://www.lcsc.com/product-detail/C136167.html) |
| 1 | D4 | SOD-123F Schottky Diode | MBR120VLSFT1G | onsemi | [C223608](https://www.google.com/search?q=https://www.lcsc.com/product-detail/C223608.html) |
| 2 | D5, D6 | SMA Schottky Diode | SS34 | baocheng | [C47018524](https://www.google.com/search?q=https://www.lcsc.com/product-detail/C47018524.html) |
| 1 | H1 | HDR-TH 7P P2.54 Female | HDR-F\_2.54\_1x7P | - | - |
| 1 | H2 | HDR-TH 2P P2.54 Female | 2.54-1\*2P | BOOMELE | [C49661](https://www.lcsc.com/product-detail/C49661.html) |
| 1 | L1 | IND-SMD L6.0-W6.0 4.7uH | CKCS6020-4.7uH/M | CENKER | [C5291857](https://www.google.com/search?q=https://www.lcsc.com/product-detail/C5291857.html) |
| 1 | L2 | IND-SMD L1.6-W1.0 47nH | HP0603-47NH-N | Chilisin | [C2903684](https://www.lcsc.com/product-detail/C2903684.html) |
| 1 | OLED | OLED-TH 4P L72.0-W43.0 P2.54 | HS242L03B2C01 | HS | [C7466000](https://www.lcsc.com/product-detail/C7466000.html) |
| 2 | Q1, Q2 | SOT-23-3 P-Channel MOSFET | SI2301 | PAKER | [C5278884](https://www.google.com/search?q=https://www.lcsc.com/product-detail/C5278884.html) |
| 2 | R1, R2 | 5.1kΩ Resistor 0603 | 5.1kΩ | - | - |
| 3 | R3, R4, R21 | 100KΩ Resistor 0603 | 100K | - | - |
| 3 | R5, R17, R18 | 10KΩ Resistor 0603 | 10K | - | - |
| 2 | R6, R7 | 3.3KΩ Resistor 0603 | 3.3K | - | - |
| 1 | R8 | 100kΩ Resistor 0603 | 0603WAF1003T5E | UNI-ROYAL | [C25803](https://www.lcsc.com/product-detail/C25803.html) |
| 1 | R9 | 1kΩ Resistor 0402 | 0402WGF1001TCE | UNI-ROYAL | [C11702](https://www.lcsc.com/product-detail/C11702.html) |
| 3 | R10, R11, R12 | 470Ω Resistor 0603 | 470R | - | - |
| 1 | R13 | NTC Thermistor 10k 0402 | NCP15XH103F03RC | muRata | [C77131](https://www.lcsc.com/product-detail/C77131.html) |
| 1 | R15 | 0.24Ω Resistor 1206 | 0.24Ω | - | - |
| 1 | R16 | NTC Thermistor 0603 | NTCS0603E3103FMT | VISHAY | [C554013](https://www.google.com/search?q=https://www.lcsc.com/product-detail/C554013.html) |
| 1 | R20 | 402KΩ Resistor 0603 | 402K | - | - |
| 1 | RF1 | ANT-SMD 6GHz U.FL Connector | U.FL-R-SMT(10) | HRS | [C434808](https://www.google.com/search?q=https://www.lcsc.com/product-detail/C434808.html) |
| 3 | SW1, SW2, SW3 | SW-SMD 4P Tactile Switch | HX 5.2x5.2x1.5H | hanxia | [C49234130](https://www.google.com/search?q=https://www.lcsc.com/product-detail/C49234130.html) |
| 1 | U1 | COMM-SMD 17P LoRa Module | Ra-01SH-P | Ai-Thinker | [C42420049](https://www.lcsc.com/product-detail/C42420049.html) |
| 1 | U2 | SMA-SMD 18GHz Connector | 142-0701-801 | belfuse | [C3173345](https://www.google.com/search?q=https://www.lcsc.com/product-detail/C3173345.html) |
| 1 | U3 | WIRELM-SMD 2.4GHz Wi-Fi/BLE | ESP32-S3-WROOM-1-N8R8 | ESPRESSIF | [C2913201](https://www.lcsc.com/product-detail/C2913201.html) |
| 1 | U6 | SOD-323 Schottky Diode | 1N5819WS | HXY MOSFET | [C5451629](https://www.google.com/search?q=https://www.lcsc.com/product-detail/C5451629.html) |
| 1 | U7 | CRYSTAL-SMD 32.768kHz | RN32768016 | TROQ | [C7206317](https://www.google.com/search?q=https://www.lcsc.com/product-detail/C7206317.html) |
| 1 | U8 | QFN-20 Battery Charger IC | MCP73871-2CCI/ML | MICROCHIP | [C5121473](https://www.lcsc.com/product-detail/C5121473.html) |
| 1 | U9 | SOT-89-5 3.3V LDO Regulator | XC6220B331PR-G | TOREX | [C3013658](https://www.google.com/search?q=https://www.lcsc.com/product-detail/C3013658.html) |
| 1 | U10 | LGA-8 Environmental Sensor | BME688 | Bosch | [C3664478](https://www.lcsc.com/product-detail/C3664478.html) |
| 1 | U11 | SSOP-10 MPPT Solar Charger | CN3791 | CONSONANCE | [C154992](https://www.lcsc.com/product-detail/C154992.html) |
| 1 | U12 | SMD-18 GNSS/GPS Receiver | MAX-M10S-00B | U-BLOX | [C4153167](https://www.lcsc.com/product-detail/C4153167.html) |
| 1 | USB1 | USB-C-SMD TYPE-C 16PIN | TYPE-C16PIN | SHOU HAN | [C393939](https://www.lcsc.com/product-detail/C393939.html) |

## project files
- `Netlist_Schematic1_2026-03-31.tel`: Netlist schematic file
- `ProPrj_cyrus_2026-03-31.epro`: Project file

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.
