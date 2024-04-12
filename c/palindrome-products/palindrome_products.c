#include "palindrome_products.h"
#include <assert.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

static void validate_palindrome(product_t * product, int from, int to){
  if (to < from)
    sprintf(product->error, "invalid input: min is %i and max is %i", from, to);
  else if (!product->factors_lg && !product->factors_sm) 
    sprintf(product->error, "no palindrome with factors in the range %i to %i", from, to);
}

static bool is_palindome(int num){
  if (num % 10 == 0) return false;
  int reversed = 0;
  while (num > reversed){
    reversed = reversed * 10 + num % 10;
    num /= 10;
  }

  return reversed == num || num == reversed / 10;
}

static void free_factors(factor_t *factor){
  if (factor->next)
    free_factors(factor->next);
  free(factor);
}

product_t *get_palindrome_product(int from, int to){
  assert(from && to);
  factor_t * cur_factor = NULL;
  product_t * product = calloc(1, sizeof(product_t));
  if (!product) return product;

  product->smallest = to * to;

  // smallest
  for (int num1 = from; num1 <= to; ++num1){
    for (int num2 = num1; num2 <= to && (num2 * num1 <= product->smallest); ++num2){
      int mult = num1 * num2;
      if (!is_palindome(mult) || mult > product->smallest)
        continue;

      factor_t * new_factor = calloc(1, sizeof(factor_t));
      new_factor->factor_a = num1; new_factor->factor_b = num2;

      if (mult < product->smallest) {
        if (product->factors_sm) free_factors(product->factors_sm);
        product->smallest = mult;
        product->factors_sm = new_factor;
        cur_factor = product->factors_sm;
      }
      else if (mult == product->smallest){
        cur_factor->next = new_factor;
        cur_factor = cur_factor->next;
      };
    }
  }

  // largest
  for (int num1 = to; num1 >= from; --num1){
    for (int num2 = num1; num2 >= from && (num2 * num1 >= product->largest); --num2){
      int mult = num1 * num2;
      if (!is_palindome(mult) || mult < product->largest)
        continue;

      factor_t * new_factor = calloc(1, sizeof(factor_t));
      new_factor->factor_a = num1; new_factor->factor_b = num2;

      if (mult > product->largest) {
        if (product->factors_lg) free_factors(product->factors_lg);
        product->largest = mult;
        product->factors_lg = new_factor;
        cur_factor = product->factors_lg;
      }
      else if (mult == product->largest){
        cur_factor->next = new_factor;
        cur_factor = cur_factor->next;
      }
    }
  }

  validate_palindrome(product, from, to);

  return product;
}


void free_product(product_t *p){
  free(p->factors_sm);
  free(p->factors_lg);

  free(p);
}
