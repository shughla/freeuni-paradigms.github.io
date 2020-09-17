#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void test(const char* actual, const char* expected);

// for loop with int i
void strcpy1(char dest[], const char source[]) {
	int i = 0;
	for (;source[i] != '\0'; i++) {
		dest[i] = source[i];
	}
	dest[i] = '\0';
}

// for loop with char* i
void strcpy2(char dest[], const char source[]) {
	for (const char* i = source; *i != '\0'; i++) {
		*dest++ = *i;
	}
	dest = '\0';
}


void strcpy3(char dest[], const char source[]) {
	while ((*dest++ = *source++) != '\0');
	// *dest = '\0'; // რატომ არ არის საჭირო?
}

void strcpy4(char dest[], const char source[]) {
 	while ((*dest++ = *source++)); // '\0' == 0
}

int main() {
	char* first = "strcpy1";
	// რა მოხდება, თუ ეწერება char* firstR?
	char firstR[10];
	strcpy1(firstR, first);
	test(firstR, first);
	char* second = "strcpy2";
	char secondR[10];
	strcpy2(secondR, second);
	test(secondR, second);
	char* third = "strcpy3";
	char thirdR[10];
	strcpy3(thirdR, third);
	test(thirdR, third);
	char* fourth = "strcpy4";
	char fourthR[10];
	strcpy4(fourthR, fourth);
	test(fourthR, fourth);
}

void test(const char* actual, const char* expected) {
	printf("%s: ", expected);
	if (strcmp(expected, actual) == 0) {
		printf("passes\n");
	} else {
		printf("fails, found %s\n", actual);
	}
}