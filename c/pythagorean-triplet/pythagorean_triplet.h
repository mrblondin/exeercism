#ifndef PYTHAGOREAN_TRIPLET_H
#define PYTHAGOREAN_TRIPLET_H
#include <stdint.h>
#include <stdbool.h>

typedef struct{
  uint16_t a;
  uint16_t b;
  uint16_t c;
} triplet_t;

typedef struct {
  uint16_t count;
  triplet_t triplets[];
} triplets_t;

/**
 * Calculation of triplets, that correspond to the expression
 * a+b+c=sum, a^2+b^2=c^2, a < b < c
 * @param (uint16_t) sum
 * returns (triplets_t) pointer to triplet
 */
triplets_t * triplets_with_sum(uint16_t sum);
/**
 * Release triplets from memory
 * @param (triplets_t) triplets - pointer to triplet
 * returns (void)
 */
void free_triplets(triplets_t * triplets);

#endif
