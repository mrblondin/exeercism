#include "prime_factors.h"

size_t find_factors(uint64_t n, uint64_t factors[static MAXFACTORS]){
  int count = 0;
  for (uint64_t dividor = 2; n > 1; dividor++){
    while (!(n % dividor)){
      factors[count++] = dividor;
      n /= dividor;
    }
  }
  return count;
}
