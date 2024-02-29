
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

### 3. Hardware Connections

> Until I create a schematic for the hardware connections you can use this simple diagram.

###### The pinout is unchanged from CiferTech's design.
|esp32 Pin|Display Pin|Function|
|:-:|:-:|:-|
|14|CS|Chip Select|
|33|RST|Reset|
|27|DC|Data/Command|
|23|DIN|Data out|
|18|CLK|Clock out|
|5V|VCC|5v Power|
|3v3|LED|Backlight|
|GND|GND|Ground|

|esp32 Pin|Function|
|:-:|:-|
|21|Up|
|22|Down|
|25|Select|
|26|Back|

###### I'll add more information about wiring later
###### The original code seems to have a bug with the back button

### 4. Flashing Software

1. Clone the repo
```sh
git clone https://github.com/syphr0/wifi32
```

2. Open the repo in Arduino and install all needed libraries.

<details><summary>List of required libraries</summary>
    <ul>
        <li>Adafruit_GFX</li>
        <li>Adafruit_ST7735</li>
        <li>Adafruit_NeoPixel</li>
        <li>FS<a href="#library-help">*</a></li>
        <li>SD<a href="#library-help">*</a></li>
        <li>SPI.h</li>
        <!-- <li></li> -->
    </ul>
</details>

<br>

3. Connect the esp32 to the computer and select the right COM port along with the board. For this project it should be the `ESP32 Dev Module`.

4. You can now flash the board. 

> If there are issues you can't fix, Create a new issue [here](https://github.com/syphr0/wifi32/issues/new/choose), if you can, create an issue with the tag `Bugfix` detailing what's broken and how we can fix it.

### Library Help
> You can find the libraries marked with a `*` in the [`required-libs`]() folder. I'll keep them updated. Copy them into your library folder (`Arduino/libraries/`).



