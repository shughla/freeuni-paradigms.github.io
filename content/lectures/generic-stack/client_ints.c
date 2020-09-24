#include "stack.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void StrFree(void *ptr) { free(*(char **)ptr); }

void Process(int data) { printf("-- Processed: %d\n", data); }

int main(int argc, char **argv) {
  Stack s;
  StackInit(&s, sizeof(int), NULL);
  for (int i = 0; i < 10; ++i) {
    StackPush(&s, &i);
  }
  for (int i = 0; i < 5; ++i) {
    int top;
    StackPop(&s, &top);
    Process(top);
  }
  StackDispose(&s);
  return 0;
}
