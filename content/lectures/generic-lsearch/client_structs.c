#include <stddef.h>
#include <stdio.h>
#include <string.h>

#include "lsearch.h"

typedef struct {
  int x;
  int y;
} Point;

Point NewPoint(int x, int y) {
  Point p;
  p.x = x;
  p.y = y;
  return p;
}

int PointCmp(void *a, void *b) {
  Point *p = a;
  Point *q = b;
  if (p->x != q->x) {
    return p->x - q->x;
  } else {
    return p->y - q->y;
  }
}

int main(int argc, char **argv) {
  Point a[] = {NewPoint(1, 2), NewPoint(0, 0), NewPoint(1, 3), NewPoint(5, 7)};
  Point key = NewPoint(10, 7);
  void *found = lsearch(&key, a, 4, sizeof(Point), PointCmp);
  if (found == NULL) {
    printf("(%d, %d) not found\n", key.x, key.y);
  } else {
    printf("(%d, %d) found at index: %ld\n", key.x, key.y, (Point *)found - a);
  }
  return 0;
}
