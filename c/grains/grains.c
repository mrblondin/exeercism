#include "grains.h"

#define SQUARE_MAX  64
#define SQUARE_MIN  1
#define ERROR       0

uint64_t square(uint8_t index){
  if (index < SQUARE_MIN || index > SQUARE_MAX)
    return ERROR;

  return (1ULL << (index - 1));
}

uint64_t total(void){
  uint64_t sum = 0;

  for (char i = 1; i <= SQUARE_MAX; i++){
    sum += square(i);
  }

  return sum;
}
