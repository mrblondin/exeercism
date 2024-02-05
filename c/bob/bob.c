#include "bob.h"
#include <assert.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

#define ASCII_LOW_LETTERS_START   97
#define ASCII_LOW_LETTERS_FINISH  122
#define ASCII_UP_LETTERS_START    65
#define ASCII_UP_LETTERS_FINISH   90
#define ERROR                     ""

typedef struct {
  bool (*is_something)(char *);
  char * answer;
} greeting_t;

// trimming string from right
static void rtrim(char *s){
  char *back = s + strlen(s);
  while(isspace(*--back)) {};
  *(back+1) = '\0';
}

static bool is_shouting(char *text){
  // check ASCII code of characters, the codes between 97 and 122
  // also check that there is at least UpperCase letter
  bool is_letter = false;
  while (*text){
    if (*text >= ASCII_LOW_LETTERS_START && *text <= ASCII_LOW_LETTERS_FINISH)
      return false; // low case letter
    if (!is_letter 
      && *text >=ASCII_UP_LETTERS_START && *text <= ASCII_UP_LETTERS_FINISH)
      is_letter = true; // upper case letter
    text++;
  }
  return is_letter;
}

static bool is_silent(char *text){ return !strcmp(text, "") ? true : false; }

static bool is_question(char *text) { return text[strlen(text) - 1] == '?' ? true : false; }

static bool is_shouting_question(char *text){ return is_shouting(text) && is_question(text); }

static bool is_smth_else(char *text) { assert(text); return true; }

greeting_t greetings[] = {
  {is_silent,             "Fine. Be that way!"},
  {is_shouting_question,  "Calm down, I know what I'm doing!"},
  {is_shouting,           "Whoa, chill out!"},
  {is_question,           "Sure."},
  {is_smth_else,          "Whatever."},
};

char *hey_bob(char *greeting){
  assert(greeting);

  char *text = calloc(strlen(greeting), sizeof(char));
  strcpy(text, greeting);
  rtrim(text);

  for (size_t i = 0; i < (sizeof(greetings) / sizeof(greeting_t)); i++)
    if (greetings[i].is_something(text)) return greetings[i].answer;

  return ERROR;
}
