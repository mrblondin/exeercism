#include "two_bucket.h"
#include <assert.h>

/**
  * There are not so many varieties of the sequence with 2 buckets.
  * The starting (1) bucket is filled, then poured into the other (2) bucket,
  * then if there is still water in the starting bucket -> empty the other bucket,
  * otherwise fill the starting bucket and repeat -> pour into the other bucket.
  * After few iterations the goal will be either achieved or the state of
  * buckets water volume will be repeated, what no solution.
  */

int steps;

static bool check_goal(bucket_t * bucket1, bucket_t * bucket2, 
                       bucket_liters_t goal) {
  return bucket1->filled == goal || bucket2->filled == goal;
}

static void empty(bucket_t * bucket){ bucket->filled = 0; steps++; }

static void fill(bucket_t * bucket){ bucket->filled = bucket->size; steps++; }

static void divert(bucket_t * bucket_from, bucket_t * bucket_to){
  if (bucket_from->filled > bucket_to->size - bucket_to->filled){
    bucket_from->filled -= (bucket_to->size - bucket_to->filled);
    bucket_to->filled = bucket_to->size;
  }
  else{
    bucket_to->filled += bucket_from->filled;
    bucket_from->filled = 0;
  }
  steps++;
}

bucket_result_t measure(bucket_liters_t bucket_1_size,
                        bucket_liters_t bucket_2_size,
                        bucket_liters_t goal_volume, bucket_id_t start_bucket){
  assert(bucket_1_size && bucket_2_size && goal_volume && 
         start_bucket >= BUCKET_ID_1 && start_bucket <= BUCKET_ID_2);

  bucket_result_t result = {false, 0, 0, 0};

  bucket_t bucket1 = 
    start_bucket == BUCKET_ID_1 ? 
    (bucket_t){ bucket_1_size, 0, BUCKET_ID_1 } :
    (bucket_t){ bucket_2_size, 0, BUCKET_ID_2 };

  bucket_t bucket2 = 
    start_bucket == BUCKET_ID_1 ? 
    (bucket_t){ bucket_2_size, 0, BUCKET_ID_2 }:
    (bucket_t){ bucket_1_size, 0, BUCKET_ID_1 };

  steps = 0;
  while (true){
    // check if repeated, bucket 2 is filled although bucket1 is empty
    if (bucket2.filled == bucket2.size && !bucket1.filled) 
      return (bucket_result_t){false};

    if (bucket1.filled)
      empty(&bucket2);
    else{
      fill(&bucket1);
      //edge case bucket2 size = goal_size
      if (bucket2.size == goal_volume) fill(&bucket2);
      if (check_goal(&bucket1, &bucket2, goal_volume)) break;
    }

    divert(&bucket1, &bucket2);
    if (check_goal(&bucket1, &bucket2, goal_volume)) break;
  }

  result.possible = true;
  result.move_count = steps; 
  
  if (bucket1.filled == goal_volume) {
    result.goal_bucket = bucket1.id;
    result.other_bucket_liters = bucket2.filled;
  }
  else {
    result.goal_bucket = bucket2.id; 
    result.other_bucket_liters = bucket1.filled;
  }

  return result;
}
