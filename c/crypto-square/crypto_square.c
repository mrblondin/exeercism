#include "crypto_square.h"
#include <assert.h>
#include <ctype.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

static void normalize(const char *input, char **output){
  int i = 0;
  while (*input){
    if (isalnum(*input))
      *output[i++] = tolower(*input);
    input++;
  }
}

char *ciphertext(const char *input){
  assert(input);
  char * n_input = calloc(strlen(input), sizeof(char));
  normalize(input, &n_input);
  int length = strlen(n_input);
  int cols = pow(length, 0.5) + 1;
  int rows = cols * (cols - 1) <= length ? cols - 1 : cols;

  char arr[rows][cols];
  char * text = n_input;

  for (int row; row < rows; row++){
    for (int col; col < cols; col++){
      arr[row][col] = *n_input;
    }
  }

  return "";
}
