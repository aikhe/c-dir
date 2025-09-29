CC = gcc
CFLAGS = -Wall -g

PROGRAM ?= argc_argv
MAIN = $(PROGRAM).c
SRC = $(wildcard $(PROGRAM)/*.c)
OBJ = $(patsubst $(PROGRAM)/%.c, $(BUILD_DIR)/%.o, $(SRC))
BUILD = ./builds/$(PROGRAM)/$(PROGRAM)

ifeq ($(OS),Windows_NT)
	BUILD_DIR = .\builds\$(PROGRAM)

	RM = rmdir /S /Q
	MKDIR = mkdir
else
	BUILD_DIR = ./builds/(PROGRAM)

	RM = rm -rf
	MKDIR = mkdir -pa
endif

$(BUILD_DIR):
	$(MKDIR) $(BUILD_DIR)

$(PROGRAM): ./$(MAIN) | $(BUILD_DIR)
	$(CC) $(CFLAGS) -o $(BUILD) ./$(MAIN)

gemini_rest: $(MAIN) | $(BUILD_DIR)
	$(CC) gemini_rest.c -I"../include" -L"../lib" -lcurl -o ./builds/gemini_rest/gemini_rest

run: $(PROGRAM)
	$(BUILD)

clean:
	$(RM) $(BUILD_DIR)
