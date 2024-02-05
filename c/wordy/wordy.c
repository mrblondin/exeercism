#include "wordy.h"
#include <assert.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define START "What is "
#define BY "by "

static int plus(int x, int y) {return x + y;}
static int minus(int x, int y) {return x - y;}
static int multiply(int x, int y) {return x * y;}
static int divide(int x, int y) {return x / y;}

typedef struct{
  char *word;
  int (*operation)(int, int );
} operation_t;

static operation_t OPS[] = {
  {"plus", plus},
  {"minus", minus},
  {"multiplied", multiply},
  {"divided", divide},

};

/**
* Replace substring in text with new string
* param {const char *} text - text to process
* param {const char **} substrings - array of strings to be found and 
* replaced in text
* param {const char *} new_substr - string to be inserted in text
* param {int} n - amount of substrings
* return {char *} - new text, this variable should be freed and pointer set 
* to NULL after use
*/
static char *replace(const char *text, const char **substrings, 
                     const char *new_substr, int n){
  char * result = calloc(strlen(text), sizeof(char));
  char * p;
  strcpy(result, text);

  for (int i = 0; i < n; i++){
    const char *substring = substrings[i];
    while ((p = strstr(result, substring))){
      int position = p - result;
      int length = strlen(result);
      int new_length = length + strlen(new_substr) - strlen(substring);
      char buf[new_length];

      strncpy(buf, result, position);
      strncpy(buf + position, new_substr, strlen(new_substr));
      strncpy(buf + position + strlen(new_substr), result + position + 
              strlen(substring), length - position - strlen(substring));

      buf[new_length] = '\0';

      result = realloc(result, new_length * sizeof(char));
      strcpy(result, buf);
    }
  }

  return result;
}

bool answer(const char *question, int *result){
  assert(question && result);

  int length = strlen(question);

  *result = 0;

  // check if string starts with "What is" and ends with "?"
  if (strstr(question, START) != question || question[length - 1] != '?')
    return false;

  const char *substrings[3] = {START, BY, "?"};
  char * q = replace(question, substrings, " ", 3);

  char * token = strtok(q, " ");

  // first element is always number 
  if (!token) { free(q); return false; };
  *result = (int) strtol(token, NULL, 10);
  token = strtok(NULL, " ");

  // iterate over other entries
  while (token){
    int (*action)(int, int ) = NULL;
    for (size_t i = 0; i < sizeof(OPS) / sizeof(operation_t); i++){
      if (!strcmp(OPS[i].word, token)){
        action = OPS[i].operation;
      }
    }
    if (!action) { free(q); return false; };

    token = strtok(NULL, " ");
    if (!token) { free(q); return false; };
    int y = (int) strtol(token, NULL, 10);
    *result = action(*result, y);
    token = strtok(NULL, " ");
  }

  free(q);
  return true;
}
