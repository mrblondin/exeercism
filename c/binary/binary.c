#include "binary.h"
#include <string.h>

int convert(const char *input){
  int value = 0;
  int factor = strlen(input) - 1;

  while(*input){
    char bit = (char)*input++;

    //convert to num from ASCII code
    bit = bit - '0';

    if (bit != 0 && bit != 1)
      return INVALID;

    if (bit) value += 1 << factor;
    factor--;
  }

  return value;
}
