CC = gcc
CFLAGS = -Wall -g

PROGRAM ?= main
MAIN = $(PROGRAM).c
BUILD_DIR = builds/$(PROGRAM)
SRC := $(MAIN) $(wildcard $(PROGRAM)/*.c)
OBJ := $(patsubst %.c,$(BUILD_DIR)/%.o,$(notdir $(SRC)))
TARGET := $(BUILD_DIR)/array_dump

ifeq ($(OS),Windows_NT)
	RM = rmdir /S /Q
	MKDIR = mkdir
else
	RM = rm -rf
	MKDIR = mkdir -pa
endif

all: $(TARGET)

# make respective build dir
$(BUILD_DIR):
	$(MKDIR) builds\$(PROGRAM)

# Compile root source
$(BUILD_DIR)/%.o: %.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Compile src/ sources
$(BUILD_DIR)/%.o: $(PROGRAM)/%.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

gemini_rest: $(MAIN) | build
	$(CC) gemini_rest.c -I"../include" -L"../lib" -lcurl -o ./builds/gemini_rest/gemini_rest

# make executable
$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $(OBJ)

run: $(TARGET)
	./$(TARGET)

clean:
	$(RM) builds\$(PROGRAM)
