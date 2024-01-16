#include "saddle_points.h"

#define ERROR 0

saddle_points_t * saddle_points(size_t rows, size_t columns, uint8_t matrix[rows][columns]){

  // allocate maximum possible memory according to matrix dimensions
  saddle_points_t * points = malloc(
    sizeof(*points) + rows*columns*sizeof(saddle_point_t));

  if (!points) return ERROR;

  points->count = 0;

  for (size_t i = 0; i < rows; i++){

    uint8_t maxInRow = 0;
    uint8_t countInRow = 0;

    for(size_t j = 0; j < columns; j++){
      if (matrix[i][j] >= maxInRow) {
        // this is the candidate

        // if new candidate in a row, we need refresh counters
        if (matrix[i][j] > maxInRow) {
          maxInRow = matrix[i][j];
          points->count -= countInRow;
          countInRow = 0;
        }

        // check if the candidate matches the condition in columns
        int success = 1;
        for(size_t k = 0; k < rows; k++){
          if (matrix[i][j] > matrix[k][j]){
            success = 0;
            break;
          }
        }

        if (success){
          points->points[points->count++] = (saddle_point_t){i+1,j+1};
          countInRow = maxInRow == matrix[i][j] ?  countInRow + 1  : 1;
        }
      } 
    } 
  }

  points = realloc(points, sizeof(*points) + points->count*sizeof(saddle_point_t));
  return points;
}

void free_saddle_points(saddle_points_t * points) {
  if (!points) return;

  free(points);
}

