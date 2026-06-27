# ESP32 Pocket UI

A small hobby project made with ESP32 and an OLED display.

The project implements a simple menu-driven interface with multiple screens and navigation using physical buttons. It was created mainly for learning, experimenting with embedded UI design, and having fun with ESP32 development.

## Features

* Menu navigation
* Settings screen
* About screen
* Counter screen
* Button-based control
* OLED graphical interface

## Hardware

* ESP32
* 128×128 OLED display
* Navigation buttons:

  * Up
  * Down
  * Enter
  * Back
  * Counter button

## Software

* PlatformIO
* Arduino Framework

## Project Structure

The code is split into multiple modules responsible for:

* Display rendering
* Input handling
* Application state
* Utilities
* Constants

This makes the project easier to maintain and expand.

## Running the Project

### 1. Clone the repository

```bash
git clone https://github.com/YOUR_USERNAME/esp32-pocket-ui.git
cd esp32-pocket-ui
```

### 2. Open in PlatformIO

Open the project folder in VS Code with the PlatformIO extension installed.

### 3. Build

```bash
pio run
```

### 4. Upload

Connect your ESP32 and run:

```bash
pio run --target upload
```

### 5. Monitor Serial Output (optional)

```bash
pio device monitor
```

## Future Ideas

* Animations
* Better UI design
* Additional applications
* Wi-Fi features
* Persistent settings

## License

MIT License

Made for fun with ESP32.
