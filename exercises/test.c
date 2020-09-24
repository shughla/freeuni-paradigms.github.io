#include <stdio.h>
void f1(int a) {
	int b = 15;
	printf("f1 a addr: %u\n", &a);
}

void f2(int a) {
	printf("f2 a addr: %u\n", &a);
	printf("f1 b value: %u\n", *(&a + 4);
}

main() {
	f1(2);
	f2(2);
}
