#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "types.h"

void addCope(Copium **head, int id, char *yaps) {
  Copium *newCope = (Copium *)malloc(sizeof(Copium));

  newCope->id = id;
  newCope->yaps = malloc(sizeof(yaps) + 1);
  strcpy(newCope->yaps, yaps);
}
