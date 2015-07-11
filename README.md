# ubirch-sketches

Sketches for the ubirch #1 board.

It is a playground for working with the board and peripherals as well as a testing
area to identify what is possible with the board.

- *interrupts* - how to initialize an interrupt and have a co-routine do work
- *hc-sr04-led* - a little sketch utilizing the HC-SR04 ultra-sonic board
- *hc-sr04-intr* - a combination of interrupts and the distance sensor
- *sim800h* - a simple serial terminal to the SIM800H chip onboard
- *sim800h-tcp* - testing the TCP capabilities of the SIM800H

## using make

Install
Edit arduino.mk to match the location of the [arduino-makefile](https://github.com/sudar/Arduino-Makefile).
Then you can use the editor of your choice and make to compile, upload and run your sketches.

Mostly you would run make inside of your sketch directory: ```cd sim800h; make upload monitor```, 
however you can also build all sketches using ```make``` or an individual sketch using ```make sketch```. 
 
## ubirch #1

This is the board. In comparison to a test board with (similar to Arduino Uno) with the FONA shield.

![ubirch #1](docs/ubirch%231.jpg?raw=true)
