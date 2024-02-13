#include "etl.h"
#include "stdlib.h"

static int cmpfunc(const void *a, const void *b) {
  return ( ((new_map*)a)->key - ((new_map*)b)->key );
}

int convert(const legacy_map *input, const size_t input_len, new_map **output){
  *output = calloc(MAX_LENGTH, sizeof(output));
  if (!*output) return ERROR;

  size_t output_index = 0;
  char to_lower_diff = 'a' - 'A';
  
  for (size_t index = 0; index < input_len; index++){
    char* v = (char *)&input[index].keys[0];
    while(*v)
      (*output)[output_index++] = 
        (new_map){(*v++ + to_lower_diff), input[index].value};
  }

  *output = realloc(*output, sizeof(output) * output_index);

  qsort(*output, output_index, sizeof(new_map), cmpfunc);

  return output_index;
}
