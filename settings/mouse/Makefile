#-*-mode:makefile-gmake;indent-tabs-mode:t;tab-width:8;coding:utf-8-*-┐
#───vi: set et ft=make ts=8 tw=8 fenc=utf-8 :vi───────────────────────┘

FRAMEWORKS	= -framework Carbon
BUILD_PATH	= ./bin
BUILD_FLAGS	= -std=gnu89 -Wall -g
SRC			= sensitivity.c
BIN			= $(BUILD_PATH)/sensitivity

.PHONY:	all clean install

all: clean $(BIN)

install: BUILD_FLAGS=-std=gnu89 -O3
install: clean $(BIN)

clean:
	rm -rf $(BUILD_PATH)

$(BIN): $(SRC)
	mkdir -p $(BUILD_PATH)
	clang $^ $(BUILD_FLAGS) $(FRAMEWORKS) -o $@
