#include "lsearch.h"

#include <stddef.h>

void *lsearch(void *key, void *base, int n, int elem_size,
              int (*cmp_fn)(void *, void *)) {
  for (int i = 0; i < n; ++i) {
    void *elem_ptr = (char *)base + i * elem_size;
    if (cmp_fn(key, elem_ptr) == 0) {
      return elem_ptr;
    }
  }
  return NULL;
}
