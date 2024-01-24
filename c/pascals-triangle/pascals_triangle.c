#include "pascals_triangle.h"

#include <stdlib.h>
#include <string.h>

#define ERROR 0
#define MIN_SIZE(x) (x < 1 ? 1 : x)

void free_triangle(uint8_t **triangle, size_t rows){
  for (size_t row = 0; row < MIN_SIZE(rows); row++){
    free(triangle[row]);
    triangle[row] = NULL;
  }
  free(triangle);
  triangle = NULL;
}

uint8_t **create_triangle(size_t rows){
  uint8_t **triangle;
  triangle = (uint8_t **) malloc(MIN_SIZE(rows) * sizeof(uint8_t*));
  if (!triangle) return ERROR;

  // init 1st row, rows = columns
  triangle[0] = (uint8_t *) malloc(MIN_SIZE(rows) * sizeof(uint8_t));
  if (!triangle[0]) return ERROR;
  triangle[0][0] = rows < 1 ? 0 : 1;

  for (size_t row = 1; row < rows; row++){
    triangle[row] = (uint8_t *)malloc(rows * sizeof(uint8_t));
    if (!triangle[row]) return ERROR;

    for (size_t column = 0; column <= row; column++){
      triangle[row][column] =  triangle[row - 1][column] + 
        (column > 0 ? triangle[row-1][column - 1] : 0);
    }
  }

  return triangle;
}

