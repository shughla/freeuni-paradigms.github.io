#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "rotate.h"

void WithinString() {
  printf("--- WITHIN STRING ---\n");
  char *s = strdup("ABCDEFGHIJKLMNO");
  printf("Before rotate: %s\n", s);
  Rotate(s, s + 3, s + strlen(s));
  printf("After rotate: %s\n", s);
  free(s);
}

void StringArray() {
  printf("--- STRING ARRAY ---\n");
  char *a[] = {strdup("ABC"), strdup("DEFGH"), strdup("XYZ")};
  printf("Before rotate:");
  for (int i = 0; i < 3; ++i) {
    printf(" %s", a[i]);
  }
  printf("\n");
  Rotate(a, a + 1, a + 3);
  printf("After rotate:");
  for (int i = 0; i < 3; ++i) {
    printf(" %s", a[i]);
  }
  printf("\n");
  for (int i = 0; i < 3; ++i) {
    free(a[i]);
  }
}

int main(int argc, char **argv) {
  WithinString();
  StringArray();
  return 0;
}
