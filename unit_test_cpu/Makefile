CXX = aarch64-himix100-linux-g++
CC = aarch64-himix100-linux-gcc
AR = aarch64-himix100-linux-ar cqs

TOP_DIR = ..

TARGET_EXE=demo

####################face_detect source file################### 
CXX_SOURCE += unit_test.cpp 
####################head file###################
DEP_INC_DIR += -I$(TOP_DIR)/include/
DEP_INC_DIR += -I$(TOP_DIR)/include/mace
DEP_INC_DIR += -I$(TOP_DIR)/include/protobuf3.4.0 

####################ld flag###################
LDFLAGS+= $(TOP_DIR)/library/mace_cpu/libmace.a 
LDFLAGS+= $(TOP_DIR)/library/protobuf3.4.0/libprotobuf-lite.a  
LDFLAGS+=-fopenmp  -lm -pthread -lrt -ldl

OBJ_CPP := $(patsubst %.cpp, %.o, $(CXX_SOURCE))

DEFINE_MACRO := 

CPPFLAGS := -std=c++11 
CPPFLAGS += $(DEP_INC_DIR) $(DEFINE_MACRO) 

$(TARGET_EXE):$(OBJ_CPP)
	$(CXX) -o $@ $^ $(LDFLAGS)

%.o : %.cpp
	$(CXX) $(CPPFLAGS) -O3 -o $@ -c $< 

clean:
	rm -rf $(OBJ_CPP) $(TARGET_EXE)
