#include <stdlib.h>

#include "../s21_matrix.h"

int s21_create_matrix(int rows, int columns, matrix_t *result) {
  if (result == NULL) {
    return INCORRECT_MATRIX;
  }

  if (rows < 1 || columns < 1) {
    return INCORRECT_MATRIX;
  }

  result->rows = rows;
  result->columns = columns;

  result->matrix = (double **)malloc(sizeof(double *) * rows);

  if (result->matrix == NULL) {
    return INCORRECT_MATRIX;
  }

  for (int i = 0; i < rows; i++) {
    result->matrix[i] = (double *)malloc(sizeof(double) * columns);

    if (result->matrix[i] == NULL) {
      s21_remove_matrix(result);
      return INCORRECT_MATRIX;
    }

    for (int j = 0; j < columns; j++) {
      result->matrix[i][j] = 0.0;
    }
  }

  return OK;
}
