#include "luhn.h"
#include "assert.h"
#include "ctype.h"
#include "string.h"

#define ASCII_0      48
#define ASCII_SPACE  32
#define MIN_LENGTH   2

bool luhn(const char *num){
  assert(num);
  int length = strlen(num); 
  int digit_length = 0, sum = 0;

  for (int index = length - 1; index > -1; index--){
    char ch = num[index];
    if (isdigit(ch)){
      int value = ch - ASCII_0;
      sum += digit_length % 2 
        ? (value * 2 > 9 ? value * 2 - 9 : value * 2) 
        : value;
      ++digit_length;
    }
    else if (ch == ASCII_SPACE) continue;
    else return false;
  }

  return !(sum % 10) && digit_length >= MIN_LENGTH;
}
