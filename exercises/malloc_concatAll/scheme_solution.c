#include "scheme.h"

char *ConcatAll(nodeType *list) {
	switch (*list) {
		case Integer:
		case Nil: return strdup("");
		case String: return strdup((char *)(list + 1));
	}
	nodeType **lists = (nodeType **)(list + 1);
	char *front = ConcatAll(lists[0]);
	char *back = ConcatAll(lists[1]);
	/**
	//	last three lines are equivalent to:
	char* front = ConcatAll(list + 1);
	char* back = ConcatAll(list + 2);	
	**/
	char *result = ConcatStrings(front, back);
	free(front);
	free(back);
	return result;
}
