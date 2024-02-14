#include "run_length_encoding.h"
#include <assert.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define ENOUGH 100000

static bool is_digit(char c){
  if (c >= 48 && c <= 57)
    return true;
  return false;
}

char *encode(const char *text){
  assert(text);
  //allocate max size
  size_t length = strlen(text);
  char * code = calloc(length + 1, sizeof(char));
  if (!code) return NULL;

  char tmp_char = '\0';
  uint16_t count = 0;
  for (size_t index = 0; index < length + 1; index++){
    if (tmp_char == text[index]){
      count++;
    }
    else {
      char buf[13]; 
      if (count > 1)
        sprintf(buf, "%d%c", count, tmp_char);
      else
        sprintf(buf, "%c", tmp_char);
      strcat(code, buf);
      tmp_char = text[index];
      count = 1;
    }
  }

  code = realloc(code, (strlen(code) + 1) * sizeof(char));

  return code;
}

char *decode(const char *data){
  assert(data);

  char * text = calloc(ENOUGH, sizeof(char));
  if(!text) return NULL;

  char *p_end = (char *)data;

  size_t text_pointer = 0;
  uint32_t count = 0;
  while (*p_end){
    if (is_digit(*p_end)){
      count = strtol(p_end, &p_end, 10);
      memset(text + text_pointer, *p_end, count);
      text_pointer += count;
    }
    else {
      text[strlen(text)] = *p_end;
      text_pointer++;
    }
    p_end++;
  }
  
  text = realloc(text, (strlen(text) + 1) * sizeof(char));

  return text;
}
