#include <gerenic_sorted_set.h>

/*
* Function: SetNew
* Usage: SetNew(&stringSet, sizeof(char *), StringPtrCompare);
*
SetNew(&constellations, sizeof(pointT), DistanceCompare);
* ----------------
* SetNew allocates the requisite space needed to manage what
* will initially be an empty sorted set. More specifically, the
* routine allocates space to hold up to 'kInitialCapacity' (currently 4)
* client elements.
*/
static const int kInitialCapacity = 4;
void SetNew(sortedset *set, int elemSize, int (*cmpfn)(const void *, const void *)){
    assert(set != NULL);
    assert(elemSize > 0);
    assert(cmpfn != NULL);
    set->elemSize = elemSize;
    set->cmpfn = cmpfn;

    set->root = (int *)malloc(kInitialCapacity * (set->elemSize + 2 * sizeof(int)) + sizeof(int));
    assert(set->root != NULL);
    *set->root = -1;

    set->logLen = 0;
    set->allocLen = kInitialCapacity;
}

/*
* Function: SetSearch
* Usage: if (SetSearch(&staffSet, &lecturer) == NULL)
*
printf("musta been fired");
* -------------------
* SetSearch searches for the specified client element according
* the whatever comparison function was provided at the time the
* set was created. A pointer to the matching element is returned
* for successful searches, and NULL is returned to denote failure.
*/
void *SetSearch(sortedset *set, const void *elemPtr){
    int * node = FindNode(set, elemPtr);
    if (*node == -1)
        return NULL;
    return (char *)(set->root + 1) + *node * (set->elemSize + 2 * sizeof(int));
}
/*
* Function: SetAdd
* Usage: if (!SetAdd(&friendsSet, &name)) free(name);
* ----------------
* Adds the specified element to the set if not already present.
* present, the client element is not copied into the set. true
* is returned if and only if the element at address elemPtr
* was copied into the set.
*/
bool SetAdd(sortedset *set, const void *elemPtr){
    int * node = FindNode(set, elemPtr);
    if (*node != -1)
        return false;

    if (set->logLen == set->allocLen){
        set->allocLen *= 2;
        set->root = (int *)realloc(set->root, set->allocLen * (set->elemSize + 2 * sizeof(int)) + sizeof(int));
    }

    int * end = (char *)(set->root + 1) + set->logLen * (set->elemSize + 2 * sizeof(int));
    *node = set->logLen;
    set->logLen++;
    memcpy(end, elemPtr, set->elemSize);
    int* arr = (char *)end + set->elemSize;
    arr[0] = -1;
    arr[1] = -1;
    return true;
}

/**
* Function: FindNode
* Usage: ip = FindNode(set, elem);
*
if (*ip == -1) printf("ip points where this element belongs!");
* ------------------
* FindNode descends through the underlying binary search tree of the
* specified set and returns the address of the offset into raw storage
* where the specified element resides. If the specified element isn't
* in the set, FindNode returns the address of the –1 that would be updated
* to contain the index of the element being sought if it were the
* element to be inserted——that is, the address of the –1 that ended
* the search.
*/
static int *FindNode(sortedset *set, const void *elem)
{
    void * current;
    int * root = set->root;
 
    while(*root != -1){
        current = (char *)(set->root + 1) + *root * (set->elemSize + 2 * sizeof(int));
        int cmpResult = set->cmpfn(elem, current);
        if (cmpResult == 0)
            break;
        if (cmpResult < 0){
            root = (char *)current + set->elemSize;
        }else{
            root = (char *)current + set->elemSize + sizeof(int);
        }
    }
    return root;
}