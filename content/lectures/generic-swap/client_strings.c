#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "swap.h"

void Correct() {
  char *a = strdup("ABCDEFGHIJKLMNOPQRS");
  char *b = strdup("XYZ");
  printf("Before swap: %s %s\n", a, b);
  Swap(&a, &b, sizeof(char *));
  printf("After swap: %s %s\n", a, b);
}

void Wrong() {
  char *a = strdup("ABCDEFGHIJKLMNOPQRS");
  char *b = strdup("XYZ");
  printf("Before swap: %s %s\n", a, b);
  // Passing values without taking reference is wrong
  Swap(a, b, sizeof(char *));
  printf("After swap: %s %s\n", a, b);
  free(a);
  free(b);
}

int main(int argc, char **argv) {
  Correct();
  Wrong();
  return 0;
}
