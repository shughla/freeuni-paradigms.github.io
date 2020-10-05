#include <assert.h>
#include <stdio.h>

#include "rotate.h"

void WithinShort() {
  printf("--- WITHIN SHORT ---\n");
  short s = (5 << 8) + 7;
  printf("Before rotate: %d\n", s);
  Rotate(&s, (char *)&s + 1, &s + 1);
  assert(s == ((7 << 8) + 5));
  printf("After rotate: %d\n", s);
}

void IntArray() {
  printf("--- INT ARRAY ---");
  int a[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  printf("Before rotate:");
  for (int i = 0; i < 10; ++i) {
    printf(" %d", a[i]);
  }
  printf("\n");
  Rotate(a, a + 6, a + 10);
  printf("After rotate:");
  for (int i = 0; i < 10; ++i) {
    printf(" %d", a[i]);
  }
  printf("\n");
}

int main(int argc, char **argv) {
  WithinShort();
  IntArray();
  return 0;
}
