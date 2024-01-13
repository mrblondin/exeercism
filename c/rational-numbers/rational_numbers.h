#ifndef RATIONAL_NUMBERS_H
#define RATIONAL_NUMBERS_H

typedef struct {
  int numerator;
  int denominator;
} rational_t;

/**
 * Sum of two rational numbers
 *
 * @param {rational_t} first number
 * @param {rational_t} second number
 * @returns {rational_t} result
 */
rational_t add(rational_t number1, rational_t number2);

/**
 * Subtraction of two rational numbers
 */
rational_t subtract(rational_t number1, rational_t number2);

/**
 * Multiplying of two rational numbers
 */
rational_t multiply(rational_t number1, rational_t number2);

/**
 * Division of two rational numbers
 */
rational_t divide(rational_t number1, rational_t number2);

/**
 * Absolute value of rational number
 */
rational_t absolute(rational_t number);

/**
 * Exponentiation of rational number to a non-negative integer power
 */
rational_t exp_rational(rational_t number, short n);

/**
 * Exponentiation of rational number to a negative integer power
 */
float exp_real(short n, rational_t number);

/**
 * Redutcion of rational number to lowest terms
 */
rational_t reduce(rational_t number);

#endif
