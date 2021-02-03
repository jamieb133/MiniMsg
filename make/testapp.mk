INC = $(MINIMSG_DIR)/inc
INC += ./ArduinoCore-avr/cores/arduino 
INC += ./ArduinoCore-avr/variants/standard
INCFLAGS = $(addprefix -I,$(INC))

SRC_DIR = examples/testapp
SRC = $(wildcard $(SRC_DIR)/*.cpp)

CPPFLAGS = -g -Wno-error=narrowing -ffunction-sections -fdata-sections -fno-exceptions -fno-threadsafe-statics -flto $(BOARD_DEFS) -x c++     
LDFLAGS = -w -Os -g -flto -fuse-linker-plugin -Wl,--gc-sections  $(BOARD_DEFS) #`-mmcu=atmega328p

BINDIR = bin/testapp
ODIR = $(BINDIR)/obj

AVRCORE = bin/avrcore
MINIMSG = bin/minimsg

LIBS = -L$(AVRCORE) -L$(MINIMSG) -lm -lavrcore -lmsg 

OBJ = $(patsubst $(SRC_DIR)%.cpp,$(ODIR)%.o, $(SRC))

all: testapp

$(ODIR)/%.o: $(SRC_DIR)/%.cpp
	$(info COMPILING $(SRC) ------> $(OBJ))
	$(CXX) $(INCFLAGS) $(CPPFLAGS) -c $< -o $@ 

testapp.elf: $(OBJ) 
	$(CC) $(LDFLAGS) -o $(BINDIR)/$@ $^ $(LIBS)

testapp.eep: testapp.elf
	$(OBJCOPY) $(EEP_FLAGS) $(BINDIR)/$(@:.eep=.elf) $(BINDIR)/$@ 
	
testapp.hex: testapp.elf testapp.eep
	$(OBJCOPY) $(ELF2HEX_FLAGS) $(BINDIR)/$(@:.hex=.elf) $(BINDIR)/$@

testapp: testapp.hex
	$(AVRSIZE) -A $(BINDIR)/$(^:.hex=.elf)

upload: testapp.hex
	$(AVRDUDE) -C$(AVRDUDE_CONF) -v -patmega328p -carduino -P$(DEVICE) -b$(BAUDRATE) -D -Uflash:w:$(BINDIR)/$^:i 

.PHONY: clean avrcore bin testapp

clean:
	echo $(OBJ)
	rm -rf $(BINDIR) avrcore.a
