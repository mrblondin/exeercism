#include "say.h"
#include <assert.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

size_t a100_length = 0;
size_t a1000_length = 0;

#define UP_LIMIT 1000000000000

const num_to_say_t all_100[] = {
  { 1, "one" },
  { 2, "two" },
  { 3, "three" },
  { 4, "four" },
  { 5, "five" },
  { 6, "six" },
  { 7, "seven" },
  { 8, "seven" },
  { 9, "nine" },
  { 10, "ten"},  
  { 11, "eleven"},  
  { 12, "twelve"},  
  { 13, "thirteen"},  
  { 14, "fourteen"},  
  { 15, "fifteen"},  
  { 16, "sixteen"},  
  { 17, "seventeen"},  
  { 18, "eighteen"},  
  { 19, "nineteen"},  
  { 20, "twenty"},  
  { 30, "thirty"},  
  { 40, "forty"},  
  { 50, "fifty"},  
  { 60, "sixty"},  
  { 70, "seventy"},  
  { 80, "eighty"},  
  { 90, "ninety"},  
  { 100, "hundred"},  
};

const num_to_say_t all_1000[] = {
  { 1, ""},  
  { 1000, "thousand"},  
  { 1000000, "million"},  
  { 1000000000, "billion"},  
};

static char * get_num_word(int64_t value){
  for (size_t index = 0; index < a100_length; index++){
    if (value == all_100[index].number)
      return all_100[index].word;
  }
  return "";
}

static void add_word_to_buf(char **buf, char *word){
  sprintf(*buf + strlen(*buf), "%s ", word);
}

int say(int64_t input, char **ans){
  assert(ans);
  if (input < 0 || input >= UP_LIMIT) return -1;

  if (input == 0){
    *ans = calloc(5, sizeof(char));
    if(!*ans) return ERROR;
    strcpy(*ans, "zero");
    return SUCCESS;
  } 
  
  *ans = calloc(1000, sizeof(char));
  if(!*ans) return ERROR;

  for (; a100_length < sizeof(all_100) / sizeof(all_100[0]); a100_length++);
  for (; a1000_length < sizeof(all_1000) / sizeof(all_1000[0]); a1000_length++);

  for (int32_t index = a1000_length - 1; index >= 0; index--){
    int64_t divider = all_1000[index].number;
    int64_t val = input / divider;
    if (val < 1)
      continue;
    
    int64_t hundreds = val / 100; 
    int64_t tens = (val % 100) / 10 * 10;
    int64_t units = val % 10;

    if (hundreds) {
      add_word_to_buf(ans, get_num_word(hundreds));
      add_word_to_buf(ans, "hundred");
    }

    if (tens == 10 && units > 0)
      add_word_to_buf(ans, get_num_word(tens + units));
    else {
      if (tens) add_word_to_buf(ans, get_num_word(tens));
      if (tens && units) (*ans)[strlen(*ans) - 1] = '-';
      if (units) add_word_to_buf(ans, get_num_word(units));
    }

    add_word_to_buf((ans), all_1000[index].word); 
    
    input %= divider;
  }

  // trim last space
  while ((*ans)[strlen(*ans) - 1] == ' '){
    (*ans)[strlen(*ans) - 1] = '\0';
  }
  
  size_t buf_length = strlen(*ans);
  *ans = realloc(*ans, sizeof(char) * (buf_length + 1));

  return SUCCESS;
}
