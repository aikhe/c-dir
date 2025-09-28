CC = gcc
CFLAGS = -Wall -g

PROGRAM ?= argc_argv
MAIN = $(PROGRAM).c
SRC = $(wildcard $(PROGRAM)/*.c)
OBJ = $(patsubst $(PROGRAM)/%.c, $(BUILD)/%.o, $(SRC))
BUILD_DIR = .\\builds\\$(PROGRAM)
BUILD = ./builds/$(PROGRAM)/$(PROGRAM)

RM = rm -f
MKDIR = mkdir -p
ifeq ($(OS),Windows_NT)
    RM = rmdir /S /Q
    MKDIR = mkdir
endif

$(BUILD):
	$(MKDIR) $(BUILD_DIR)

$(PROGRAM): ./argc_argv.c | $(BUILD)
	$(CC) $(CFLAGS) -o $(BUILD) ./argc_argv.c

run: $(PROGRAM)
	$(BUILD)

clean: 
	$(RM) $(BUILD_DIR)
