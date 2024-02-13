#include "binary_search.h"

const int *binary_search(int value, const int *arr, size_t length){
  if (!arr || !length) return ERROR; 

  // min and max index of the range to look for
  size_t min = 0, max = length;

  // Current position index
  size_t mid = (max - min) >> 1;
  
  while (min < max) {
    mid = min + ((max - min) >> 1);

    if (arr[mid] == value) return &arr[mid];

    if (value < arr[mid]){
      max = mid;
    }
    else{
      min = mid + 1;
    }
  }

  return ERROR;
}
