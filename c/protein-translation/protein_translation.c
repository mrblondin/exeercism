#include "protein_translation.h"
#include <assert.h>
#include <string.h>

#define CODE_LENGTH 3
static code_t CODES[] = {
  {"AUG", 0}, {"UUU", 1}, {"UUC", 1}, {"UUA", 2}, {"UUG", 2}, {"UCU", 3},
  {"UCC", 3}, {"UCA", 3}, {"UCG", 3}, {"UAU", 4}, {"UAC", 4}, {"UGU", 5},
  {"UGC", 5}, {"UGG", 6}, {"UAA", -1}, {"UAG", -1}, {"UGA", -1}
};

static protein_t find_code(char * text){
  for (size_t i = 0; i < sizeof(CODES) / sizeof(code_t); i++)
    if (!strncmp(CODES[i].code, text, CODE_LENGTH)) return CODES[i].protein;
  
  return INVALID;
}

proteins_t proteins(const char *const rna){
  assert(rna);
  proteins_t proteins = {true, 0, {0}};
  
  int length = strlen(rna);
  for (int index = 0; index < length; index += CODE_LENGTH){
    char buf[CODE_LENGTH + 1]; // +1 to have '\0' 
    memcpy(buf, &rna[index], CODE_LENGTH);
    protein_t protein = find_code(buf);

    if (protein == INVALID){ proteins.valid = false; return proteins; }
    else if (protein == STOP) break;
    else {
      proteins.proteins[proteins.count] = protein;
      proteins.count += 1;
    }
  }
  return proteins;
}
