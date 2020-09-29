#include "sparsestringarray.h"

static void StringFree(void *elem) {
  free(*(char **) elem);
}

void SSANew(sparsestringarray *ssa, int arrayLength, int groupSize) {
  ssa->arrayLength = arrayLength;
  ssa->groupSize = groupSize;
  ssa->numGroups = (arrayLength - 1) / groupSize + 1;
  ssa->groups = malloc(ssa->numGroups * sizeof(group));
	
  for (int i = 0; i < ssa->numGroups; i++) {
    ssa->groups[i].bitmap = malloc(groupSize * sizeof(bool));
    bzero(ssa->groups[i].bitmap, groupSize * sizeof(bool));
    VectorNew(&ssa->groups[i].strings, sizeof(char *), StringFree, 1);
  }
}

void SSADispose(sparsestringarray *ssa) {
  for (int i = 0; i < ssa->numGroups; i++) {
    free(ssa->groups[i].bitmap);
    VectorDispose(&ssa->groups[i].strings);
  }
  
  free(ssa->groups);
}

bool SSAInsert(sparsestringarray *ssa, int index, const char *str) {
  int grp = index / ssa->groupSize;
  int indexWithinBitmap = index % ssa->groupSize;
  int indexWithinVector = 0;
  for (int i = 0; i < indexWithinBitmap; i++) {
    if (ssa->groups[grp].bitmap[i])
      indexWithinVector++;
  }

  const char *copy = strdup(str);
  bool previouslyInserted = ssa->groups[grp].bitmap[indexWithinBitmap];
  if (previouslyInserted)
    VectorReplace(&ssa->groups[grp].strings, &copy, indexWithinVector);
  else
    VectorInsert(&ssa->groups[grp].strings, &copy, indexWithinVector);
  ssa->groups[grp].bitmap[indexWithinBitmap] = true;

  return !previouslyInserted;
}

void SSAMap(sparsestringarray *ssa, SSAMapFunction mapfn, void *auxData) {
  int index = 0;
  for (int i = 0; i < ssa->numGroups; i++) {
    group *grp = &ssa->groups[i];
    int groupSize = ssa->groupSize;
    if (i == ssa->numGroups - 1 && ssa->arrayLength % ssa->groupSize > 0)
      groupSize = ssa->arrayLength % ssa->groupSize;
      
    int indexOfNonEmptyString = 0;
    for (int j = 0; j < groupSize; j++) {
      const char *str = "";
      if (grp->bitmap[j]) {
        str = *(char **) VectorNth(&grp->strings, indexOfNonEmptyString);
        indexOfNonEmptyString++;
      }
      mapfn(index, str, auxData);
      index++;
    }
  }
}
