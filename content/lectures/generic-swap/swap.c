#include "swap.h"

#include <string.h>

void Swap(void *a, void *b, int elem_size) {
  char tmp[elem_size];
  memcpy(tmp, a, elem_size);
  memcpy(a, b, elem_size);
  memcpy(b, tmp, elem_size);
}
