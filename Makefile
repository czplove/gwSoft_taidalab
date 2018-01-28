CC_MIPS = g++

#the [-D] parmeter's description as follows:
#:_RELEASE_ : used when the application is released.
#:_TEST_CONNECT_:used when cloudserver is vitual . configure file is readed. File name is 'csaddresr', path is currently path.

#test the exception of cloudser 
#CFLAGS = -D _TEST_CONNECT_

#5350 debug
CFLAGS =  -D PLATFORM_DREAMFLOWER 
OUTPUT_NAME = SmartHome-MIPS-p
OBJ_DIR = $(shell pwd)/debug/obj/5350

#5350 debug + hardware debug
#CqFLAGS =  -D PLATFORM_MIPS -D _HardWare_Debug_
#OUTPUT_NAME = SmartHome-MIPS-p-hardware
#OBJ_DIR = $(shell pwd)/debug/obj/5350_hardware

#5350 released + SoftWare debug
#CFLAGS =  -D _RELEASE_ -D PLATFORM_MIPS -D _SoftWare_Debug_
#OUTPUT_NAME = SmartHome-MIPS-r-Software
#OBJ_DIR = $(shell pwd)/release/obj/5350_Software

#yun jia debug
#CFLAGS =  -D PLATFORM_MIPS -D PLATFORM_MIPS_YUNJIA
#OUTPUT_NAME = SmartHome-MIPS-p-yunjia
#OBJ_DIR = $(shell pwd)/debug/obj/yunjia


#yun jia released + hardware debugg
#CFLAGS = -D _RELEASE_ -D PLATFORM_MIPS -D PLATFORM_YUNJIA -D _HardWare_Debug_
#OUTPUT_NAME = SmartHome-MIPS-r-yunjia-hardware
#OBJ_DIR = $(shell pwd)/release/obj/yunjia_hardware

#7620 debug
#CFLAGS =  -D PLATFORM_MIPS_7620 
#OUTPUT_NAME = SmartHome-MIPS-p-7620
#OBJ_DIR = $(shell pwd)/debug/obj/7620


#7620 released + hardware debug
#CFLAGS =  -D _RELEASE_ -D PLATFORM_MIPS_7620 -D _HardWare_Debug_
#OUTPUT_NAME = SmartHome-MIPS-r-7620-hardware
#OBJ_DIR = $(shell pwd)/release/obj/7620_hardware

#7620 released + software debug
#CFLAGS =  -D _RELEASE_ -D PLATFORM_MIPS_7620 -D _SoftWare_Debug_
#OUTPUT_NAME = SmartHome-MIPS-r-7620-softdware
#OBJ_DIR = $(shell pwd)/release/obj/7620_software

#H3C debug
#CFLAGS = -D PLATFORM_MIPS_H3C 
#OUTPUT_NAME = SmartHome-MIPS-p-h3c
#OBJ_DIR = $(shell pwd)/debug/obj/h3c

#H3C released
#CFLAGS = -D _RELEASE_ -D PLATFORM_MIPS_H3C 
#OUTPUT_NAME = SmartHome-MIPS-r-h3c
#OBJ_DIR = $(shell pwd)/release/obj/h3c

INCLUDE = -I/home/tzz/boost_1_56_0

LDFLAGS_MIPS = -L/home/tzz/boost_1_56_0/lib/ \
			   /home/tzz/boost_1_56_0/lib/libboost_system.a /home/tzz/boost_1_56_0/lib/libboost_thread.a -lpthread
			   
OBJS = $(OBJ_DIR)/main.o $(OBJ_DIR)/PlatformInit.o $(OBJ_DIR)/CommonFunc.o 

SmartHome-MIPS : $(OBJS)
	$(CC_MIPS) $(CFLAGS) $(INCLUDE)  -O2 -o $(OUTPUT_NAME)  $(OBJS) $(LDFLAGS_MIPS)

$(OBJ_DIR)/main.o : main.cpp #-./threadfunc/ThreadFunc.hpp
	$(CC_MIPS) $(CFLAGS) $(INCLUDE)  -c -O2 -o $@ main.cpp

$(OBJ_DIR)/PlatformInit.o : ./platform/PlatformInit.cpp ./common/GlobalConfig.hpp ./platform/PlatformInit.hpp \
	./common/CommonFunc.hpp
	$(CC_MIPS) $(CFLAGS) $(INCLUDE)  -c -O2 -o $@ ./platform/PlatformInit.cpp
	
$(OBJ_DIR)/CommonFunc.o : ./common/CommonFunc.cpp ./common/CommonFunc.hpp
	$(CC_MIPS) $(CFLAGS) $(INCLUDE)  -c -O2 -o $@ ./common/CommonFunc.cpp

#$(OBJ_DIR)/log.o : ./log/log.cpp ./log/log.h
#	$(CC_MIPS) $(CFLAGS) $(INCLUDE)  -c -O2 -o $@ ./log/log.cpp

#-strip:
#-	mipsel-openwrt-linux-strip $(OUTPUT_NAME)
#-	cp $(OUTPUT_NAME) ../tftpserver
.PHONY: clean 
clean:
	-rm -f $(OBJS) 
