#include <stdio.h>

#include "add_cope.h"
#include "types.h"

int main() {
  Copium *cope = NULL;

  addCope(&cope, 1, "Some yapping");
  addCope(&cope, 2, "Insane yap");
  addCope(&cope, 3, "Giga yapfest");

  printf("Yappings:\n");
  Copium *current = cope;
  while (current) {
    printf("ID: %d, Yaps: %s\n", current->id, current->yaps);
    current = current->next;
  }

  return 0;
}
