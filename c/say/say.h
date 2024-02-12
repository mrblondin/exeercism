#ifndef SAY_H
#define SAY_H

#include <stdint.h>

#define ERROR  -1
#define SUCCESS 0

typedef struct {
  int64_t number;
  char * word;
} num_to_say_t;

int say(int64_t input, char **ans);

#endif
