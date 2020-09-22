typedef enum {
	Integer, String, List, Nil
} nodeType;

static char *ConcatStrings(const char *first, const char *second) {
	char *result = malloc(strlen(first) + strlen(second) + 1);
	strcpy(result, first); 
	strcat(result, second);
	return result;
}

char *ConcatAll(nodeType *list) {
	switch (*list) {
		case Integer:
		case Nil: return strdup("");
		case String: return strdup((char *)(list + 1));
	}
	nodeType **lists = (nodeType **)(list + 1);
	char *front = ConcatAll(lists[0]);
	char *back = ConcatAll(lists[1]);
	char *result = ConcatStrings(front, back);
	free(front);
	free(back);
	return result;
}
