#include "nucleotide_count.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
 
#define ERROR ""
#define NUCLEO_NUMBER 4


char *count(const char *dna_strand) {
  if (!dna_strand) return ERROR;

  int buf[NUCLEO_NUMBER][2] = {{'A', 0}, {'C', 0}, {'G', 0}, {'T', 0}};

  char *result = malloc(sizeof(char) * NUCLEO_NUMBER * (7));
  if (!result) return ERROR;

  while (*dna_strand){
    char single_dna = *dna_strand++;
    int found = 0;
    for (int i = 0; i < NUCLEO_NUMBER; i++){
      if (single_dna == buf[i][0]){
        buf[i][1]++;
        found = 1;
        break;
      }
    }

    // Wrong nucleo code, return empty result
    if (!found) return result;
  }


  for (int i = 0; i < NUCLEO_NUMBER; i++){
    char str[7];
    sprintf(str, "%c:%i%c", buf[i][0], buf[i][1], ((i + 1) / NUCLEO_NUMBER ? '\0' : ' '));

    strcat(result, str);
  }

  return result;
}
