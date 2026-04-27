# Cyrus : Solar-Powered LoRa communication with GPS  
Cyrus is a project that allows the use of affordable LoRa radios for long-range, off-grid communication where reliable infrastructure is absent. It is entirely community-driven. It uses the LoRa protocol, which is license-free and widely available in most areas without needing any additional licenses or certifications, unlike traditional HAM radio.
- For location awareness and asset tracking, Cyrus features an integrated u-blox GNSS receiver.
- The hardware is designed for indefinite deployment in remote environments. It utilizes a dedicated Maximum Power Point Tracking (MPPT) charge controller to efficiently harvest energy from a 6V solar panel.
<img width="1872" height="2272" alt="Remove background project" src="https://github.com/user-attachments/assets/9b82a06c-5981-46c4-8d6d-db9bbfa54162" />

## Hardware Architecture

The system is distributed across five logical subsystems, fully detailed in the provided schematics.

### 1. Core Compute & Control
* **MCU:** Espressif ESP32-S3-WROOM-1U (U.FL variant for external antenna routing)
* **I/O Expansion:** XL9555 (I2C) for power-gating RF modules and handling UI interrupts.

### 2. RF Subsystem
* **LoRa:** Ebyte E22-900M22S (SPI) - Includes hardware TX/RX switching.
* **GPS:** u-blox MAX-M10S (UART) - Routed with a 50-ohm trace to a dedicated U.FL connector.
* **NFC:** STMicroelectronics ST25R3916 (SPI) - Includes custom EMI filtering and receiver feedback loops.

### 3. Power Delivery Network
* **Main Charging:** Texas Instruments BQ25896 (USB-C 3.1 16-pin interface).
* **Solar Harvesting:** Texas Instruments BQ25570 for trickle-charging via external solar panels.
* **Fuel Gauge:** Maxim MAX17048 for highly accurate state-of-charge reporting.
* **Regulation:** Dedicated RT9080 LDOs to isolate noise-sensitive RF and SD Card domains.

### 4. Peripherals & UI
* **Display:** 30-pin FPC interface for HS13L03W2C01 OLED.
* **Keyboard:** 6-pin FPC connector mapped for standard Blackberry I2C keyboard modules.
* **Haptics:** DRV2605 I2C driver paired with a KOTL Z30C1T8219731 SMD cylindrical motor.
* **Environment & Timing:** BME280 (Temp/Humidity/Pressure) and PCF85063AT RTC (with CR1220 battery backup).

### 5. Audio Pipeline
* **Input:** INMP441 MEMS Digital Microphone (I2S).
* **Output:** MAX98357A Class-D Amplifier (I2S).

--- 
## Design Details
- Software Used: EasyEDA
- Component Size: Primarily 0603 SMD for a balance between compact size and hand-solderability.

## Schemetic 

1. Power Delivery Network
![](https://image-pro.easyeda.com/pullimages/d2033df7d1f04e058e594b4361e9f61d.webp)
2. Core MCU
![](https://image-pro.easyeda.com/pullimages/5b60e9557f2c4a5697ca8b7fabd7da72.webp)
I/O expention 
![](https://image-pro.easyeda.com/pullimages/e376947c7ec6454ea7dc795001a701cc.webp)
RF Subsystem
![](https://image-pro.easyeda.com/pullimages/2171d2289a524bf486cdfb932196aa68.webp)
Peripherals & UI
![](https://image-pro.easyeda.com/pullimages/05ea7df4484a4fd0b0732260e4d13acb.webp)

---
old version
![](https://image-pro.easyeda.com/pullimages/8fa98248aa934d5c965c4f3c3752a967.webp)

## Hardware size and pcb view
![](https://image-pro.easyeda.com/pullimages/b95d34b9c34a40c1961e5731502df87b.webp)

## Project Bill of Materials (BOM)

### Bill of Materials (BOM)

| Qty | Designator | Description | Footprint | MPN | Manufacturer |
|---:|:---|:---|:---|:---|:---|
| 5 | BOOT, DOWN, RESET, SCLT, UP | TS-1088-AR02016 | SW-SMD_L3.9-W2.9-LS4.8 | TS-1088-AR02016 | XUNPU(讯普) |
| 8 | C5, C6, C7, C22, C29, C36, C38, C61 | 10uF | C0402 | CL05A106MP5NUNC | SAMSUNG(三星) |
| 2 | C8, C12 | 22uF | C0603 | CL10A226MP8NUNE | SAMSUNG(三星) |
| 6 | C9, C11, C15, C17, C19, C27 | 100nF | C0603 | CL10B104KB8NNNC | SAMSUNG(三星) |
| 4 | C10, C14, C16, C18 | 10uF | C0603 | CL10A106KP8NNNC | SAMSUNG(三星) |
| 1 | C20 | 22pF | C0402 | CC0402JRNPO9BN220 | YAGEO(国巨) |
| 1 | C21 | 47nF | C0402 | CC0402KRX7R9BB473 | YAGEO(国巨) |
| 2 | C23, C26 | 4.7uF | C0603 | CL10A475KO8NNNC | SAMSUNG(三星) |
| 1 | C24 | 10nF | C0603 | CC0603KRX7R9BB103 | YAGEO(国巨) |
| 12 | C28, C40, C41, C42, C43, C44, C45, C46, C47, C55, C60, C64 | 100nF | C0402 | CL05B104KO5NNNC | SAMSUNG(三星) |
| 5 | C30, C35, C50, C56, C57 | 1uF | C0402 | CL05A105KP5NNNC | SAMSUNG(三星) |
| 6 | C31, C34, C37, C39, C62, C63 | 100nF | C0402 | CC0402KRX7R7BB104 | YAGEO(国巨) |
| 2 | C32, C33 | 12pF | C0402 | CC0402JRNPO9BN120 | YAGEO(国巨) |
| 2 | C48, C49 | 10pF | C0402 | CL05C100JB5NNNC | SAMSUNG(三星) |
| 2 | C51, C52 | 100pF | C0603 | CL10C101JB8NNNC | SAMSUNG(三星) |
| 2 | C53, C54 | 1nF | C0603 | CL10B102KB8NNNC | SAMSUNG(三星) |
| 2 | C58, C59 | 4.7uF | C0402 | CL05A475KP5NRNC | SAMSUNG(三星) |
| 3 | CN1, CN2, CN3 | S2B-PH-SM4-TB(LF)(SN) | CONN-SMD_P2.00_S2B-PH-SM4-TB-LF-SN | S2B-PH-SM4-TB(LF)(SN) | JST |
| 1 | FPC1 | FPC1.0-WSS11-6P211-H25 | FPC-SMD_FPC1.0-WSS11-6P211-H25 | FPC1.0-WSS11-6P211-H25 | HMTCONN(华明通) |
| 1 | FPC2 | FPC-05FB-30PH20 | FPC-SMD_30P-P0.50_FPC-05FB-30PH20 | FPC-05FB-30PH20 | XUNPU(讯普) |
| 2 | JP1, JP2 | 6GHz | RF-SMD_FRF05002-JSS103M | U.FL-R-SMT-1(80) | HRS(广濑) |
| 1 | L1 | 2.2uH | L0805 | ZEPIM201210S-2R2M | ZE(增益) |
| 1 | L2 | 1uH | L0805 | DFE201210U-1R0M=P2 | muRata(村田) |
| 1 | L3 | 10nH | IND-SMD_L1.6-W0.8-1 | LQW18AN10NG00D | muRata(村田) |
| 2 | L4, L5 | 470nH | L0603 | LQW18ANR47G00D | muRata(村田) |
| 1 | LED1 | LED_0603-G | LED0603-RD_GREEN | - | - |
| 1 | M1 | Z3OC1T8219731 | VIBRATING-MOTOR-SMD_3P-C9900001680 | Z3OC1T8219731 | KOTL(金龙机电) |
| 1 | MIC1 | INMP441 | MIC-SMD_INMP441 | INMP441 | TDK InvenSense |
| 1 | OLED1 | HS13L03W2C01 | OLED-TH_L35.4-W33.5_HS13L03W2C01 | HS13L03W2C01 | HS(汉昇) |
| 1 | R2 | NTCG104BH103HT1 | R0402 | NTCG104BH103HT1 | TDK |
| 2 | R3, R4 | 5.1kΩ | R0402 | RC0402FR-075K1L | YAGEO(国巨) |
| 1 | R5 | 10kΩ | R0402 | ERJ2RKF1002X | PANASONIC(松下) |
| 1 | R6 | 100kΩ | R0603 | RC0603FR-07100KL | YAGEO(国巨) |
| 1 | R7 | 22.1kΩ | R0603 | FRC0603F2212TS | FOJAN(富捷) |
| 1 | R8 | 200Ω | R0402 | 0402WGF2000TCE | UNI-ROYAL(厚声) |
| 1 | R9 | 10MΩ | R0603 | RC0603FR-0710ML | YAGEO(国巨) |
| 1 | R10 | 7.5MΩ | R0603 | FRC0603F7504TS | FOJAN(富捷) |
| 6 | R11, R12, R17, R18, R21, R22 | 10kΩ | R0402 | RC0402FR-0710KL | YAGEO(国巨) |
| 2 | R13, R14 | 22Ω | R0402 | RC0402FR-0722RL | YAGEO(国巨) |
| 2 | R15, R16 | 4.7kΩ | R0402 | RC0402FR-074K7L | YAGEO(国巨) |
| 9 | R19, R20, R23, R24, R25, R26, R28, R29, R30 | 10kΩ | R0603 | RC0603FR-0710KL | YAGEO(国巨) |
| 1 | R27 | 560kΩ | R0603 | RC0603FR-07560KL | YAGEO(国巨) |
| 1 | R31 | 1kΩ | R0402 | RC0402FR-071KL | YAGEO(国巨) |
| 1 | SIM1 | 1040310811 | SIM-SMD_8P-1040310811 | 1040310811 | MOLEX |
| 1 | U1 | BQ25570RGRR | VQFN-20_L3.5-W3.5-P0.50-BL-EP2.0 | BQ25570RGRR | TI(德州仪器) |
| 1 | U2 | BQ25896RTWR | QFN-24_L4.0-W4.0-P0.50-TL-EP2.7 | BQ25896RTWR | TI(德州仪器) |
| 1 | U3 | MAX17048G+T10 | TDFN-8_L2.0-W2.0-P0.50-BL-EP1.2 | MAX17048G+T10 | ADI(美信) |
| 1 | U5 | SY8089AAAC | SOT-23-5_L3.0-W1.7-P0.95-LS2.8-BR | SY8089AAAC | Silergy(矽力杰) |
| 3 | U6, U7, U8 | RT9080-33GJ5 | TSOT-23-5_L2.9-W1.6-P0.95-LS2.8-BL | RT9080-33GJ5 | RICHTEK(立锜) |
| 1 | U9 | 22uH | IND-SMD_L1.8-W1.3 | AHW1608FE220KTF | APV(爱普微) |
| 1 | U10 | 2.4GHz | WIRELM-SMD_ESP32-S3-WROOM-1U | ESP32-S3-WROOM-1U-N16R8 | ESPRESSIF(乐鑫) |
| 1 | U12 | XL9555 | TSSOP-24_L7.8-W4.4-P0.65-LS6.4-BL | XL9555 | XINLUDA(信路达) |
| 1 | U13 | DRV2605LDGSR | DRV2605LDGSR | DRV2605LDGSR | TI(德州仪器) |
| 1 | U14 | PCF85063AT/A | SO-8_L4.9-W3.9-P1.27-LS5.9-BL | PCF85063AT/A | NXP(恩智浦) |
| 1 | U15 | E22-900M22S | WIRELM-SMD_E22-900M22S | E22-900M22S | EBYTE(亿佰特) |
| 1 | U16 | MAX-M10S-00B | SMD-18_L10.1-W9.7-P1.10-TL_SKG09F | MAX-M10S-00B | U-BLOX(优北罗) |
| 1 | U17 | ST25R3916-AQWT | VFQFPN-32_L5.0-W5.0-P0.50-TL-EP3.5 | ST25R3916-AQWT | ST(意法半导体) |
| 1 | U19 | MAX98357AETE+T | TQFN-16_L3.0-W3.0-P0.50-BL-EP1.5 | MAX98357AETE+T | ADI(美信) |
| 1 | U20 | BME280 | LGA-8_BME280_BL | BME280 | Bosch(博世) |
| 1 | USB1 | HX TYPE-C-3.1-16PIN | TYPE-C-SMD_HX-TYPE-C-16PIN | HX TYPE-C-3.1-16PIN | hanxia(韩下) |
| 1 | X1 | 32.768kHz | OSC-SMD_L3.2-W1.5 | SMD31327681252090 | JGHC(晶光华) |
| 1 | X2 | 27.12MHz | CRYSTAL-SMD_4P-L3.2-W2.5-BL_SIT8008BI | XL2EL89CSI-111YLC-27.12M | YXC(扬兴晶振) |


old version
---
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

## Fabrication & Assembly Notes

If you are fabricating this board, please adhere to the following design rules:

1. **Layer Stackup:** A 4-layer PCB is strictly required. 
   * Layer 1: Signals
   * Layer 2: Solid GND Plane (Do not route traces here)
   * Layer 3: Power Plane (`VDD3V3`, `VBAT`, `VSYS`)
   * Layer 4: Signals
2. **Impedance Matching:** The traces connecting the ESP32, LoRa module, and GPS module to their respective U.FL connectors must be calculated to exactly 50 ohms based on your manufacturer's specific prepreg thickness.
3. **Antenna Placement:** Ensure no copper exists on any of the 4 layers directly beneath the U.FL connectors or the NFC antenna header.
4. **Mechanical:** The USB-C shield tabs (pins 17-20) and the vibration motor Exposed Pad (Pin 3) must be solidly tied to the GND plane for structural integrity.

---

##  Contributing

Contributions to both the hardware design and the upcoming firmware are welcome. Please open an issue to discuss major architectural changes before submitting a pull request.

## project files
- `Netlist_Schematic1_2026-03-31.tel`: Netlist schematic file
- `ProPrj_cyrus_2026-03-31.epro`: Project file

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.
