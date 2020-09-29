#include "scheme.h"

char *ConcatStrings(const char *first, const char *second) {
	size_t size = strlen(first) + strlen(second) + 1;
	char * result = malloc(size);
	strcpy(result, first);
	strcat(result, second);
	return result;
}


