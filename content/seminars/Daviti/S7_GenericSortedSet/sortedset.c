/*
typedef struct {
	int* root;
	int logLen;
	int alocLen;
	int (*cmp)(const void* a,const void* b);
	int elemSize;
} sortedset;
*/

int kInitialCapacity = 4;

int NodeSize(elemSize){
    return elemSize + 2*sizeof(int);
}


void SetNew(sortedset *set, int elemSize, int (*cmpfn)(const void *, const void *))
{
    assert(set != null);
    assert(elemSize > 0);
    assert(cmpfn != null);
    
    set->root = malloc( kInitialCapacity*NodeSize(elemSize) + sizeof(int));
    *set->root = -1;
    set->logLen = 0;
    set->alocLen = kInitialCapacity;
    set->cmp = cmpfn;
    set->elemSize = elemSize;
}


int* findNode(sortedset *set, const void *elemPtr){
    int* root = set->root;
    void* curNode ;

    while(*root != -1 ){
        curNode = (char*)(set->root + 1) + (*root)*(NodeSize(elemSize))
        int comp = set->cmp(elemPtr, curNode))
        if(comp == 0)
            break;

        root = (int*)((char*)curNode + elemSize)
        
        if (comp > 0)
            root++;
    }

    return root;
}


void Expand(sortedset *set){
    set->alocLen = 2*set->alocLen;
    set->root = realloc(set->root,set->alocLen*NodeSize(elemSize) + sizeof(int) );
}


bool SetAdd(sortedset *set, const void *elemPtr){
    int* pos = findNode(set, elemPtr);
    if(*pos != -1)
        return false;
    if(set->logLen >= set->alocLen) Expand(set);
    newNode = (char*)(set->root + 1) + (set->logLen)*(NodeSize(elemSize))
    set->logLen;
    memcpy(newNode, elemPtr, elemSize);
    int* child = (int*)((char*)newNode + elemSize)
    *child = -1;
    *(child + 1) = -1;
    return true;
}
