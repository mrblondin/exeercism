#include "sieve.h"
#include <stdint.h>
#include <string.h>
#include <stdlib.h>

uint32_t sieve(uint32_t limit, uint32_t *primes, size_t max_primes){
  size_t primeCount = 0;

  uint32_t arr[limit + 1];
  
  memset(arr, 0, sizeof(arr));

  // apply sieve of Eratosthenes algorithm, instead of mark assign 0
  for (uint32_t i = 2; i <= limit; i++){
    if (!arr[i]){
      primes[primeCount++] = i;
      if (primeCount >= max_primes) 
        break;
      for (uint32_t j = i * i; j <= limit; j+=i){
        arr[j] = 1;
      }
    }
  }

  return (uint32_t)primeCount;
}
