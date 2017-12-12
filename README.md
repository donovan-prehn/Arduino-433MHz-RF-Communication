# Arduino-433MHz-RF-Communication
Communicating analog data over low-cost RF modules between Arduino microcontrollers

## Project Description

Communication of analog data over RF between two Arduino microcontrollers. The analog data we use is from a light-dependent resistor being read by an Arduino Nano.

We used the popular low-cost 433MHz RF Transmitter & Receiver pair, there is no complex hardware encoding or decoding on these devices. A HIGH signal on the transmitter will produce a HIGH signal on the receiver. We use the Arduino VirtualWire library to encode our data as well as provide error-checking.

The analog light value is received by an Arduino Uno which prints the value onto an attached LCD Keypad Shield.

## Setup

### Install Arduino
Download and Install <a href="https://www.arduino.cc/en/Main/Software"> Arduino IDE</a>

### Set-up VirtualWire
1. Download <a href="http://www.airspayce.com/mikem/arduino/VirtualWire/">VirtualWire Library</a>
2. Import in Arduino IDE  ```Sketch -> Include Library -> Add .Zip Library...```

### Set-up Arduino
1. Open **transmitter.c** or **receiever.c** in Arduino IDE
2. Select Board in Arduino IDE  ```Tools -> Board: XXXXX```
3. Select ```Sketch -> Upload```

## Hardware

**Transmitter**
- Arduino Nano
- FS1000A

**Receiver**
- Arduino Uno
- XY-MK-5V
## Dependencies
-  Python3.6
- <a href="http://www.airspayce.com/mikem/arduino/VirtualWire/">VirtualWire Library</a>
