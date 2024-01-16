#ifndef SADDLE_POINTS_H
#define SADDLE_POINTS_H
#include <stdlib.h>
#include <stdint.h>

typedef struct {
  uint8_t row;
  uint8_t column;
} saddle_point_t;

typedef struct {
  size_t count;
  saddle_point_t points[];
} saddle_points_t;

/**
 * Find the appropriate coordinates, minimum in a row and max in a column
 * @param (size_t) rows, number of rows in matrix
 * @param (size_t) columns, number of columns in matrix
 * @param (uint8_t[]) matrix, array filled with numbers
 * returns (saddle_points_t *) suitable coordinates
 */
saddle_points_t * saddle_points(size_t rows, size_t columns, uint8_t matrix[rows][columns]);

/**
 * Release saddle points value from the memory
 * @param (saddle_points_t) points to free
 * returns (void)
 */
void free_saddle_points(saddle_points_t * points);

#endif
