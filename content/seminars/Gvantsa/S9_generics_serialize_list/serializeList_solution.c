#include "serializeList.h"

// list = (const void **) *(const void**)list;

// რატომ არ გვაქვს შექმნილი Node სტრუქტურა?
int * serializeListSolution(const void *list){
  int *serialization = malloc(sizeof(int));
  int serializationLength = sizeof(int);
  const void **curr = (const void **) list;
  int numNodes = 0;
  while (curr != NULL) {
    const char *str = (const char *)(curr + 1);
    serialization = realloc(serialization, serializationLength + strlen(str) + 1);
    strcpy((char *) serialization + serializationLength, str);
    serializationLength += strlen(str) + 1;
    // იმუშავებს თუ არა, რომ არ დავკასტოთ?
    curr = (const void **) *curr;
    numNodes++;
  }
  *serialization = numNodes;
  return serialization;
}
