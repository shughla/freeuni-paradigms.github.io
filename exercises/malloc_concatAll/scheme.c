#include "scheme.h"

char *ConcatAll(nodeType *list) {
	switch (*list) {
		case Integer:
		case Nil: return strdup("");
		case String: return strdup((char*) (list + 1));
	}
	char *first = ConcatAll(list + 1);
	char *second = ConcatAll(list + 2);
	char *result = ConcatStrings(first, second);
	free(first);
	free(second);
	return result;
}

	// შემდეგი ელემენტი არის list + 1-ზე
	// switch: 
	// int - 0 return "" 
	// String: return string
	// case Nil: return ""

	// List return concatAll(list)
	// ამ შემთხვევაში აქ წერია ორი მიმთითებელი
	//  concatAll(1, 2)
	// free 1, 2

}
