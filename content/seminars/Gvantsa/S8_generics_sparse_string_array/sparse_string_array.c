#include "sparse_string_array.h"

/**
* Function: SSANew
* ----------------
* Constructs the sparsestringarray addressed by the first argument to
* be of the specified length, using the specified group size to decide
* how many groups should be used to back the implementation. You can
* assume that arrayLength is greater than groupSize, and for simplicity you
* can also assume that groupSize divides evenly into arrayLength.
*/
void SSANew(sparsestringarray *ssa, int arrayLength, int groupSize){
    ssa->groupSize = groupSize;
    ssa->arrayLength = arrayLength;
    ssa->numGroups = (arrayLength - 1) / groupSize + 1;
    ssa->groups = malloc(sizeof(group) * ssa->numGroups);

    for (int i = 0; i < ssa->numGroups; i++){
        ssa->groups[i].bitmap = malloc(ssa->groupSize * sizeof(bool));
        for (int j = 0; j < ssa->groupSize; j++)
            ssa->groups[i].bitmap[j] = false;
        VectorNew(&ssa->groups[i].strings, sizeof(char *), StringFree, 1);
    }
}


/**
* Function: SSADispose
* --------------------
* Disposes of all the resources embedded within the addressed
* sparsestringarray that have built up over the course of its
* lifetime.
*/
void SSADispose(sparsestringarray *ssa){
    for (int i = 0; i < ssa->numGroups; i++){
        free(ssa->groups[i].bitmap);
        VectorDispose(&ssa->groups[i].strings);
    }

    free(ssa->groups);
}

/**
* Function: SSAInsert
* -------------------
* Inserts the C string addressed by str into the sparsestringarray addressed
* by ssa at the specified index. If some nonempty string already resides
* at the specified index, then it is replaced with the new one. Note that
* SSAInsert makes a deep copy of the string address by str.
*/
bool SSAInsert(sparsestringarray *ssa, int index, const char *str){
    int groupIndex = index / ssa->groupSize;
    int bitmapIndex = index % ssa->groupSize;
    group* currentGroup = &ssa->groups[groupIndex];

    bool isInArray = currentGroup->bitmap[bitmapIndex];

    int vectorIndex = 0;
    for (int i = 0; i < bitmapIndex; i++){
        if (currentGroup->bitmap[i])
            vectorIndex++;
    }

    const char *copy = strdup(str);

    if (isInArray){
        VectorReplace(&currentGroup->strings, &copy, vectorIndex);
    }else{
        VectorInsert(&currentGroup->strings, &copy, vectorIndex);
        currentGroup->bitmap[bitmapIndex] = true;
    }
    return !isInArray;
}

/**
* Function: SSAMap
* ----------------
* Applies the specified mapping routine to every single index/string pair
* (along with the specified auxiliary data). Note that the mapping routine
* is called on behalf of all strings, both empty and nonempty.
*/
void SSAMap(sparsestringarray *ssa, SSAMapFunction mapfn, void *auxData){
    int groupSize = ssa->groupSize;
    for (int i = 0; i < ssa->numGroups; i++){
        if (i == ssa->numGroups - 1 && ssa->arrayLength % ssa->groupSize > 0)
            groupSize = ssa->arrayLength % ssa->groupSize;

        int vectorIndex = 0;
        for (int j = 0; j < groupSize; j++){
            const char* str = "";
            if (ssa->groups[i].bitmap[j]){
                str = *(char **)VectorNth(&ssa->groups[i].strings, vectorIndex);
                vectorIndex++;
            }
            mapfn(i * ssa->groupSize + j, str, auxData);
        }
    }

}