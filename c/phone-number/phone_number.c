#include "phone_number.h"
#include <stdlib.h>
#include <string.h>

#define ERROR           "0000000000"
#define NUM_LENGTH      10

#define ASCII_NUMBER_0  48
#define ASCII_NUMBER_1  49
#define ASCII_NUMBER_9  57

#define AREA_CODE_START     0
#define EXCHANGE_CODE_START 3

char *phone_number_clean(const char *input){
  if (!input) return ERROR;

  char * phoneNum = malloc((NUM_LENGTH + 1) * sizeof(char *));
  if (!phoneNum) return ERROR;

  size_t i = 0;

  while (*input){
    // check if the char is digit
    if (*input >= ASCII_NUMBER_0 && *input <= ASCII_NUMBER_9){
      if ((i == AREA_CODE_START || i == EXCHANGE_CODE_START) 
        && *input <= ASCII_NUMBER_1){
        //the first and fourth digit is 0 or 1, do nothing
      }
      else {
        phoneNum[i] = *input; 
        i++;
      }
    }
    input++;
  }

  if (i != NUM_LENGTH) strcpy(phoneNum, ERROR);

  phoneNum[NUM_LENGTH] = '\0';

  return phoneNum;
}
