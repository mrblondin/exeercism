#include "matching_brackets.h"
#include <string.h>
#include <assert.h>
#include <stdlib.h>

#define OPENING "({["
#define CLOSING ")}]"
#define ASCII_MAX_DISTANCE_BETWEEN_BRACKET 2

bool is_paired(const char *input) {
  assert(input);

  char buf[strlen(input)];
  int count = 0;
  
  while(*input){
    char ch = *input++;

    if (strchr(OPENING, ch)){
      buf[count] = ch;
      count++;
    }
    else if (strchr(CLOSING, ch)){
      if (!count)
        return false;

      int ascii_distance = abs(ch - buf[count - 1]);
      if (ascii_distance <= 2){
        buf[count - 1] = '\0';
        count--;
      } else
        return false;
    }
  }

  return (count == 0);
}
