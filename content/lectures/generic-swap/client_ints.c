#include <stdio.h>

#include "swap.h"

int main(int argc, char **argv) {
  int a = 5;
  int b = 7;
  printf("Before swap: %d %d\n", a, b);
  Swap(&a, &b, sizeof(int));
  printf("After swap: %d %d\n", a, b);
  return 0;
}
