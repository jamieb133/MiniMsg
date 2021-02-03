SRC_DIR = $(MINIMSG_DIR)/src
SRC := $(wildcard $(SRC_DIR)/*.cpp)

AVRCORE_INC = $(AVRCORE_DIR)/cores/arduino $(AVRCORE_DIR)/variants/standard
INC_DIR = $(MINIMSG_DIR)/inc
INC := $(addprefix -I,$(INC_DIR))
INC += $(addprefix -I,$(AVRCORE_INC))

BINDIR = bin/minimsg
ODIR = $(BINDIR)/obj
_OBJ := $(notdir $(SRC))
_OBJ := $(_OBJ:.cpp=.o)
OBJ := $(patsubst %,$(ODIR)/%,$(_OBJ))

.PHONY: all clean bin testapp inputs

all: libavrcore.a print_src

$(OBJ):$(ODIR)%.o : $(SRC_DIR)%.cpp 
	$(CXX) $(INC) -MMD $(CPPFLAGS) -c $< -o $@ 

libmsg.a: $(OBJ)
	
	$(AR) rcs $(BINDIR)/$@ $^

clean:
	echo $(OBJ)
	rm -rf $(BINDIR) avrcore.a
