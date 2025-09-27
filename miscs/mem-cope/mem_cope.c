#include <stdio.h>

#include "add_cope.h"
#include "types.h"

int main() {
  Copium *cope = NULL;

  addCope(1, "Some yapping");

  printf("Yappings:\n");
  printf("ID: %d, Yaps: %s", cope->id, cope->yaps);

  return 0;
}
