# ESP32 OLED Display Project 📱🌐🎶

This project integrates an ESP32 microcontroller with an OLED display to control four different apps: **WiFi**, **Music**, **Telegram**, and **Camera**. The software is controlled via serial commands and works with a Python script for the Telegram integration.

## Features 🚀

- **WiFi**: Connects to a WiFi network to enable internet features.
- **Music**: Plays music through a connected audio device.
- **Telegram**: Displays Telegram messages on the OLED screen by running a Python script locally.
- **Camera**: Allows for camera control or image display (depending on the app configuration).

## Project Components 🧩

1. **ESP32**: The microcontroller at the core of this project.
2. **OLED Display**: A small screen to display the current app and relevant information.
3. **Python Script**: Manages Telegram functionality and listens for messages to be displayed on the OLED screen.
4. **Serial Communication**: Commands sent through the serial port to switch between apps.

## Setup and Installation 📦

### 1. Requirements

- **Hardware**:
  - ESP32 Microcontroller
  - OLED Display (e.g., SSD1306)
  - Optional: Audio output device for music, camera module for the camera app.

- **Software**:
  - Python 3.x
  - `pyserial` for serial communication between the ESP32 and your computer.
  - Python libraries for Telegram API (`telethon` or `python-telegram-bot`).

### 2. Flashing the ESP32

To get started, you'll need to flash the ESP32 with the appropriate firmware. Follow these steps:

1. Connect the ESP32 to your computer via USB.
2. Flash the firmware using [Arduino IDE](https://www.arduino.cc/en/software) or [PlatformIO](https://platformio.org/). Make sure to install the necessary libraries for OLED display, WiFi, and any other hardware you're using.

#### Libraries:
- `Adafruit_SSD1306` for the OLED display.
- `WiFi.h` for WiFi functionality.
- `WiFiClientSecure.h` for secure internet connections.
  
Example:
```cpp
#include <WiFi.h>
#include <Adafruit_SSD1306.h>
