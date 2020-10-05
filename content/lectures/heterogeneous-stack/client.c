#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "stack.h"

int main(int argc, char **argv) {
  Stack s;
  StackInit(&s);
  for (int i = 0; i < 100; ++i) {
    StackPush(&s, &i, sizeof(int));
  }
  char *a[] = {"ABCDE", "FGH", "IJKLMNOPQRSTUWXYZ"};
  for (int i = 0; i < 3; ++i) {
    StackPush(&s, &a[i], sizeof(char *));
    StackPush(&s, a[i], strlen(a[i]) + 1);
  }
  for (int i = 0; i < 3; ++i) {
    char *x = StackPop(&s);
    printf("%s\n", x);
    free(x);
    char **y = StackPop(&s);
    printf("%s\n", *y);
    free(y);
  }
  for (int i = 0; i < 100; ++i) {
    int *top = StackPop(&s);
    printf("%d\n", *top);
    free(top);
  }
  StackDispose(&s);
  return 0;
}
