#include "nth_prime.h"
#include <math.h>
#include <string.h>

uint32_t nth(uint32_t n){
  if (n == 0) return 0;

  uint32_t primes[n];
  memset(primes, 0, n * sizeof(uint32_t));
  int count = 1; // prime numbers count, the first prime is 2
  primes[0] = 2; // setting the first prime to 2

  // starting iterate from 3 only odd numbers, saving only prime nums
  uint32_t num = 3;
  while (!primes[n - 1]){
    int is_prime = 1;

    // the trick is this - the divisor of the number can not be greater than 
    // the sqrt of number + 1 
    for (int i = 0; primes[i] < sqrt(num + 1); i++)
      if (num % primes[i] == 0) { is_prime = 0; break; }

    if (is_prime) primes[count++] = num;
    num += 2;
  }

  return primes[n - 1];
}
