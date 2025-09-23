CC = gcc
CFLAGS = -Wall -g
TARGET = array_dump
SRC = array_dump.c append_int.c
OBJ = $(SRC:.c=.o)
RM = rm -f
ifeq ($(OS),Windows_NT)
    RM = del /Q
endif

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC)

run: $(TARGET)
	./$(TARGET)

clean:
	$(RM) $(OBJ) $(TARGET).exe
