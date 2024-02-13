#include "diamond.h"
#include <assert.h>
#include <stdlib.h>
#include <string.h>

char **make_diamond(const char letter){
  assert(letter);

  int side_size = (letter - 'A') * 2 + 1;
  char ** diamond = calloc(side_size, sizeof(char *));
  if (!diamond) return NULL;

  for (int i = 0; i < side_size; i++){
    diamond[i] = calloc(side_size + 1, sizeof(char));
    if (!diamond) return NULL;
    memset(diamond[i], ' ', side_size);
    int mid = side_size / 2;
    int x = i < mid ? i : 2 * mid - i; // coordinate of char relative to center
    diamond[i][mid - x] = diamond[i][mid + x] = 'A' + x;
  }

  return diamond;
}

void free_diamond(char **diamond){
  int size = strlen(diamond[0]);
  for (int i = 0; i < size; i++)
    free(diamond[i]);

  free(diamond);
}
