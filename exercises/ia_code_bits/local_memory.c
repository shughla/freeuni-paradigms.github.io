
#include <stdio.h>
void f1(int a) {
	int b = 15;
	printf("f1 a addr: %u\n", &a);
	printf("f1 b addr: %u\n", &b);
}

int* f2(int a) {
	printf("f2 a addr: %u\n", &a);
	printf("f1 b value from f2: %u\n", *(&a - 2));
	*(&a - 2) = 20;
}

void f3(int a) {
	int b;
	printf("f3 b value: %d\n", b);
	printf("f3 b addr: %u\n", &b);
}
int main() {
	f1(2);
	f2(2);
	f3(2);
	return 0;
}
