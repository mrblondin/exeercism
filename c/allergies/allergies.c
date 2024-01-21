#include "allergies.h"
#include <stdio.h>

bool is_allergic_to(unsigned char allergen, unsigned int score){
  return score & 1U << allergen;
}

allergen_list_t get_allergens(unsigned int score){
  allergen_list_t alList;
  alList.count = 0;

  for (int i = ALLERGEN_COUNT - 1; i >=0; i--) {
    alList.allergens[i] = is_allergic_to(i, score);    
    if (alList.allergens[i]) alList.count++;
  }

  return alList; 
}
