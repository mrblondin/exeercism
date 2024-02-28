#include "triangle.h"

static bool is_valid(triangle_t s){
  return s.a && s.b && s.c && (s.a + s.b >= s.c) && (s.a + s.c >= s.b) 
         && (s.b + s.c >= s.a);
}

bool is_equilateral(triangle_t sides){
  return is_valid(sides) && (sides.a == sides.b) && (sides.a == sides.c);
}

bool is_isosceles(triangle_t sides){
  return is_valid(sides) && ((sides.a == sides.b) || (sides.a == sides.c) 
                             || (sides.b == sides.c));
}

bool is_scalene(triangle_t sides){
  return is_valid(sides) && !is_isosceles(sides);
}
