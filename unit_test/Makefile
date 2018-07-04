CXX = arm-hisiv600-linux-g++
CC = arm-hisiv600-linux-gcc
AR = arm-hisiv600-linux-ar cqs

TOP_DIR = ..

TARGET_EXE=demo

####################face_detect source file################### 
CXX_SOURCE += unit_test.cpp 
####################head file###################
DEP_INC_DIR += -I$(TOP_DIR)/include/
DEP_INC_DIR += -I$(TOP_DIR)/include/mace
DEP_INC_DIR += -I$(TOP_DIR)/include/protobuf3.4.0
#DEP_INC_DIR += -I$(TOP_DIR)/include/opencv2.4.9 
#DEP_INC_DIR += -I$(TOP_DIR)/include/opencv2.4.9/opencv 
#DEP_INC_DIR += -I$(TOP_DIR)/include/opencv2.4.9/opencv2 

####################ld flag###################
LDFLAGS+= $(TOP_DIR)/library/mace/libmace.a 
LDFLAGS+= $(TOP_DIR)/library/protobuf3.4.0/libprotobuf.a
LDFLAGS+= $(TOP_DIR)/library/protobuf3.4.0/libprotobuf-lite.a
LDFLAGS+= $(TOP_DIR)/library/protobuf3.4.0/libprotoc.a
#LDFLAGS+= -L$(TOP_DIR)/library/opencv2.4.9 
#LDFLAGS+= -lopencv_video -lopencv_highgui -lopencv_imgproc -lopencv_core 
#LDFLAGS+= -llibjpeg -lz
LDFLAGS+=  -lm -pthread  -lrt -ldl

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
