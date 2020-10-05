#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int elemSize;
    int (*cmpfn)(const void *, const void *);
    int * root;
    int logLen;
    int allocLen;
} sortedset;

void SetNew(sortedset *set, int elemSize, int (*cmpfn)(const void *, const void *));
bool SetAdd(sortedset *set, const void *elemPtr);
void *SetSearch(sortedset *set, const void *elemPtr);