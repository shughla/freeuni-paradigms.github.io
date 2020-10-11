#include "serializeList.h"


int * serializeList(const void *list){

  int * result = (int *)malloc(sizeof(int));
  *result = 0;
  int length = sizeof(int);
  void ** current = list;

  while (current != NULL){
    char * str = (char *)(current + 1);
    int currentLength = strlen(str);
    result = realloc(result, length + currentLength + 1);
    char * dest = (char *)result + length;
    strcpy(dest, str);
    length += currentLength + 1;
    *result += 1;
    current = *current;
  }

  return result;
}