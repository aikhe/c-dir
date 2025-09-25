#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "types.h"

void addCope(Copium **head, int id, char *yaps) {
  Copium *newCope = (Copium *)malloc(sizeof(Copium));

  newCope->id = id;
  newCope->yaps = malloc(strlen(yaps) + 1);
  strcpy(newCope->yaps, yaps);
  newCope->next = NULL;

  // traverse node so that sequence is right so
  // ex. 1, 2, 3 instead of 3, 2, 1
  Copium **indirect =
      head; // pointer to a ppointer to handle both empty/non-empty (t/f)
  printf("indirect pointer: %p\n",
         (void *)*indirect);         // %p expect a void pointer
  while (*indirect != NULL) {        // checks if indirect has value
    indirect = &((*indirect)->next); // points indirect to the next node
    printf("next node\n");
  }

  *indirect = newCope; // now inserts new cope if node before has value
}
