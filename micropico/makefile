CC = gcc
SRC_DIR = ../src
HAL_DIR = ../micropico
CFLAGS = -Wextra -g -I$(SRC_DIR) -I.
INCLUDE = -I$(HAL_DIR) -I./lua -I../src
DEPS = picoglue.h $(SRC_DIR)/ssd1351.h $(SRC_DIR)/fonts.h $(SRC_DIR)/sprites.h $(SRC_DIR)/color_palette.h $(HAL_DIR)/myHAL.h $(HAL_DIR)/socketSPI.h lua/lua.h
LUA_OBJS = lua/lapi.o lua/lauxlib.o lua/lbaselib.o lua/lcode.o lua/lcorolib.o lua/lctype.o lua/ldblib.o lua/ldebug.o lua/ldo.o lua/ldump.o lua/lfunc.o lua/lgc.o lua/linit.o lua/liolib.o lua/llex.o lua/lmathlib.o lua/lmem.o lua/loadlib.o lua/lobject.o lua/lopcodes.o lua/loslib.o lua/lparser.o lua/lstate.o lua/lstring.o lua/lstrlib.o lua/ltable.o lua/ltablib.o lua/ltests.o lua/ltm.o lua/lundump.o lua/lutf8lib.o lua/lvm.o lua/lzio.o
OBJS = $(LUA_OBJS) picoglue.o $(SRC_DIR)/ssd1351.o $(SRC_DIR)/color_palette.o $(SRC_DIR)/fonts.o $(SRC_DIR)/sprites.o $(HAL_DIR)/myHAL.o $(HAL_DIR)/socketSPI.o

all: main

main: main.o $(DEPS) $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDE) -o main main.o $(OBJS) -lws2_32

$(SRC_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(HAL_DIR)/%.o: $(HAL_DIR)/%.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

clean:
	rm *.o main.exe