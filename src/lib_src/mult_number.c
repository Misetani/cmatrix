#include <stdlib.h>

#include "../s21_matrix.h"

int s21_mult_number(matrix_t *A, double number, matrix_t *result) {
  if (A == NULL || result == NULL) {
    return INCORRECT_MATRIX;
  }

  if (A->rows <= 0 || A->columns <= 0) {
    return INCORRECT_MATRIX;
  }

  if (s21_create_matrix(A->rows, A->columns, result) == INCORRECT_MATRIX) {
    return INCORRECT_MATRIX;
  }

  for (int i = 0; i < A->rows; ++i) {
    for (int j = 0; j < A->columns; ++j) {
      result->matrix[i][j] = number * A->matrix[i][j];
    }
  }

  return OK;
}