#include "scheme.h"

char *ConcatStrings(const char *first, const char *second) {
	char *result = malloc(strlen(first) + strlen(second) + 1);
	strcpy(result, first); 
	strcat(result, second);
	return result;
}

