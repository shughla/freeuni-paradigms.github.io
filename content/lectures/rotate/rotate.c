#include "rotate.h"

#include <string.h>

void Rotate(void *front, void *middle, void *end) {
  int left_size = (char *)middle - (char *)front;
  int right_size = (char *)end - (char *)middle;
  char tmp[right_size];
  memcpy(tmp, middle, right_size);
  memmove((char *)front + right_size, front, left_size);
  memcpy(front, tmp, right_size);
}
