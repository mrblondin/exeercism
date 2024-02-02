#include "two_fer.h"
#include <assert.h>
#include <stdio.h>


void two_fer(char *buffer, const char *name){
  assert(buffer);

  sprintf(buffer, "One for %s, one for me.", name ? name : "you");
}
