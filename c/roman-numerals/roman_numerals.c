#include "roman_numerals.h"
#include <assert.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 20

static roman_form_t roman_form[] = {
  {3000, "MMM"}, {2000, "MM"}, {1000, "M"},
  {900, "CM"}, {800, "DCCC"}, {700, "DCC"}, {600, "DC"}, {500, "D"},
    {400, "CD"}, {300, "CCC"}, {200, "CC"}, {100, "C"},
  {90, "XC"}, {80, "LXXX"}, {70, "LXX"}, {60, "LX"}, {50, "L"},
    {40, "XL"}, {30, "XXX"}, {20, "XX"}, {10, "X"},
  {9, "IX"}, {8, "VIII"}, {7, "VII"}, {6, "VI"}, {5, "V"},
    {4, "IV"}, {3, "III"}, {2, "II"}, {1, "I"}
};

#define FORM_SIZE (sizeof(roman_form) / sizeof(roman_form_t))

char *to_roman_numeral(unsigned int number) {
  assert(number);

  char *output = calloc(MAX_LENGTH, sizeof(char));

  for (size_t i = 0; i < FORM_SIZE; i++){
    if (number / roman_form[i].decimal == 1){
      number %= roman_form[i].decimal;
      strcat(output, roman_form[i].roman);
    }
  }

  return output;
}
