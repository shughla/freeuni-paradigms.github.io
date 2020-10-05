#include <stddef.h>
#include <stdio.h>
#include <string.h>

#include "lsearch.h"

int StrCmp(void *a, void *b) {
  char *x = *(char **)a;
  char *y = *(char **)b;
  return strcmp(x, y);
}

int main(int argc, char **argv) {
  char *a[] = {"Foo", "Bar", "Dev", "Null"};
  char *key = strdup("Bar");
  void *found = lsearch(&key, a, 4, sizeof(char *), StrCmp);
  if (found == NULL) {
    printf("%s not found\n", key);
  } else {
    printf("%s found at index: %ld\n", key, (char **)found - a);
  }
  free(key);
  return 0;
}
