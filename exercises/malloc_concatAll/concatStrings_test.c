#include "scheme.h"
#include <stdio.h>

int main() {
	char * string1 = "abc";
	char * string2 = "de";
	char * result = ConcatStrings(string1, string2);
	printf("string1: %s\n", result);
	printf("string2: %s\n", result);
	printf("result: %s\n", result);
	printf("addresses (can't be the same)\n")
	printf("1 - %u, 2- %u, r - %u\n", string1, string2, result);
}
