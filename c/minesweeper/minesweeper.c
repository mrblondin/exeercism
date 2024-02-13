#include "minesweeper.h"
#include <assert.h>
#include <stdlib.h>
#include <string.h>

#define MINE '*'
#define EMPTY ' '

// need rows for free() memory, the tests assume that we free each annotation before 
// creating a new one
size_t rows_to_free = 0;

static void mark_field(char *field){
  if (*field == MINE) return;
  if (*field == EMPTY){ *field = '1'; return; }
  *field += 1;
}

static void mark_mine(char ** annotation, size_t row, size_t col, size_t rows,
                      size_t columns){
  // iterate +1 all the values around mine; check the borders from sides  
  if (row > 0) mark_field(&annotation[row - 1][col]);
  if (row < rows) mark_field(&annotation[row + 1][col]);

  if (col > 0) mark_field(&annotation[row][col - 1]);
  if (col < columns) mark_field(&annotation[row][col + 1]);

  if (row > 0 && col > 0) mark_field(&annotation[row - 1][col - 1]);
  if (row < rows && col < columns) mark_field(&annotation[row + 1][col + 1]);

  if (row > 0 && col < columns) mark_field(&annotation[row - 1][col + 1]);
  if (row < rows && col > 0) mark_field(&annotation[row + 1][col - 1]);
}

char **annotate(const char **minefield, const size_t rows){
  if (rows == 0) return NULL;
  char ** annotation = calloc(rows, sizeof(char *));
  if (!annotation) return NULL;
  size_t columns = strlen(minefield[0]);
  rows_to_free = rows;

  // copy board to annotation
  for (size_t i = 0; i < rows; i++){
    annotation[i] = calloc(columns + 1, sizeof(char));
    if (!annotation) return NULL;
    strncpy(annotation[i], minefield[i], columns);
  }

  for (size_t row = 0; row < rows; row++){
    for (size_t col = 0; col < columns; col++){
      if (annotation[row][col] == MINE)
        mark_mine(annotation, row, col, rows - 1, columns - 1);
    } 
  }
  return annotation;
}

void free_annotation(char **annotation){
  assert(annotation);
  for (size_t i = 0; i < rows_to_free; i++)
    free(annotation[i]);

  free(annotation);
}
