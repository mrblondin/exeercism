#include "rna_transcription.h"
#include <assert.h>
#include <string.h>
#include <stdlib.h>

#define NUCLEO_NUM 4
#define ERROR NULL
static const char DNA[NUCLEO_NUM] = "GCTA";
static const char RNA[NUCLEO_NUM] = "CGAU";

// another better variant of matchmaking
//static const char lookup[] = {['A'] = 'A', ['B'] = 'B'}

char *to_rna(const char *dna){
  assert(dna);

  int length = strlen(dna) + 1;

  char * rna_result = calloc(length, sizeof(char));
  if (!rna_result) return ERROR;

  int index = 0;

  while (*dna){

    for (int i = 0; i < NUCLEO_NUM; i++){
      if (DNA[i] == *dna){
        rna_result[index] = RNA[i];
        break;
      }
    }

    if (!rna_result[index]){
      free(rna_result);
      return ERROR;
    }

    dna++;
    index++;
  }

  rna_result[length] = '\0';
  return rna_result;
}
