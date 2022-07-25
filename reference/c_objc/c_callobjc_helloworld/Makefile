.PHONY: all clean

CC		= clang
FRAMEWORKS	= -framework Foundation -framework CoreFoundation
#BUILD_FLAGS	= -std=c99
BUILD_FLAGS	= -std=c99
BUILD_PATH	= ./bin 
SRCS		= *.c
OBJS		= $(SRC:.c=.o)
BIN		= main

all: $(BIN)

$(BIN): $(OBJS)
	$(CC) $(BUILD_FLAGS) $(FRAMEWORKS) $(SRCS) -o $@

clean:
	rm -rf $(BIN)
