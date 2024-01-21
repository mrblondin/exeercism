#ifndef ALLERGIES_H
#define ALLERGIES_H

#include <stdbool.h>

typedef enum {
   ALLERGEN_EGGS = 0,
   ALLERGEN_PEANUTS,
   ALLERGEN_SHELLFISH,
   ALLERGEN_STRAWBERRIES,
   ALLERGEN_TOMATOES,
   ALLERGEN_CHOCOLATE,
   ALLERGEN_POLLEN,
   ALLERGEN_CATS,
   ALLERGEN_COUNT,
} allergen_t;

typedef struct {
   int count;
   bool allergens[ALLERGEN_COUNT];
} allergen_list_t;

/**
 * Check is allergen is in the score
 * @param {unsigned char} allergen
 * @param {unsigned int} score
 * returns {bool}
 */
bool is_allergic_to(unsigned char allergen, unsigned int score); 

/**
 * Get Allergen list from the score
 * @param {unsigned int} score
 * returns {allergen_list_t} a list of allergens
 */
allergen_list_t get_allergens(unsigned int score);

#endif
