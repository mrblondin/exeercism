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
      (*output)[i++] = tolower(*input);
    input++;
  }
}

char *ciphertext(const char *input){
  assert(input);

  // calloc and 0 length workaround
  int ilength = strlen(input);
  char * n_input = calloc(ilength ? ilength : 1, sizeof(char));
  if (!n_input) return NULL;
  if (ilength == 0) return n_input;

  normalize(input, &n_input);
  int length = strlen(n_input);
  
  // determine amount of rows and cols
  int cols = pow(length, 0.5);
  cols = cols * cols == length ? cols : cols + 1;
  int rows = cols * (cols - 1) >= length ? cols - 1 : cols;

  char * output = calloc((cols + 1) * rows, sizeof(char));
  if (!output) return NULL;

  // filling it the result string
  int i = 0;
  for (int col = 0; col < cols; col++){
    for (int row = col; row < col + cols*rows; row += cols){
      output[i++] = n_input[row] ? n_input[row] : ' ';
    }
    if (col != cols - 1) output[i++] = ' ';
  }

  free(n_input);

  return output;
}
