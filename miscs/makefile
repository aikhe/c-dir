CC = gcc
CFLAGS = -Wall -g

PROGRAM ?= argc_argv
MAIN = $(PROGRAM).c
SRC = $(wildcard $(PROGRAM)/*.c)
OBJ = $(patsubst $(PROGRAM)/%.c, $(BUILD_DIR)/%.o, $(SRC))
BUILD_DIR = ./builds/$(PROGRAM)
BUILD = $(BUILD_DIR)/$(PROGRAM)

RM = rm -rf
MKDIR = mkdir -p
ifeq ($(OS),Windows_NT)
    RM = rmdir /S /Q
    MKDIR = powershell -Command "if (-not (Test-Path '$(BUILD_DIR)')) { mkdir '$(BUILD_DIR)' }"
endif

$(BUILD_DIR):
	$(MKDIR)

$(PROGRAM): ./$(MAIN) | $(BUILD_DIR)
	$(CC) $(CFLAGS) -o $(BUILD) ./$(MAIN)

gemini_rest: ./gemini_rest.c | $(BUILD_DIR)
	$(CC) gemini_rest.c -I"../include" -L"../lib" -lcurl -o ./builds/gemini_rest/gemini_rest

run: $(PROGRAM)
	$(BUILD)

clean:
	$(RM) $(BUILD_DIR)
