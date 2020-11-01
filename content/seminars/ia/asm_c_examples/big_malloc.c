#include <stdlib.h>
#include <unistd.h>
int main() {
	void * largeheap = malloc(1073741824);
	// read user input 
	sleep(5);
	free(largeheap);
}
