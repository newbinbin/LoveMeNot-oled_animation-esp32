# LoveMeNot-oled_animation
ESP32-C3 OLED animation — 247-frame bitmap video playback on SSD1306 | Rawbotics
# Love Me Not — OLED Animation (ESP32-C3 Mini)

A 247-frame bitmap animation played on a 128x64 SSD1306 OLED display using an ESP32-C3 Mini.

Part of the **Rawbotics** project series — [rawbotics.io](https://www.instagram.com/rawbotics.io)

---

## Hardware

| Component | Detail |
|---|---|
| Microcontroller | ESP32-C3 Mini |
| Display | 0.96" SSD1306 OLED (128x64, I2C) |

## Wiring

| OLED Pin | ESP32-C3 Mini Pin |
|---|---|
| SDA | GPIO 8 |
| SCL | GPIO 9 |
| VCC | 3.3V |
| GND | GND |

---

## Libraries Required

Install these via Arduino Library Manager:

- `Adafruit SSD1306`
- `Adafruit GFX Library`

---

## Files

| File | Description |
|---|---|
| `oled_i_miss_you.ino` | Main sketch |
| `VideoFrame.h` | 247 bitmap frames in PROGMEM |

---

## How It Works

- Frames are stored as `PROGMEM` byte arrays in `VideoFrame.h`
- Played back at ~24fps (41ms delay per frame)
- Loops continuously

---

## Notes

- Both files must be in the **same folder** to compile
- I2C clock is set to 800kHz for smooth playback
- Built and uploaded using **ArduinoDroid** (Android)
