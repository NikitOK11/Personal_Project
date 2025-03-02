# Software for IOT project for personal usage!:wave:

This project provides a software for integrating in any IOT thing project! The system consists of two main components:

1. **Arduino Firmware (`sketch_feb5a.ino`)**  
   An Arduino sketch for your ESP (ESP8266/ESP32) board that listens on the serial port for incoming messages. Modify the sketch to handle commands or data as needed—for example, controlling hardware or triggering events on your device.

2. **Python Script (`script_forward_messages.py`)**  
   A Python script that leverages the Telethon library to monitor your Telegram account for new messages. When a message arrives, the script retrieves the message and the sender’s username, combines them, and sends the information over a serial connection to the ESP device.

## Features

- **Real-Time Telegram Integration:** Receive and process Telegram messages instantly.
- **Serial Communication:** Forward messages over a high-speed serial link (921600 baud by default).
- **Modular Design:** Separate firmware and Python components allow independent development and testing.
- **Customizable:** Easily modify the Arduino code or Python script to suit your specific application.

## Hardware Requirements

- ESP8266 or ESP32 development board
- USB cable and necessary connectors for serial communication
- A computer to run the Python script

## Software Requirements

- **For ESP Firmware:**
  - [Arduino IDE](https://www.arduino.cc/en/software) or [PlatformIO](https://platformio.org/install)
  
- **For Python Script:**
  - Python 3.x
  - Python packages as listed in `requirements.txt`

## Setup and Installation

### 1. Arduino Firmware

- **Step 1:** Open the `sketch_feb5a.ino` file in the Arduino IDE or PlatformIO.
- **Step 2:** Connect your ESP board to your computer.
- **Step 3:** Select the appropriate board and port.
- **Step 4:** Compile and upload the sketch to your ESP device.

> **Note:** This sketch is designed to wait for serial data. Adjust the code as necessary to suit your application needs (e.g., handling specific commands or controlling hardware).

### 2. Python Script

- **Step 1:** Ensure Python 3.x is installed.
- **Step 2:** (Optional) Create and activate a virtual environment:
  ```bash
  python3 -m venv venv
  source venv/bin/activate  # On Windows: venv\Scripts\activate
