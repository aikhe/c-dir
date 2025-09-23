#include <stdio.h>
#include <stdlib.h>

#include "append_int.h"

// declare params pointer, asteris so it can read and reflect changes to
// passed arguments from main function
void append_int(int **arr, int *size, int *capacity, int value) {
  if (*size >= *capacity) {
    // doubles capacity if 0
    *capacity = (*capacity == 0) ? 1 : (*capacity * 2);
    int *new_arr = realloc(*arr, (*capacity) * sizeof(int));

    // if (!new_arr) {
    //   fprintf(stderr, "Memory allocation failed\n");
    //   exit(EXIT_FAILURE);
    // }

    // apply new changes to arr
    *arr = new_arr;
  }

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

  // deallocate dynamic memory (prevents memory leak), used with realloc() &
  // malloc()
  free(arr);

  printf("\n");

  // int *pSize = &size;
  // printf("%d \n", *pSize);
  // printf("%d \n", size);
  //
  // printf("\n");

  for (int i = 0; i < 5; ++i) {
    array_int_sample(&arr, &size, &capacity, i);
  }

  printf("\n");

  for (int i = 0; i < size; ++i) {
    printf("%d \n", arr[i]);
  }

  return 0;
}
