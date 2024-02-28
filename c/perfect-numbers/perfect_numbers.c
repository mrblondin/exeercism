#include "perfect_numbers.h"

kind classify_number(int number){
  if (number < 1) return ERROR;
  int sum = 0;
  
  for (int i = 1; i <= number / 2; i++)
    sum = number % i ? sum : sum + i;
  
  return sum == number ? PERFECT_NUMBER 
                       : (sum > number ? ABUNDANT_NUMBER : DEFICIENT_NUMBER);
}
