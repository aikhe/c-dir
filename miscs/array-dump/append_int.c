#include <stdlib.h>

#include "append_int.h"

// declare params pointer, asteris so it can read and reflect changes to
// passed arguments from main function. passed as address so needs to
// dereference using asterisk. also pointer-to-pointer arr since its defined as
// a pointer
void append_int(int **arr, int *size, int *capacity, int value) {
  // doubles capacity if 0, this capacity will then be used by arr
  *capacity = (*capacity == 0) ? 1 : (*capacity + 1);
  int *new_arr = realloc(*arr, (*capacity) * sizeof(int));
  *arr = new_arr;

  // this is where the magic happen, appends each value
  (*arr)[*size] = value;
  (*size)++;
}
