#include "leap.h"
#include "assert.h"

bool leap_year(int year){
  assert(year);

  return !(year % 400) || (year % 100 && !(year % 4));
}
