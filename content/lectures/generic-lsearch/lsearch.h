#ifndef LSEARCH_H_
#define LSEARCH_H_

void *lsearch(void *key, void *base, int n, int elem_size,
              int (*cmp_fn)(void *, void *));

#endif // LSEARCH_H_
