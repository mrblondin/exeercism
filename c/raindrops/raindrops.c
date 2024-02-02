#include "raindrops.h"
#include <assert.h>
#include <string.h>
#include <stdio.h>

static char VALUES[] = { 3, 5, 7 };
static const char *SOUNDS[] = { "Pling", "Plang", "Plong" };

char *convert(char result[], int drops){
  assert(result);

  for (size_t i = 0; i < (sizeof(VALUES) / sizeof(VALUES[0])); i++)
    if (!(drops % VALUES[i])) strcat(result, SOUNDS[i]);

  if (!*result) sprintf(result, "%i", drops);

  return result;
}
