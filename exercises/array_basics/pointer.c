#include <stdio.h>
int main() {
	int* ptr;
	int i = 4;
	ptr = &i;
//	int arr[6] = {1, 2, 3, 4, 5, 6};
	ptr[100] = 3;
	printf("%d\n", ptr[4]);
}
