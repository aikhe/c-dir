CC = gcc
CFLAGS = -Wall -g

MAIN ?= array_dump.c

# collect all sources: main.c in root + everything in array_dump/
SRC := $(MAIN) $(wildcard array_dump/*.c)

# map sources directly to build/*.o 
# this line means: for each .c file in SRC, generate an .o filename inside BUILD_DIR, stripping away the directory path.
OBJ := $(patsubst %.c,builds/array_dump/%.o,$(notdir $(SRC)))

all: $(OBJ)

build:
	mkdir builds\array_dump

# compile root sources
builds/array_dump/%.o: array_dump.c build
	$(CC) $(CFLAGS) -c $< -o $@

# compile array_dump/ sources
builds/array_dump/%.o: array_dump/%.c build
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rmdir /S /Q .\builds\array_dump
