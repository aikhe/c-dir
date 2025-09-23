#include "append_int.h"
#include <stdio.h>

void array_int_sample(int **arr, int *size, int *capacity, int value) {
  printf("%d \n", *size);

  (*arr)[*size] = value;
  (*size)++;
}
