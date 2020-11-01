#include <stdbool.h>
#include <stddef.h>
typedef struct {
	int kHeapSize;
	int kHeapStart;
} HeapData;

typedef struct list {
	int data;
	struct list *next;
} list;
HeapData data;
int kHeapSize = 1000000;


bool validPointer(struct list * l) {
	return l > data.kHeapStart && l < data.kHeapStart + kHeapSize;
}

bool checkLinkedList(void *byte) {
	list * ptr = (struct list*) byte;
	if (ptr->data != 1) 
		return false;
	if (validPointer(ptr->next) && ptr->next->data != 2)
		return false;
	return true;

}
/**
* Your function should not dereference any invalid pointers. 
*/
void findLinkedList(char * kHeapStart) {
	for (int i = 0; i < kHeapSize; i++) {
		checkLinkedList(kHeapStart + i);
	}
}


int main() {
	char * heap = malloc(kHeapSize);
	data.kHeapStart = heap;
	list * l1 = heap + 6000;
	l1->data = 1;

	list * l2 = heap + 8500;
	l2->data = 2;
	l1->next = l2;
	list * l3 = heap + 90000;	
	l3->next = NULL;
	
	findLinkedList(heap);
	
}
