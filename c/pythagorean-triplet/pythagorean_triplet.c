#include "pythagorean_triplet.h"
#include <stdint.h>
#include <stdlib.h>

#define ERROR 0

triplets_t * triplets_with_sum(uint16_t sum){
  if (!sum) return ERROR;

  uint16_t a, b, c;
  uint16_t count = 0;

  triplets_t * triplets = malloc(sizeof(*triplets));

  for (a = 1; a < (sum / 3); a++) {
    b = a + 1;
    c = sum - b - a; 
    while (b < c){
      if (a * a + b * b == c * c){
        triplet_t triplet = {a, b, c}; 
        count++;
        triplets = realloc(triplets, sizeof(*triplets) + count*sizeof(triplet_t));
        triplets->triplets[count - 1] = triplet;
      }

      b++;
      c = sum - b - a; 
    }
  }
  triplets->count = count;
  return triplets;
}

void free_triplets(triplets_t * triplets){
  if (!triplets) return;

  free(triplets);
}
