#include "stack.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void StrFree(void *ptr) { free(*(char **)ptr); }

void Process(char *data) { printf("-- Processed: %s\n", data); }

int main(int argc, char **argv) {
  char *friends[] = {"Ana", "DAto", "Giorgi"};
  Stack s;
  StackInit(&s, sizeof(char *), StrFree);
  for (int i = 0; i < 3; ++i) {
    char *clone = strdup(friends[i]);
    StackPush(&s, &clone);
  }
  char *top;
  StackPop(&s, &top);
  Process(top);
  free(top);
  StackDispose(&s);
  return 0;
}

/* void ints() { */
/*   Stack s; */
/*   StackInit(&s, sizeof(int), NULL); */
/*   for (int i = 0; i < 10; ++i) { */
/*     StackPush(&s, &i); */
/*   } */
/*   int top; */
/*   StackPop(&s, &top); */
/*   Process(top); */
/*   StackDispose(&s); */
/* } */
