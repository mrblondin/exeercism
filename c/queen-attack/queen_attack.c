#include "queen_attack.h"
#include <stdbool.h>
#include <stdlib.h>

#define q1x queen_1.row
#define q1y queen_1.column
#define q2x queen_2.row
#define q2y queen_2.column

#define MAX_X       7
#define MIN_X       0

static int valid_position(position_t queen_1) {
  return !(q1x < MIN_X || q1y < MIN_X || q1x > MAX_X || q1y > MAX_X);
}

static bool is_on_straigt_or_diag(position_t queen_1, position_t queen_2){
  return q1x == q2x || q1y == q2y || (abs(q1x - q2x) == abs(q1y - q2y));
}

attack_status_t can_attack(position_t queen_1, position_t queen_2){
  if (q1x == q2x && q1y == q2y)
    return INVALID_POSITION;

  if (!valid_position(queen_1) || !valid_position(queen_2))
    return INVALID_POSITION;

  if (is_on_straigt_or_diag(queen_1, queen_2))
      return CAN_ATTACK;

  return CAN_NOT_ATTACK;
}
