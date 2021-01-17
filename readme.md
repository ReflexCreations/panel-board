# RE:Flex Dance Panel v2 PCB Design 

This repository contains source documents and manufacturing files for the RE:Flex Dance Pad's Panel Board. It was created using [KiCAD 5.1.4](https://kicad-pcb.org/).

The Panel Boards purpose is to implement three subsystems underneath a standard dance pad 'panel':
- An interface for four [GML670 50kg Load Cell Sensors](http://www.gavincc.com/galoce/category-1/140.html). This subsystem conditions and amplifies the sensor differential input signals to prevent noise interference. The system is then sampled by an ADC at approximately 64kHz, and averaged to produce a clear 1kHz signal.
- Interface for a diamond-shaped grid of 84 RGB WS2813 LEDs at over 60Hz. On-board implementation of a 24->5V switch-mode power supply allows interface of standard brick PSUs to power a given board. There is also a 5V logic system for generating timing data that allows control of the RGB LED data.
- Interface for UART over RJ45, to communicate data from the I/O board for LED animations and to communicate data back to the I/O board for sensor data. The I/O USB interface allows for the generation of lighting data by computer program, and subsequent use of the analog sensor data gathered by Panel boards.

2. Place the order with [JLCPCB](https://jlcpcb.com)
```
    Open https://jlcpcb.com/ in your web browser.
    Click "Order Now" in the upper-right of the screen.
    Click "Add your gerber file", select the release-v2-RC2.zip file from the releases.
    Pick a PCB Qty.  It has to be a multiple of 5.  You will need 4 panel boards per platform.  Note that the per-board cost may reduce quite dramatically as you increase your order size.
    Pick a board color or leave it at the default green. Last time I checked different colors only affect build time, not price.
    Pick a surface finish or leave it on the default. The default is cheapest, but contains lead. ENIG gives the pads a nice golden finish instead of silver.
    Leave all the other options as they are.
    Scroll down to "SMT Assembly" and switch it on.  This means they will solder components on the board for you.  But not necessarily all of them.
    Select "assemble top side"
    Pick a quantity (SMT QTY).  If you picked 5 for the PCB Qty, you can choose to have only 2 assembled, to save money on parts and assembly fees.  Otherwise all of them will be assembled.
    Click "Confirm".
    On the right side of the page, click "Next"
    Click "Add BOM File"; upload the *release/bom.csv* file
    Click "Add CPL File"; upload the the *release/panel-board-top-pos.csv* file
    Click "Next"
    Review the specified parts; they should all be "confirmed" in the right column, so you can leave everything as it is.
        It's IMPORTANT to check this page carefully, as stock shortages are not at all uncommon, and will be reported on this page.
        If you proceed without addressing such issues, your order will go ahead but the missing components will be left out of the assembly process.  You will not be charged for these components, but they will not be mounted on your board either.
        Also note that this page only considers a single board when giving the cost for each component.  Don't worry.  The actual per-component cost you are charged will be based on the total quantity of the component mounted on all boards combined.  You will be able to confirm this in the Bill of Materials, viewable from the shopping cart page.
    Click "Next"
        In the preview, some ICs might look like they're oriented wrong. This is a problem with their viewer; the files are correct. If it ends up wrong (not aligning with the pads), they'll either correct it or email you to find a solution.
    Click "Save to cart"
        On the shopping cart page, you can access the Bill of Material for the SMT assembly, which will show exactly what you pay for each component.
        If the total cost here is lower than you expected, take it as a sign to double-check the Bill of Material and the "Unselected Parts" in the next tab, and look for parts that should have been supplied by JLCPCB but weren't.
    Click "Check out Securely"
    Add your shipping and billing details
    Select a shipping method. Usually the DHL-based ones are fine. You can gamble on whether or not you want duty and customs paid up front (more expensive), or hope for the best with the cheaper option, in which case you might get a bill from the courier later.
    Click "Continue" when you're happy
    Click "submit order"
    Do what you need to do for payment
    Wait for your boards to get delivered
```

3. Order the remaining through-hole parts - A list of these parts can be seen at `release/unpopulated.csv`. Companies that sell parts like this include Mouser, Digikey, RS-Components and Farnell.

4. Solder the remaining parts onto the board.  Here is a guide for each through-hole part on the panel board:
    J1 / Würth Elektronik 694106301002 / 2.1mm DC barrel jack connector: Easy.  Big contacts can take a lot of solder.  I put a folded paper towel under it to keep it pressed against the board while soldering, even when other components protrude a little further from the board.
    J2 / Amphenol FCI 54602-908LF / Rj45/ethernet connector: Snaps onto the board with plastic tabs so you don't have to worry about holding it in place.  These large components can make soldering other components more difficult, so it may be a good idea to leave the big ones until last.
    J3 / 3M 30310-6002HB / 10-pin ST-LINK connector with plastic fence: The gap in the fence goes on the side with pin 1 - the pin with the square solder pad.  The gap also faces towards the edge of the board.  I used a folded paper towel under this one.
    J4 / Harwin M20-9980446 / External Logic connector: It's quite possible you'll never use this connector.  Use a folded paper towel to help hold it in place.  Or leave it off the board entirely, which will probably lower the chances of damaging the 74HCT245 chip next to it with a static discharge.
    J5,J6,J7,J8 / Japan Solderless Terminals B4B-PH-K-S(LF)(SN) / load cell sensor connectors: The gap in the fence goes towards the inside of the board.  If you're looking at the side of the connector with that gap, pin 1 is on the right.  Unless you're holding it upside-down.  Just point the gap towards the middle of the board and you'll be okay.These things grip to the board quite well.
    SW1,SW2 / TE Connectivity 1825910-6: The pins lock into the board so you don't have to worry about it falling out of position.  When these switches are placed correctly, the pins come out on the left and right sides.

## Future Improvements
- Under test, several boards had broken level shifters / microcontrollers due to ESD under improper handling. This shouldn't be a problem if taking proper ESD precaution. Reducing susceptibility to ESD would be important to improve reliability of these boards for end users, though.
- The LEDs don't need to be powered by 5V. Running 4V is perfectly reasonable. And running the microcontroller at 3.6V could remove the requirement for the level shifter IC. This'd save money and complexity.
- Currently, there's a lot of connectors. We could daisy chain a number of boards if we utilized the correct UART transmission protocol. My hope is eventually to just have 3 RJ45 connectors, which can each address a maximum of 3 panels. 
- Switching to lower power LEDs would be nice. Currently they're far too bright and reducing their power consumption could make some things easier.
- We could also eliminate the need for all of the output DC power jacks by running power along the RJ45 cable, similar to 'Power over Ethernet'. This would probably depend on using low power LEDs.
- Step-down converter update. Currently it's a bit unwieldy. With lower power LEDs we could switch the electrolytics for an array of multiceramics to improve reliability. This would also be necessary for the daisy chaining method.
- The RS-485 transceivers probably don't need direction-switching, and the transceiver is entirely deprecated connected to the USART clock lines. We could save some microcontroller pins by removing this. This'd also make firmware updates to panel boards over UART a lot easier.
- Setting a panel 'address' via DIP switches. This'd make it easier to transfer information back about the sensor data, and allow the panel to be identified by software as a 'Left' or 'Up-Right' or any other type of panel. Especially useful for future daisy chained 9 panel implementations.
- Easier debugging. The status LEDs are ambiguous as to what they do. More status LEDs, more text indication on the board (e.g. 'Active UART comms' next to a status LED) could make things a lot easier for the end user.
- Future form factor updates. People might want to use these boards in an arcade pad. They may want to avoid the aluminium extrusion framework. Fitting this board for all sorts of different requirements will improve accessibility to the electronics.
- Board that doesn't need LEDs, or use external LED power source for running the panels. This will make things significantly cheaper for other variants. This board could also avoid the expensive conditioning of load cells if it could interface FSRs and digital sensors. 
- These boards could have through hole parts populated by a batch manufacturer, and be sold without the need for soldering. If you'd like to sell these boards, please get in touch, and we can help you source finished boards.

## Firmware

For the board to function, you will need to install the panel board firmware to it. You can find this information within the repo for the Panel-Firmware.

## License

For license details, see LICENSE file