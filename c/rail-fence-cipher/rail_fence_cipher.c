#include "rail_fence_cipher.h"
#include <string.h>
#include <stdlib.h>
#include <assert.h>

#define ERROR 0

char *encode(char *text, size_t rails){
  assert(text && rails > 0);

  size_t text_length = strlen(text);
  char * encoded = malloc(sizeof(char) * (text_length + 1));
  if (!encoded) return ERROR;

  size_t index = 0;
  size_t division = rails - 1;
  char strs[rails][text_length];
  while(*text){
    // find to which row belongs the current character
    size_t row = (index / division) % 2 == 0 
                  ? index % division
                  : division - index % division;

    // the position of index in each string
    size_t cur_position = 
        index % division == 0 
                ? ((index % division) % 2 == 0 
                        ? index / (2 * division) 
                        : (index - division) / (2 * division))
                 : index / division; 

    strs[row][cur_position] = *text++;
    strs[row][cur_position+1] = '\0';
    
    index++;
  } 

  for (size_t i = 0; i < rails; i++){
    strcat(encoded, strs[i]);
  }

  encoded[text_length] = '\0';
  return encoded;
}

char *decode(char *ciphertext, size_t rails){
  assert(ciphertext && rails > 0);

  size_t text_length = strlen(ciphertext);
  char * decoded = malloc(sizeof(char) * (text_length + 1));
  if (!decoded) return ERROR;

  size_t start_of_row[rails];

  size_t division = rails - 1;

  // find starting position of each row and save it to start_of_row array
  start_of_row[0] = 0;
  for (size_t i = 0; i < rails - 1; i++){
    start_of_row[i + 1] = (text_length - i - 1) / 
      ((i % division) == 0 ? 2 * division : division) + 1 
      + (i > 0 ? start_of_row[i] : 0);
  }

  size_t index = 0;
  for (index = 0; index < text_length; index++){
    size_t row = (index / division) % 2 == 0 
                  ? index % division
                  : division - index % division;
    
    decoded[index] = ciphertext[start_of_row[row]];
    start_of_row[row]++;
  }

  return decoded;
}
