#include <stdio.h>
#include <stdlib.h>

char *read_file(const char *filename) {
  FILE *fptr = fopen(filename, "rb");
  if (!fptr)
    return NULL;

  fseek(fptr, 0, SEEK_END);  // move position indicator to end
  long length = ftell(fptr); // get length
  rewind(fptr);              // move position indicator to end

  char *data = malloc(length + 1); // add 1 for null terminator
  fread(data, 1, length, fptr);    // this is where data finally gets read
  data[length] =
      '\0'; // add null terminator (crucial for printf & other string functions)
  fclose(fptr);

  return data;
}

int main(void) {
  char *file_data = read_file("read_file/example.txt");

  printf("%s", file_data);
}
