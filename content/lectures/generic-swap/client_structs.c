#include <assert.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#include "swap.h"

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

void Values() {
  printf("--- VALUES ---\n");
  Point a = NewPoint(1, 2);
  Point b = NewPoint(3, 4);
  printf("Before swap: (%d, %d) (%d, %d)\n", a.x, a.y, b.x, b.y);
  Swap(&a, &b, sizeof(Point));
  printf("After swap: (%d, %d) (%d, %d)\n", a.x, a.y, b.x, b.y);
}

void Pointers() {
  printf("--- POINTERS ---\n");
  Point *a = malloc(sizeof(Point));
  assert(a != NULL);
  a->x = 1;
  a->y = 2;
  Point *b = malloc(sizeof(Point));
  assert(b != NULL);
  b->x = 3;
  b->y = 4;
  printf("Before swap: (%d, %d) (%d, %d)\n", a->x, a->y, b->x, b->y);
  // Here we are swapping just pointers to the Point objects but not Point
  // object values themselves.
  Swap(&a, &b, sizeof(Point *));
  printf("After swap: (%d, %d) (%d, %d)\n", a->x, a->y, b->x, b->y);
  free(a);
  free(b);
}

int main(int argc, char **argv) {
  Values();
  Pointers();
  return 0;
}
