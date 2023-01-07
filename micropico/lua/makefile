CC = gcc
SRC_DIR = 
HAL_DIR = 
CFLAGS = -Wextra -g -I$(SRC_DIR) -I.
INCLUDE = 
DEPS = $(SRC_DIR)lua.h
LUA_OBJS = lapi.o lauxlib.o lbaselib.o lcode.o lcorolib.o lctype.o ldblib.o ldebug.o ldo.o ldump.o lfunc.o lgc.o linit.o liolib.o llex.o lmathlib.o lmem.o loadlib.o lobject.o lopcodes.o loslib.o lparser.o lstate.o lstring.o lstrlib.o ltable.o ltablib.o ltests.o ltm.o lundump.o lutf8lib.o lvm.o lzio.o
OBJS = $(LUA_OBJS)

all: main

main: main.o $(DEPS) $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDE) -o main main.o $(OBJS) -lws2_32

$(SRC_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(HAL_DIR)/%.o: $(HAL_DIR)/%.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

clean:
	rm *.o main.exe