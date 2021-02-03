#------------------------------------------------------#
#----------------------toolchain ----------------------#
#------------------------------------------------------#
export AVR_ROOT = /Users/jamiebrown/Library/Arduino15/packages/arduino/tools
export AVR_GCC= $(AVR_ROOT)/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin

export CC = $(AVR_GCC)/avr-gcc
export CXX = $(AVR_GCC)/avr-g++
export ASM = $(AVR_GCC)/avr-gcc
export AR = $(AVR_GCC)/avr-gcc-ar
export RANLIB = $(AVR_GCC)/avr-gcc-ranlib
export NM = $(AVR_GCC)/avr-gcc-nm
export OBJCOPY = $(AVR_GCC)/avr-objcopy
export AVRSIZE = $(AVR_GCC)/avr-size
export AVRDUDE = $(AVR_ROOT)/avrdude/6.3.0-arduino17/bin/avrdude

#------------------------------------------------------#
#------------------------flags-------------------------#
#------------------------------------------------------#
export CFLAGS = $(INC) -Os -w -std=gnu11 -ffunction-sections -fdata-sections  $(BOARD_DEFS)
export CPPFLAGS = $(INC)  -Os -Wno-error=narrowing -ffunction-sections -fdata-sections -fno-exceptions -fno-threadsafe-statics $(BOARD_DEFS) #-flto -x c++ -Os   
export ASM_FLAGS=$(INC) -x assembler-with-cpp # -flto 
export LDFLAGS = -w -Os -fuse-linker-plugin -Wl,--gc-sections #-flto
export BOARD_DEFS = -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10607 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR
export EEP_FLAGS = -O ihex -j .eeprom --set-section-flags=.eeprom=alloc,load --no-change-warnings --change-section-lma .eeprom=0
export ELF2HEX_FLAGS = -O ihex -R .eeprom

#------------------------------------------------------#
#-------------------flashing tools --------------------#
#------------------------------------------------------#
export DEVICE = /dev/cu.usbmodem141101
export AVRDUDE_CONF = /Users/jamiebrown/Library/Arduino15/packages/arduino/tools/avrdude/6.3.0-arduino17/etc/avrdude.conf
export BAUDRATE = 115200

export MINIMSG_DIR = MiniMsg
export AVRCORE_DIR = ArduinoCore-avr

MAKE = make 

.PHONY: avrcore minimsg testapp clean

avrcore: bin
	$(MAKE) -f make/avrcore.mk all

minimsg: bin
	$(MAKE) -f make/minimsg.mk libmsg.a

testapp: avrcore minimsg
	$(MAKE) -f make/testapp.mk testapp

upload: testapp
	$(MAKE) -f make/testapp.mk upload

screen: upload
	screen $(DEVICE) 9600

bin:
	mkdir -p bin
	mkdir -p bin/avrcore
	mkdir -p bin/avrcore/obj
	mkdir -p bin/minimsg
	mkdir -p bin/minimsg/obj
	mkdir -p bin/testapp
	mkdir -p bin/testapp/obj

debug:
	$(MAKE) -f make/minimsg.mk debug_make

all: avrcore

clean:
	rm -rf bin
	$(MAKE) -f make/avrcore.mk clean
