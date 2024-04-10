#include "eliuds_eggs.h"

int egg_count(int code){
  int result = 0;  

  while (code){
    result += code & 1;
    code >>= 1;
  }

  return result;
}
