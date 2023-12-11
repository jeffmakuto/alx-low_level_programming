#ifndef SEARCH_ALGOS_H
#define SEARCH_ALGOS_H

/* Header files */
#include <stdio.h>
#include <stdlib.h>

/* Prototype functions */
int linear_search(int *array, size_t size, int value);
int binary_search(int *array, size_t size, int value);
int recursive_search(int *array, size_t size, int value);

#endif /* SEARCH_ALGOS_H */
