#include <stdio.h>
#include <stdlib.h>

typedef struct Point {
  int p;
} Point;

int main() {
  int var = 69;
  int *pVar = &var;
  int **ppVar =
      &pVar; // ** = pointer to an already existing pointer (pointer-to-pointer)

  Point *pointer = NULL; // define pointer struct to p
  pointer = malloc(sizeof(Point));
  pointer->p = 69;
  int *pP = &pointer->p;
  Point **ppointer = &pointer;

  printf("var\n");
  printf("var: %d\n", var);
  printf("var address: %p\n", (void *)&var);

  printf("\npVar\n");
  printf("pVar val: %p\n", (void *)pVar);
  printf("pVar address: %p\n", (void *)&pVar);
  printf("pVar dereference to var: %d\n", *pVar);

  printf("\nppVar\n");
  printf("ppVar val: %p\n", &ppVar);
  printf("ppVar dereference to pVar val: %p\n", *ppVar);
  printf("ppVar dereference to var: %d\n", **ppVar);

  printf("\npointer struct\n");
  printf("pointer struct address: %p\n", (void *)pointer);
  printf("pointer struct p val: %d\n", pointer->p);
  printf("pointer struct p address & pointer: %p\n", (void *)&pointer->p);

  printf("\npp\n");
  printf("pp address: %p\n", pP);
  printf("pp dereference to p: %d\n", *pP);

  printf("\nppointer struct\n");
  printf("ppointer struct address: %p\n", &ppointer);
  printf("ppointer dereference to pointer: %p\n", *ppointer);
  free(pointer);

  return 0;
}
