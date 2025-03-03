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
  - Python libraries for Telegram API (`telethon`).

### 2. Flashing the ESP32

To get started, you'll need to flash the ESP32 with the appropriate firmware. Follow these steps:

1. Connect the ESP32 to your computer via USB.
2. Flash the firmware using [Arduino IDE](https://www.arduino.cc/en/software) or [PlatformIO](https://platformio.org/). Make sure to install the necessary libraries for OLED display, WiFi, and any other hardware you're using.

#### Libraries:
- `Adafruit_SSD1306` for the OLED display.
- `Adafruit_GFX.h` also for the OLED display
- `Wire.h` for display pin activation 
- `WiFi.h` for WiFi functionality.
- `WiFiClientSecure.h` for secure internet connections.
- `Fonts/segoeui5pt7b.h` for Segoe UI 5pt font
- `Fonts/segoeui6pt7b.h` for Segoe UI 6pt font
- `NTPClient.h` for getting current time
- `Graphics/icons.h` for integrating icons in the project
- `All_Variables/Const_Variables.h` for adding necessary constant variables
- `All_Variables/Variables.h` for adding necessary changable constan variables
- `BluetoothA2DPSink.h` for bluetooth connectivity and reading audio tracks metadata

## Usage instructions
For correct work, follow these steps:

1. Connect the ESP32 via USB to your computer
2. Run the python script in your IDE
3. Restart your ESP32 via RST button

Now make sure, that your ESP32 is connected to Wi-Fi. If is, you will see the main menu of software on your OLED screen.
Use the following commands to control the software:

1. 'Enter' - enters the active app
2. '
