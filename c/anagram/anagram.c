#include "anagram.h"
#include <assert.h>
#include <string.h>
#include <strings.h>

#define ALPHABET_COUNT 26

static char to_lower(char c) {
  return c = c > 0x40 && c < 0x5b ? c | 0x60 : c;
}

static enum anagram_status is_anagram(const char *subject, const char *word){
  if (strlen(subject) != strlen(word) || !strcasecmp(subject, word))
    return NOT_ANAGRAM;

  int occurencies[ALPHABET_COUNT];
  memset(occurencies, 0, sizeof(int) * ALPHABET_COUNT);

  while (*word) {
    occurencies[to_lower(*word++) - 'a']++;
    occurencies[to_lower(*subject++) - 'a']--;
  }

  for (size_t index = 0; index < ALPHABET_COUNT; index++){
    if (occurencies[index] != 0)
      return NOT_ANAGRAM;
  }

  return IS_ANAGRAM;
}

void find_anagrams(const char *subject, struct candidates *candidates){
  assert(subject && candidates);

  for (size_t index = 0; index < candidates->count; index++){
    candidates->candidate[index].is_anagram = 
      is_anagram(subject, candidates->candidate[index].word); 
  } 
}
