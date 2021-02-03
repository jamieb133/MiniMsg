# additional libraries (e.g. SoftwareSerial just get chucked into this same archive for simplicity)

INC = -I$(AVRCORE_DIR)/cores/arduino
INC += -I$(AVRCORE_DIR)/variants/standard
INC += -I$(AVRCORE_DIR)/libraries/SoftwareSerial/src

SRC_DIR = $(AVRCORE_DIR)/cores/arduino
SRC_C := $(wildcard $(SRC_DIR)/*.c)
SRC_CXX := $(wildcard $(SRC_DIR)/*.cpp)
SRC_CXX += $(AVRCORE_DIR)/libraries/SoftwareSerial/src/SoftwareSerial.cpp
SRC_ASM := $(wildcard $(SRC_DIR)/*.S)

_OBJ = $(SRC_C:.c=.o)
_OBJ += $(SRC_CXX:.cpp=.o)
_OBJ += $(SRC_ASM:.S=.o)
OBJ = $(patsubst %,$(ODIR)/%,$(notdir $(_OBJ)))

BINDIR = bin/avrcore
ODIR = $(BINDIR)/obj
.PHONY: all clean bin testapp

all: libavrcore.a 

$(ODIR)/%.o: $(SRC_DIR)/%.c 
	$(CC) $(INC) -MMD $(CFLAGS) -c $< -o $@

$(ODIR)/%.o: $(AVRCORE_DIR)/libraries/SoftwareSerial/src/%.cpp 
	$(CC) $(INC) -MMD $(CFLAGS) -c $< -o $@

$(ODIR)/%.o: $(SRC_DIR)/%.cpp 
	$(CXX) $(INC) -MMD $(CPPFLAGS) -c $< -o $@ 

$(ODIR)/%.o: $(SRC_DIR)/%.S 
	$(ASM) $(INC) -MMD $(ASM_FLAGS) -c $< -o $@  

libavrcore.a: $(OBJ) 
	$(AR) rcs $(BINDIR)/$@ $^
	#$(RANLIB) $(BINDIR)/$@

clean:
	echo $(OBJ)
	rm -rf $(BINDIR) avrcore.a
