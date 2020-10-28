#include <stdio.h>

static int Add(int one, int two) {
	int temp, sum;
	printf("temp addr: %u\nsum addr: %u\n", &temp, &sum);
	printf("one addr: %u\ntwo addr: %u\n", &one, &two);
	sum = one + two;
	return sum;
}

static void Caller(void) {
	int num = 10;
	int *ptr = &num;
	*(ptr+1) = 5;
	printf("num addr %u\n", &num);
	num = Add(num, 45);  
	int * second;
	int * third;
	printf("second addr %u\n", &second);
	printf("second value%u\n", second);
	printf("third addr%u\n", third);
	printf("third value%u\n", *third);
	num = 100;
}

int main() {
	Caller();
}
