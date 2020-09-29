#define NodeSize(clientElem)  ((clientElem) + 2 * sizeof(int))

static const int kInitialCapacity = 4;

void SetNew(sortedset *set, int elemSize,
            int (*cmpfn)(const void *, const void *)){
	assert(elemSize > 0);
	assert(cmpfn != NULL);
	set->root = malloc(sizeof(int) + kInitialCapacity * NodeSize(elemSize));
	assert(set->root);
	*set->root = -1; // set it empty
	set->logicalSize = 0;   // still empty
	set->allocatedSize = kInitialCapacity;
	set->cmp = cmpfn;
	set->elemSize = elemSize;
}

/**
 * Function: FindNode
 * Usage: ip = FindNode(set, elem);
 *        if (*ip == -1) printf("ip points where this element belongs!");
 * ------------------
 * FindNode descends through the underlying binary search tree of the
 * specified set and returns the address of the offset into raw storage
 * where the specified element resides.  If the specified element isn't
 * in the set, FindNode returns the address of the –1 that would be updated
 * to contain the index of the element being sought if it were the
 * element to be inserted——that is, the address of the –1 that ended
 * the search. */
static int *FindNode(sortedset *set, const void *elem) {void *curr;
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

bool SetAdd(sortedset *set, const void *elemPtr) {
	int *child;void *dest;
	child = FindNode(set, elemPtr);
	if (*child != -1) return false;  // already there.. say we didn't add it.
	if (set->logicalSize == set->allocatedSize) Expand(set);
	*child = set->logicalSize++;
	dest = (char *) (set->root + 1) + (*child) * NodeSize(set->elemSize);
	memcpy(dest, elemPtr, set->elemSize);  // assume (quite reasonably) no overlap
	child = (int *)((char *) dest + set->elemSize);
	child[0] = -1;
	child[1] = -1;
	return true;
}

static void Expand(sortedset *set) {
	set->allocatedSize *= 2;  // use doubling strategy
	set->root = realloc(set->root,sizeof(int) + set->allocatedSize * NodeSize(set->elemSize));
	assert(set->root != NULL);
}

void *SetSearch(sortedset *set, const void *elemPtr) {
	int *node = FindNode(set, elemPtr);
	if (*node == -1) return NULL;
	return (char *) (set->root + 1) + *node * NodeSize(set->elemSize);
}