#ifndef BINARY_SEARCH_H
#define BINARY_SEARCH_H

#include <stddef.h>

#define ERROR       0

/**
 * Binary search for the value in array
 *
 * @param {int} value to look for
 * @param {const int *} pointer to array in which to look for value
 * @param {size_t} length of array
 * @returns {const int *} binary_search, the pointer to value in array
 */
const int *binary_search(int value, const int *arr, size_t length);

#endif
