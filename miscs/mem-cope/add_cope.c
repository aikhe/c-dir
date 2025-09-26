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

  if (*head == NULL) {
    printf("%d\n", newCope->id);

    *head = newCope;
  } else {
    printf("%d\n", newCope->id);

    Copium *current = *head;
    while (current->next != NULL) {
      current = current->next;
    }

    current->next = newCope;
  }
}
