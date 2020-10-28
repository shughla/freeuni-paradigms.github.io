#include <stdio.h>
#include <stdlib.h>

static void Banana(short* scores,  int n) {   
	scores[n] = 10;
	scores = (short *) malloc(100);
}

static void Banana2(short** scores, int n) {
	*scores = (short *) malloc(100);
}

int main() {
	short scores[4];
	//scores = (short *) malloc(100);
	Banana(scores, 3);
	short * scores_ptr = scores;
	printf("%d\n", scores_ptr[3]);
	Banana2(&scores_ptr, 3);
	printf("%d\n", scores[3]);
	printf("%d\n", scores_ptr[3]);
	int scores2[4];
	//scores2 = (int *) malloc(100);
}
