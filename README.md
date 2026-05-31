# Hackbat-MultiToolhacking-OS1
An open-source multi-tool firmware for the RP2040 Hackbat. Unifies sub-1GHz RF (CC1101), NFC (PN532), BadUSB (HID), and Wi-Fi (ESP8266) modules into an interactive, menu-driven penetration testing OS. Built for automated keystroke injection, signal cloning, credential spoofing, and advanced wireless network security auditing.


# Hackbat Multi-Tool OS 🦇

An open-source multi-tool firmware for the RP2040 Hackbat. Unifies sub-1GHz RF (CC1101), NFC (PN532), BadUSB (HID), and Wi-Fi (ESP8266) modules into an interactive, menu-driven penetration testing OS. Built for automated keystroke injection, signal cloning, credential spoofing, and advanced wireless network security auditing.

---

## 🚀 Core Features
*   **Sub-1 GHz Suite:** Capture, save, and replay 433MHz radio signals.
*   **NFC Toolkit:** Scan passive tags and emulate cloned card UIDs.
*   **BadUSB Engine:** Inject high-speed offensive automated keystroke scripts.
*   **Wi-Fi Link:** Send serial attack macros directly to the ESP-12F chip.

## 🛠️ Hardware Mapping

| Peripheral | Chipset | RP2040 Pin |
| :--- | :--- | :--- |
| **OLED Screen** | SH1106 I2C | Default I2C0 |
| **Buttons** | Up / Down / Select | GPIO 2 / 3 / 4 |
| **NFC Interface** | NXP PN532 | GPIO 5 (IRQ) / 6 (RST) |
| **Radio Interface**| TI CC1101 | GPIO 7 (GDO0) |
| **Wi-Fi Serial** | ESP-12F | GPIO 8 (RX) / 9 (TX) |

## 🔧 Installation & Flashing
1. Add the **Earle Philhower RP2040 Core** to your Arduino IDE boards manager.
2. Install dependencies: `Adafruit SH110X`, `Adafruit PN532`, and `SmartRC-CC1101-Driver-Lib`.
3. Hold the **BOOT** button on the Hackbat, connect via USB, and select **Generic RP2040**.
4. Click **Upload** to compile and flash the firmware binary.

## ⚖️ Disclaimer
*This project is created strictly for authorized penetration testing, educational research, and white-hat auditing. The author assumes no liability for hardware misuse or regulatory radio violations.*
