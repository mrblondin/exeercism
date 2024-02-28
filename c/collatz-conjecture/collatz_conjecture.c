#include "collatz_conjecture.h"

int steps(int start){
  if (start < 1) return ERROR_VALUE;
  int count = 0;

  while (start != 1){
    if (start % 2) start = start * 3 + 1;
    else start /= 2;
    count++;
  }
  return count;
}
