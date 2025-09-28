CC = gcc
CFLAGS = -Wall -g
TARGET = mem_cope
SRC = mem_cope.c add_cope.c
OBJ = $(SRC:.c=.o)
RM = rm -f
ifeq ($(OS),Windows_NT)
    RM = del /Q
endif

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ)

run: $(TARGET)
	./$(TARGET)

clean:
	$(RM) $(OBJ) $(TARGET).exe
