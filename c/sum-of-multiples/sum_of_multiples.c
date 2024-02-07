#include "sum_of_multiples.h"
#include <assert.h>

unsigned int sum(const unsigned int *factors, const size_t number_of_factors,
                 const unsigned int limit){
  assert(limit);
  unsigned int sum = 0;
  
  for (size_t index = 0; index < number_of_factors; index++){
    if (factors[index] == 0) continue;
    for (size_t j = 1; j < (limit - 1) / factors[index] + 1; j++){
      int dup = 0;
      for (size_t i = 0; i < index; i++){
        // skipping
        if (j * factors[index] % factors[i] == 0){
          dup = 1;
          break;
        }
      }
      if (dup) continue;
      sum += factors[index] * j;
    }
  }

  return sum;
}
