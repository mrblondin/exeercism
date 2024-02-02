#include "pig_latin.h"
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define SUFFIX "ay"
#define XR "xr"
#define YT "yt"

// decare Vowel letters as first letters, all the others are Consonat.
static const char VOWELS[] = "aeiouy";

static int find_vowel_position(char * word, size_t word_length){
  int vowel_position = -1;

  // edge cases
  if (!strncmp(word, XR, 2) || !strncmp(word, YT, 2)){
    vowel_position = 0;
    return vowel_position;
  }

  for (size_t i = 0; i < word_length; i++){
    for (size_t j = 0; j < sizeof(VOWELS) / sizeof(char); j++){
      // special treatment for 'y' as first letter
      if (!i && VOWELS[j] == 'y')
        continue;

      if (word[i] == VOWELS[j]){
        vowel_position = i;

        // special treatment for 'qu'
        if (word[i] == 'u' && word[i - 1] == 'q')
          vowel_position++;

        return vowel_position;
      }
    }

    if (vowel_position > - 1) break;
  }

  return vowel_position;
}

static void apply_rules(char * word, char * translation){
  size_t word_length = strlen(word);

  int vowel_position = find_vowel_position(word, word_length);

  char buf[word_length + 1];
  strncpy(buf, word + vowel_position, word_length - vowel_position);
  strncpy(buf + word_length - vowel_position, word, vowel_position);
  buf[word_length] = '\0';
  strcat(translation, buf);
  strcat(translation, SUFFIX);
}

char *translate(const char *phrase){
  assert(phrase);

  // max length is phrase * 3 (1 letter + 'ay')
  int max_length = strlen(phrase) * 3 + 1;
  char * translation = calloc(sizeof(char), max_length);
  
  char phrase_copy[strlen(phrase) + 1];
  strcpy(phrase_copy, phrase);

  char * token = strtok(phrase_copy, " ");

  while ( token != NULL){
    if (strlen(translation)) strcat(translation, " ");

    apply_rules(token, translation);

    token = strtok(NULL, " ");
  }

  return translation;
}
