# wifi32

A wifi tool using the esp32

###### Fork of [ESP32-DIV](https://github.com/cifertech/ESP32-DIV) by CiferTech

# Requirements

## Software

- Latest Arduino IDE (`2.3.2` at the time of writing)

## Hardware

- ESP32 DevKitc v4 _(`other esp32 boards will have a different pin layout and won't work with the diagram`)_
- 1.8" TFT LCD with the ST7735x chip family using **SPI**
- 4 momentary buttons _(see [here](https://learn.sparkfun.com/tutorials/button-and-switch-basics/all) for information about buttons)_
- _(`Optional`)_ Breadboard
- _(`Optional`)_ Jumper wires

# Prerequisites

This will be a step-by-step guide to getting started with the wifi32 (ESP32-DIV).
<!-- In order to use the esp32 with the arduino IDE, a few steps must be done first. -->

### 1. Install the Arduino IDE
- Windows 7 - 10 _(`64bit`)_

Get the latest latest Arduino IDE at `https://www.arduino.cc/en/software`.

- Windows 11 _(`22000 and up`)_

Run:

```pwsh
winget install 9NBLGGH4RSD8
```
This will install the Arduino IDE using Windows'build in package manager from the Microsoft Store.

- Linux

Use your favorite package manager to install the arduino IDE.
If you don't know how, look it uo on Google.

### 2. ESP32 + Arduino

In order to program the esp32 using the Arduino IDE, it needs to be detected by the computer and by the IDE.

1. Head over to `File` >  `Preferences` > `Additional boards manager URLs` and add this line:

```
https://raw.githubusercontent.com/espressif/arduino-esp32/gh-pages/package_esp32_index.json
```

Click `OK` and wait for the list of boards to be indexed.

2. `Tools` > `Boards` > `Boards Manager...`. Search for ESP32 and click `Install`.

3. Your board needs drivers in order to communicate with the computer.

|Chip|Link|
|:-|-|
|`CP210X`|[click](https://www.silabs.com/developers/usb-to-uart-bridge-vcp-drivers?tab=downloads)|
|`CH340`|[click](https://learn.sparkfun.com/tutorials/how-to-install-ch340-drivers/all)|

After installing the driver restart your PC.

### 3. 