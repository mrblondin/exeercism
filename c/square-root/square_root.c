#include "square_root.h"

// solution taken from https://en.wikipedia.org/wiki/Integer_square_root

int square_root(int number){
  if (number < 2)
    return number;

  int small_cand = square_root(number >> 2) << 1;
  int large_cand = small_cand + 1;

  if (large_cand * large_cand > number)
    return small_cand;
  else
    return large_cand;
}
