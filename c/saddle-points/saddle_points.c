#include "saddle_points.h"

#define ERROR 0

saddle_points_t * saddle_points(size_t rows, size_t columns, uint8_t matrix[rows][columns]){
    // allocate maximum possible memory according to matrix dimensions
    saddle_points_t * points = malloc(
    sizeof(*points) + rows*columns*sizeof(saddle_point_t));

    if (!points) return ERROR;

    points->count = 0;

    uint8_t max_row_values[rows];
    memset(max_row_values, 0, sizeof(max_row_values));

    // calculate max values in rows
    for (size_t row = 0; row < rows; ++row){
        for (size_t col = 0; col < columns; ++col){
            max_row_values[row] = matrix[row][col] > max_row_values[row] ?
                matrix[row][col] : max_row_values[row];
        } 
    }


    // find min values in columns and compare it with max_row_values
    for (size_t col = 0; col < columns; ++col){
        uint8_t min_col_value = -1;

        for (size_t row = 0; row < rows; ++row){
            uint8_t cur_val = matrix[row][col];
            if (cur_val > min_col_value) continue;
            min_col_value = cur_val;
        }

        for (size_t row = 0; row < rows; ++row){
            uint8_t cur_val = matrix[row][col];
            if (cur_val == min_col_value && cur_val == max_row_values[row])
                points->points[points->count++] = (saddle_point_t){row + 1, col + 1};
        }
    }

    points = realloc(points, sizeof(*points) + points->count*sizeof(saddle_point_t));
    return points;
}

void free_saddle_points(saddle_points_t * points) {
    free(points);
}
