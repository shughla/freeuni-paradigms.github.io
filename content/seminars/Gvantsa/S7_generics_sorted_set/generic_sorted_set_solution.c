#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int *root;
    // points to the offset index of the root.
    int logicalSize;
    // number of active client elements currently stored.
    int allocatedSize; // number of elements needed to saturate memory.
    int (*cmp)(const void *, const void *);
    int elemSize;
    // client element size.
} sortedset;

/**
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
#define NodeSize(clientElem) ((clientElem) + 2 * sizeof(int))
static const int kInitialCapacity = 4;
void SetNew(sortedset *set, int elemSize,
int (*cmpfn)(const void *, const void *))
{
    assert(elemSize > 0);
    assert(cmpfn != NULL);
    set->root = malloc(sizeof(int) + kInitialCapacity * NodeSize(elemSize));
    assert(set->root);
    *set->root = -1;
    // set it empty
    set->logicalSize = 0;
    // still empty
    set->allocatedSize = kInitialCapacity;
    set->cmp = cmpfn;
    set->elemSize = elemSize;
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
    void *curr;
    int comp, *root = set->root;
    while (*root != -1) { // while not addressing a leaf
        curr = (char *) (set->root + 1) + *root * NodeSize(set->elemSize);
        comp = set->cmp(elem, curr); // compare client element to value at curr
        if (comp == 0) break;
        root = (int *)((char *) curr + set->elemSize);
        if (comp > 0) root++;
    }
    return root;
}

/**
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
void *SetSearch(sortedset *set, const void *elemPtr)
{
    int *node = FindNode(set, elemPtr);
    if (*node == -1) return NULL;
    return (char *) (set->root + 1) + *node * NodeSize(set->elemSize);
}

/**
* Function: SetAdd
* Usage: if (!SetAdd(&friendsSet, &name)) free(name);
* ----------------
* Adds the specified element to the set if not already present.
* present, the client element is not copied into the set. true
* is returned if and only if the element at address elemPtr
* was copied into the set.
*/
bool SetAdd(sortedset *set, const void *elemPtr){
    int *child;
    void *dest;
    child = FindNode(set, elemPtr);
    if (*child != -1) return false;
    // already there.. say we didn't add it.

    if (set->logicalSize == set->allocatedSize) Expand(set);

    *child = set->logicalSize++;
    dest = (char *) (set->root + 1) + (*child) * NodeSize(set->elemSize);
    memcpy(dest, elemPtr, set->elemSize); // assume (quite reasonably) no overlap
    child = (int *)((char *) dest + set->elemSize);
    child[0] = -1;
    child[1] = -1;
    return true;
}

static void Expand(sortedset *set)
{
    set->allocatedSize *= 2; // use doubling strategy
    set->root = realloc(set->root,
    sizeof(int) + set->allocatedSize * NodeSize(set->elemSize));
    assert(set->root != NULL);
}