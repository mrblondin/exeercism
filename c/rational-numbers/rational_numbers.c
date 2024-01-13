#include "rational_numbers.h"
#include <math.h>

#define A     number.numerator
#define B     number.denominator
#define A1    number1.numerator
#define B1    number1.denominator
#define A2    number2.numerator
#define B2    number2.denominator

#define ZERO  (rational_t) {0, 1}
#define FALSE (rational_t) {0, 0}


/**
 * Absolute value calculation
 * @param {int} number
 * @returns {int} result
 */
static int abs(int number){
  return (number < 0 ? number * -1 : number);
}

rational_t add(rational_t number1, rational_t number2){
  if (!B1 || !B2)
    return FALSE;

  rational_t sum = {
    A1 * B2 + A2 * B1,
    B1 * B2
  };

  return reduce(sum);
}

rational_t subtract(rational_t number1, rational_t number2){
  if (!B1 || !B2)
    return FALSE;

  rational_t subtract = {
    A1 * B2 - A2 * B1,
    B1 * B2
  };

  return reduce(subtract);
}

rational_t multiply(rational_t number1, rational_t number2){
  if (!B1 || !B2)
    return FALSE;

  rational_t multiply = {
    A1 * A2,
    B1 * B2
  };

  return reduce(multiply);
}

rational_t divide(rational_t number1, rational_t number2){
  if (!B1 || !B2 || !A2)
    return FALSE;

  rational_t division = {
    A1 * B2,
    A2 * B1
  };

  return reduce(division);
}

rational_t absolute(rational_t number){
  if (!B)
    return FALSE;

  rational_t absValue = { abs(A), abs(B) };

  return reduce(absValue);
}

rational_t exp_rational(rational_t number, short n){
  if (!B)
    return FALSE;

  rational_t exp = { 0, 0 };

  if (n > 0){
    exp.numerator = pow(A, n);
    exp.denominator = pow(B, n);
  }
  else {
    exp.numerator = pow(B, abs(n));
    exp.denominator = pow(A, abs(n));
  }

  return reduce(exp);
}

float exp_real(short n, rational_t number){
  if (!B)
    return 0;

  float exp = (float) pow(pow(n, A), (1.0 / B));

  return exp;
}

rational_t reduce(rational_t number){
  if (A == 0) return (rational_t) {0, 1};

  // check if division if negative
  if (B < 0){
    A *= -1;
    B *= -1;
  }

  int min = abs(A > B ? B : A);

  for (int i = 2; i <= min; i++){
    if (A % i == 0 && B % i == 0){
      A = A / i;
      B = B / i;
      number = reduce(number);
      break;
    }
  }

  return number;
}
