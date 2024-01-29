#include "high_scores.h"
#include <assert.h>

#define ERROR 0
#define TOP_SIZE   3

int32_t latest(const int32_t *scores, size_t scores_len){
  assert(scores && scores_len > 0);
  return scores[scores_len - 1];
}

int32_t personal_best(const int32_t *scores, size_t scores_len){
  assert(scores && scores_len > 0);

  int32_t best_result = 0;

  for (size_t index = 0; index < scores_len; index++)
    best_result = scores[index] > best_result ? scores[index] : best_result;
  
  return best_result;
}

size_t personal_top_three(const int32_t *scores, size_t scores_len,
                          int32_t *output){
  assert(scores && scores_len > 0);

  // instead of sorting, iterate n+3n times, O(n+3n) complexity
  for (size_t s_index = 0; s_index < scores_len; s_index++){
    int32_t next = -1;
    for (size_t o_index = 0; o_index < TOP_SIZE; o_index++){
      if (next >= 0) {
        if (next > output[o_index]){
          int32_t temp = output[o_index];
          output[o_index] = next;
          next = temp;
        }
      }
      else if (scores[s_index] > output[o_index]){
        next = output[o_index]; 
        output[o_index] = scores[s_index];
      }
    }
  }


  return scores_len > TOP_SIZE ? TOP_SIZE : scores_len;
}
