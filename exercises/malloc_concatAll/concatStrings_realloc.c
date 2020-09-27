#include "scheme.h"

char *ConcatStrings(const char *first, const char *second) {
	char *result = realloc((void*) first, strlen(first) + strlen(second) + 1);
//	const char * result = first;
	//strcpy(result, first); 
	strcat(result, second);
	return result;
}

