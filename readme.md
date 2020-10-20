# RE:Flex Dance Panel v2 PCB Design 

This repository contains source documents and manufacturing files for the RE:Flex Dance Pad's Panel Board. It was created using [KiCAD 5.1.4](https://kicad-pcb.org/).

The Panel Boards purpose is to implement three subsystems underneath a standard dance pad 'panel':
- An interface for four [GML670 50kg Load Cell Sensors](http://www.gavincc.com/galoce/category-1/140.html). This subsystem conditions and amplifies the sensor differential input signals to prevent noise interference. The system is then sampled by an ADC at approximately 64kHz, and averaged to produce a clear 1kHz signal.
- Interface for a diamond-shaped grid of 84 RGB WS2813 LEDs at over 60Hz. On-board implementation of a 24->5V switch-mode power supply allows interface of standard brick PSUs to power a given board. There is also a 5V logic system for generating timing data that allows control of the RGB LED data.
- Interface for UART over RJ45, to communicate data from the I/O board for LED animations and to communicate data back to the I/O board for sensor data. The I/O USB interface allows for the generation of lighting data by computer program, and subsequent use of the analog sensor data gathered by Panel boards.

## Getting your own

For details on having your own made, see the [PCB manufacturing page](https://reflex.dance/manufacture/pcbs).

## Firmware

For the board to function, you will need to install the Panel board firmware to it, which can be found on the [firmware installation page](https://reflex.dance/firmware-installation).

## License

For license details, see LICENSE file