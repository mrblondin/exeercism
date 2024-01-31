#include "secret_handshake.h"
#include <stdlib.h>
#include <string.h>

#define REVERSE       1 << 4
#define ERROR         NULL
#define ACTIONS_NUM   4

static const char *actions[] = { "wink", "double blink", 
  "close your eyes", "jump" };

const char **commands(size_t number){
  if (number > 0x20)
    return ERROR;

  const char ** result = calloc(4, sizeof(char *));
  if (!result) return ERROR;

  int count = 0;
  char is_reversed = number & REVERSE;

  for (int i = 0; i < ACTIONS_NUM; i++){
    int index = is_reversed ? ACTIONS_NUM - i - 1 : i;

    if ((1 << index) & number) {
      result[count] = actions[index];
      count++;
    }
  }

  //result = realloc(result, count * sizeof(char *));

  return result;
}
