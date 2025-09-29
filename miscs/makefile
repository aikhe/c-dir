CC = gcc
CFLAGS = -Wall -g

PROGRAM ?= main
BUILD_DIR = builds/$(PROGRAM)
TARGET := $(BUILD_DIR)/$(PROGRAM)
ifeq ($(OS),Windows_NT)
	RM = rmdir /S /Q
	MKDIR = mkdir
else
	RM = rm -rf
	MKDIR = mkdir -pa
endif

# make respective build dir
$(BUILD_DIR):
	$(MKDIR) builds\$(PROGRAM)

ifeq ($(PROGRAM),gemini_rest)
# special rule, no object compilation
$(TARGET): gemini_rest.c | $(BUILD_DIR)
	$(CC) gemini_rest.c -I"../include" -L"../lib" -lcurl -o $(TARGET)
else ifneq (,$(filter $(PROGRAM),something))
	# else if
else
	MAIN = $(PROGRAM).c
	SRC := $(MAIN) $(wildcard $(PROGRAM)/*.c)
	OBJ := $(patsubst %.c,$(BUILD_DIR)/%.o,$(notdir $(SRC)))
	
	# compile root source
	$(BUILD_DIR)/%.o: %.c | $(BUILD_DIR)
		$(CC) $(CFLAGS) -c $< -o $@
	
	# compile respective dir sources
	$(BUILD_DIR)/%.o: $(PROGRAM)/%.c | $(BUILD_DIR)
		$(CC) $(CFLAGS) -c $< -o $@
	
	# make executable
	$(TARGET): $(OBJ)
		$(CC) $(CFLAGS) -o $@ $(OBJ)
endif

run: $(TARGET)
	./$(TARGET)

clean:
	$(RM) builds\$(PROGRAM)
