#include <stddef.h>
#include <stdio.h>

#include "lsearch.h"

int IntCmp(void *a, void *b) {
  int x = *(int *)a;
  int y = *(int *)b;
  return x - y;
}

int main(int argc, char **argv) {
  int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int key = 3;
  void *found = lsearch(&key, a, 10, sizeof(int), IntCmp);
  if (found == NULL) {
    printf("%d not found\n", key);
  } else {
    printf("%d found at index: %ld\n", key, (int *)found - a);
  }
  return 0;
}
