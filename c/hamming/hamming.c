#include "hamming.h"
#include <stdio.h>
#include <string.h>

#define ERROR -1

int compute(const char *lhs, const char *rhs){
  int diff = 0;

  while (*lhs && *rhs){
    if (*lhs++ != *rhs++)
      diff++;
  }

  if (*lhs != *rhs)
    return ERROR;

  return diff;
}
