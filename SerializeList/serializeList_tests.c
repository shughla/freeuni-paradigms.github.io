#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdbool.h>
#include "serializeList.h"
#include "serializeList_solution.h"

#define ASSERT(expr) {							\
  if (!(expr)) {								\
    printf("%s:%d: Assertion failed: %s\n", __FILE__, __LINE__, #expr);	\
    return false;							\
  }									\
}

void Test(char* name, bool(*test_fn)()) {
  printf("++ RUNNING TEST: %s\n", name);
  if (test_fn()) {
    printf("-- TEST %s: SUCCEEDED\n", name);
  } else {
    printf("-- TEST %s: FAILED\n", name);
  }
  printf("\n");
}

void* makeLinkedList(char** stringArray, int length){
  void* res = malloc(sizeof(void*));
  void* curr = res;

  for( int i = 0; i < length; i++){
    //Pointer, String, Terminating
    void* newElem = malloc(sizeof(void*) + strlen(stringArray[i]) + 1);
    char* destination = ((char*)newElem) + sizeof(void*);
    char* source = stringArray[i];
    strcpy(destination, source);
    free(source);
    memcpy(curr, &newElem, sizeof(void*));
    curr = newElem;
    (*((void**)curr)) = NULL;
  }
  free(stringArray);
  return *((void**)res);
}

bool check(void* studentAnswer, void* realAnswer){
  if(studentAnswer == NULL)
    return false;
  if(*((int*)studentAnswer) != *((int*)realAnswer))
      return false;

  int quantity = *((int*)studentAnswer);

  void* first = (char*)studentAnswer + sizeof(int*);
  void* second = (char*)realAnswer + sizeof(int*);

  for(int i = 0; i < quantity; i++){
    if(strcmp((char*)first, (char*)second) != 0)
      return false;
    first = (char*)first + strlen(first) + 1;
    second = (char*)second + strlen(second) + 1;
  }

  return true;
}

bool test1(){
  char ** stringArray = malloc(3*sizeof(char*));
  stringArray[0] = strdup("yellow");
  stringArray[1] = strdup("blue");
  stringArray[2] = strdup("red");

  void* test = makeLinkedList(stringArray, 3);

  void* studentAnswer = serializeList(test);
  void* realAnswer = serializeListSolution(test);
  
  return check(studentAnswer, realAnswer);
}


bool test2(){
  char ** stringArray = malloc(3*sizeof(char*));
  stringArray[0] = strdup("");
  stringArray[1] = strdup("b");
  stringArray[2] = strdup("ab");

  void* test = makeLinkedList(stringArray, 3);

  void* studentAnswer = serializeList(test);
  void* realAnswer = serializeListSolution(test);
  
  return check(studentAnswer, realAnswer);
}

bool test3(){
  char ** stringArray = malloc(sizeof(char*));
  stringArray[0] = strdup("");
  
  void* test = makeLinkedList(stringArray, 1);

  void* studentAnswer = serializeList(test);
  void* realAnswer = serializeListSolution(test);
  
  return check(studentAnswer, realAnswer);
}

bool test4(){
  char ** stringArray = malloc(10 * sizeof(char*));
  for(int i = 0 ; i < 10; i++){
    stringArray[i] = strdup("a");
  }
  void* test = makeLinkedList(stringArray, 10);

  void* studentAnswer = serializeList(test);
  void* realAnswer = serializeListSolution(test);
  
  return check(studentAnswer, realAnswer);
}

bool test5(){
  void* test = makeLinkedList(NULL, 0);

  void* studentAnswer = serializeList(test);
  void* realAnswer = serializeListSolution(test);
  
  return check(studentAnswer, realAnswer);
}


bool test6(){
  char ** stringArray = malloc(sizeof(char*));
  stringArray[0] = strdup("abcdefg");
  
  void* test = makeLinkedList(stringArray, 1);

  void* studentAnswer = serializeList(test);
  void* realAnswer = serializeListSolution(test);
  
  return check(studentAnswer, realAnswer);
}

int main(){
  Test("test1", test1);
  Test("test2", test1);
  Test("test3", test1);
  Test("test4", test1);
  Test("test5", test1);
  Test("test6", test1);
  return 0;
}
