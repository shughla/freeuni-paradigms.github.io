#include <stdlib.h>
typedef struct {
	int violet;
	char *dash[2];
	char superboy[4];
} superhero;

// ignore this funciton's body, just so it can compile
static superhero **pixar(superhero *syndrome) {
	superhero * ptr = malloc(sizeof(superhero*));
	ptr = syndrome;
	superhero ** ptr2 = malloc(sizeof(superhero**));
	ptr2 = &ptr;
	return ptr2;
}
static superhero *theincredibles(short *frozone, superhero elastigirl){ 
	frozone += elastigirl.superboy[*frozone];
	((superhero *)((superhero *) elastigirl.dash[0])->dash)->violet = 400;
	return *pixar(&elastigirl) +10;
}


int main() {
	superhero elastigirl;
	short frozone[2];
	theincredibles(frozone, elastigirl);
}
