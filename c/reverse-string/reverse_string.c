#include "reverse_string.h"
#include <stdlib.h>

#define ERROR 0

char *reverse(const char *value){
  if (!value) return ERROR;

  int i = 0;
  // getting length of the word
  for (i = 0; value[i] != '\0'; ++i);

  char *str = malloc((i+1)*sizeof(char));
  if (!str) return ERROR;

  int len = i;
  str[len] = '\0';

  for (i = 0; value[i] != '\0'; i++){
    str[len - 1 - i] = value[i];
  }

  return str;
}
