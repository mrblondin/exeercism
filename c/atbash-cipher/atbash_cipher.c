#include "atbash_cipher.h"
#include <assert.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

typedef enum {
  DECODE,
  ENCODE
} CODE_TYPE;

static void atbash_code(const char *input, char **output, CODE_TYPE side){
  int length = strlen(input);
  int i = 0; // code index
  int space_divider = 5;
  for (int index = 0; index < length; index++){
    char ch = input[index];
    if (!isalnum(ch))
      continue;

    // space ' ' workaround
    if (side == ENCODE && i && i % space_divider == 0) {
      (*output)[i++] = ' ';
      space_divider += 6;
    }  
    (*output)[i++] = isalpha(ch) ? 'z' + 'a' - tolower(ch) : ch;
  }
}

char *atbash_encode(const char *input){
  assert(input);
  int length = strlen(input);
  char * code = calloc(length * 1.2 + 1, sizeof(char)); // + 20% causes of spaces
  if (!code) return NULL;

  atbash_code(input, &code, ENCODE);
  code = realloc(code, (strlen(code) + 1) * sizeof(char));

  return code;
}

char *atbash_decode(const char *input){
  assert(input);
  int length = strlen(input);
  char * text = calloc(length + 1, sizeof(char));
  if (!text) return NULL;

  atbash_code(input, &text, DECODE);
  text = realloc(text, (strlen(text) + 1) * sizeof(char));

  return text;
}

