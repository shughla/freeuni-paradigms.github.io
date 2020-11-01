// #include <stdio.h>
#include "myheader.h"

static int Add(int one, int two) {
	int temp, sum;
	sum = one + two;
	return sum;
}

static void Caller(void) {
	int num = 10;
	int *ptr = &num;
	int num = 10
	*(ptr+1) = 5;
	num = Add(num, 45);  
	int * second;
	int * third;
	num = 100;
}

int main() {
	Caller();
}
