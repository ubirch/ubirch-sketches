# https://github.com/sudar/Arduino-Makefile
# http://hardwarefun.com/tutorials/compiling-arduino-sketches-using-makefile
# currently works with Arduino SDK 1.6.4

# if you want to see configuration settings, comment out the next line
ARDUINO_QUIET=1

BOARD_TAG=uno
ARDUINO_PORT=/dev/cu.SLAB_USBtoUART

# you need to change this to your actual location of the arduino-mk installation
include /usr/local/opt/arduino-mk/Arduino.mk
