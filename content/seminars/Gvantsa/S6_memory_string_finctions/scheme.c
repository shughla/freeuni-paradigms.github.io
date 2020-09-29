#include "scheme.h"

typedef enum {
	Integer, String, List, Nil
} nodeType;

char *ConcatAll(nodeType *list) {
    nodeType current = *list;

    switch (current)
    {
    case Integer:
    case Nil:
        return strdup("");
    case String:
        return strdup((char *)(list + 1));
    }

    nodeType ** arr = (nodeType **)(list + 1);
    nodeType * first = arr[0]; // *(nodetype **)(list + 1)
    nodeType * second = arr[1]; //*(nodetype **)(list + 2)

    char * first_str = ConcatAll(first);
    char * second_str = ConcatAll(second);
    char * result = ConcatStrings(first_str, second_str);

    free(first_str);
    free(second_str);
    return result;
}
