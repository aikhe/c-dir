#include <stdlib.h>

#include "append_int.h"

void append_int_sample(int **arr, int *size, int *capacity, int value) {
  *capacity = (*capacity == 0) ? 1 : (*capacity + 1);
  int *new_arr = realloc(*arr, (*capacity) * sizeof(int));
  *arr = new_arr;

  (*arr)[*size] = value;
  (*size)++;
}
