# http://hardwarefun.com/tutorials/compiling-arduino-sketches-using-makefile
# currently works with Arduino SDK 1.6.4

BOARD_TAG=uno
ARDUINO_PORT=/dev/cu.SLAB_USBtoUART

include /usr/local/opt/arduino-mk/Arduino.mk
