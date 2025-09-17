#include <stdio.h>
#include <stdlib.h>

#include "append_int.h"

// declare params pointer, asteris so it can read and reflect changes to
// passed arguments from main function
void append_int(int **arr, int *size, int *capacity, int value) {
  // doubles capacity if 0
  *capacity = (*capacity == 0) ? 1 : (*capacity + 1);
  int *new_arr = realloc(*arr, (*capacity) * sizeof(int));
  *arr = new_arr;

  // this is where the magic happen, appends each value
  (*arr)[*size] = value;
  (*size)++;
}

int main() {
  int *arr = NULL;
  int size = 0;
  int capacity = 0;

  for (int i = 0; i < 5; ++i) {
    append_int(&arr, &size, &capacity, i);
  }

  for (int i = 0; i < size; ++i) {
    printf("%d \n", arr[i]);
  }
  printf("size: %d \n", size);
  printf("capacity: %d \n", capacity);

  printf("\n");

  for (int i = 0; i < 5; ++i) {
    append_int_sample(&arr, &size, &capacity, i);
  }

  printf("\n");

  for (int i = 0; i < size; ++i) {
    printf("%d \n", arr[i]);
  }
  printf("size: %d \n", size);
  printf("capacity: %d \n", capacity);

  // deallocate dynamic memory (prevents memory leak), used with realloc() &
  // malloc()
  free(arr);

  return 0;
}
