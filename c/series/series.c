#include "series.h"
#include <string.h>
#include <stdlib.h>


slices_t slices(char *input_text, unsigned int substring_length){
  slices_t slices = {0};
  size_t length = strlen(input_text);
  if (length < substring_length || !substring_length || !input_text) return slices;

  // 4, 2 => 3, 5,3 => 3
  unsigned int slices_count = length - substring_length + 1;

  slices.substring = calloc(slices_count, sizeof(char *)); 
  if (!slices.substring) return slices;

  for (size_t index = 0; index < slices_count; index++){
    slices.substring[index] = (char *)calloc(substring_length + 1, sizeof(char));
    if (!(slices.substring[index])) return slices;
    for (size_t jindex = 0; jindex < substring_length; jindex++){
      slices.substring[index][jindex] = input_text[index + jindex];
    }
  }

  slices.substring_count = slices_count;
  return slices;
} 
