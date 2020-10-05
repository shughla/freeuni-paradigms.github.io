#ifndef HETEROGENEOUS_STACK_STACK_H_
#define HETEROGENEOUS_STACK_STACK_H_

typedef struct {
  void *elems;
  int alloc_bytes;
  int last_elem_offset;
} Stack;

void StackInit(Stack *s);
void StackDispose(Stack *s);
void StackPush(Stack *s, void *elem, int elem_size);
void *StackPop(Stack *s);

#endif // HETEROGENEOUS_STACK_STACK_H_
