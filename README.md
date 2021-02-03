# MiniMsg

## Overview
Small embedded messaging stack. Designed to be platform/comms agnostic but aiming for COBS encoded serial packetisation using an arduino uno (avr) to start with.

## Prerequisites
*TODO: docker container instead*

* **avr-gcc toolchain** 
* **avrdude** for flashing
* **screen** for serial monitor (optional)

Change relevant config variables at start of top-level Makefile e.g.
```
#------------------------------------------------------#
#----------------------toolchain ----------------------#
#------------------------------------------------------#
export AVR_ROOT = <path to avr toolchain>
export AVR_GCC= $(AVR_ROOT)/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin

#------------------------------------------------------#
#-------------------flashing tools --------------------#
#------------------------------------------------------#
export DEVICE = /dev/<connected usb serial port>
export AVRDUDE_CONF = <location of avrdude.conf file>/avrdude.conf
export BAUDRATE = <baudrate for upload e.g. 115200>
```