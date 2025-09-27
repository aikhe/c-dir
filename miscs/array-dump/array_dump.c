#include <stdio.h>
#include <stdlib.h>

#include "append_int.h"

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

  // deallocate dynamic memory (prevents memory leak), used with realloc() &
  // malloc()
  free(arr);

  return 0;
}
